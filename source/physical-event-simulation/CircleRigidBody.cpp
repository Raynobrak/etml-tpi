#include "CircleRigidBody.h"
#include "utils.h"

constexpr unsigned OBJECTS_TRACE_HISTORY_LENGTH = 20u;
constexpr float OBJECTS_TIME_BETWEEN_TRACE_SAVE = 0.02f;

CircleRigidBody::CircleRigidBody(ch::Circle circle, float mass, ch::vec_t initialVelocity) : 
	circle_(circle), 
	mass_(mass), 
	vel_(initialVelocity), 
	timeSinceLastTraceSave_(0.f),
	massLabel_(ch::collision::enclosingAABB(circle), TINY_TEXT, utils::float_to_fixed_string(mass))
{
	massLabel_.setTextColor(color_palette::DARK_TEXT);

	shape_.setRadius(circle_.radius);
	shape_.setOrigin(circle_.radius, circle_.radius);
	shape_.setPosition(circle_.pos);
	shape_.setFillColor(color_palette::LIGHT_FOREGROUND);
	shape_.setOutlineThickness(1.f);
	shape_.setOutlineColor(sf::Color::Black);
}

void CircleRigidBody::collideWithWalls(ch::AABB enclosingWalls) {
	auto circleAABB = ch::collision::enclosingAABB(circle_);
	if (!ch::collision::aabb_contains(enclosingWalls, circleAABB)) {
		auto collision = ch::collision::aabb_collision_info(enclosingWalls, circleAABB);

		auto direction = -collision.normal;
		float distance = circle_.diameter() - collision.absolutePenetrationDepthAlongNormal();

		move(distance * direction);
		accelerate(ch::vec_dot_product(vel_, collision.normal) * direction * 2.f);
	}
}

void CircleRigidBody::accelerate(ch::vec_t acceleration) {
	vel_ += acceleration;
}

void CircleRigidBody::move(ch::vec_t translationVector) {
	circle_.pos += translationVector;
}

void CircleRigidBody::update(float dt) {
	move(dt * vel_);

	timeSinceLastTraceSave_ += dt;
	if (timeSinceLastTraceSave_ > OBJECTS_TIME_BETWEEN_TRACE_SAVE) {
		timeSinceLastTraceSave_ = 0.f;
		savePosition();
	}

	massLabel_.setPosition(ch::collision::enclosingAABB(circle_).pos);
	shape_.setPosition(circle_.pos);
}

void CircleRigidBody::collideWith(CircleRigidBody& other) {
	// D�tection de la collision
	ch::CirclesCollision coll = ch::collision::circles_collision_info(circle_, other.circle_);

	// Si il n'y a pas de collision, on ne va pas plus loin.
	if (coll.normal == ch::NULL_VEC)
		return;

	// Calcul du vecteur de mouvement
	ch::vec_t movement = coll.normal * coll.absoluteDepth / 2.f;

	// Application du d�placement aux deux projectiles
	move(-movement);
	other.move(movement);

	// Calcul du vecteur d'impulsion
	float j = ch::vec_dot_product(2.f * coll.normal, vel_ - other.vel_) / (inverseMass() + other.inverseMass());
	ch::vec_t impulse = coll.normal * j;

	// Application de l'impulsion aux deux projectiles
	accelerate(-impulse / mass_);
	other.accelerate(impulse / other.mass_);
}

ch::Circle CircleRigidBody::getCircle() const {
	return circle_;
}

float CircleRigidBody::computeKineticEnergy() const {
	auto vel = ch::vec_magnitude(vel_);
	return mass_ / 2.f * vel * vel;
}

float CircleRigidBody::getMass() const {
	return mass_;
}

ch::vec_t CircleRigidBody::getVelocity() const {
	return vel_;
}

float CircleRigidBody::inverseMass() const {
	return 1.f / mass_;
}

void CircleRigidBody::savePosition() {
	trace_.push_back(circle_.pos); // Ajout de la position actuelle � l'arri�re de la file d'attente

	if (trace_.size() > OBJECTS_TRACE_HISTORY_LENGTH) { // Si la file d'attente d�passe sa taille max...
		trace_.pop_front(); // On enl�ve la position � l'avant de la file d'attente
	}
}

void CircleRigidBody::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Color outline = color_palette::LIGHT_FOREGROUND;
	outline.r = 255;
	outline.a = 0;
	float radius = 0;
	for (const auto& pos : trace_) {
		sf::CircleShape shape(radius);
		shape.setOrigin(radius, radius);
		shape.setPosition(pos);
		shape.setFillColor(outline);
		shape.setOutlineThickness(1.f);
		shape.setOutlineColor(outline);
		target.draw(shape);
		outline.a += (255 / OBJECTS_TRACE_HISTORY_LENGTH);
		radius += (circle_.radius / OBJECTS_TRACE_HISTORY_LENGTH);
	}

	target.draw(shape_);
	target.draw(massLabel_);
}
