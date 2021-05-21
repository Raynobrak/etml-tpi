#pragma once

#include <SFML/Graphics.hpp>
#include <charbrary.h>
#include "constants.h"
#include "color_palette.h"
#include <deque>
#include "Label.h"

// Repr�sente un corps rigide circulaire � deux dimensions.
// Un corps rigide est simplement un corps physique ne pouvant pas se d�former.
// Cette classe est utilis�e par les deux simulations pour repr�senter les projectiles.
// H�rite de sf::Drawable pour pouvoir �tre affich� sur une fen�tre SFML.
class CircleRigidBody : public sf::Drawable {
public:
	// Construit un projectile � partir d'un cercle (sa hitbox), d'une masse et d'une vitesse initiale.
	CircleRigidBody(ch::Circle circle = ch::Circle(), float mass = 0.f, ch::vec_t initialVelocity = ch::NULL_VEC);
	
	// D�tecte et r�soud une potentielle collision entre le projectile et les "murs" donn�s.
	// Ici, le but est de garantir que le projectile reste � l'int�rieur du rectangle donn�.
	void collideWithWalls(ch::AABB enclosingWalls);

	// Acc�l�re le projectile par le vecteur de v�locit� donn�. L'acc�l�ration est instantan�e.
	void accelerate(ch::vec_t acceleration);

	// D�place le projectile par la translation donn�e.
	void move(ch::vec_t translationVector);

	// Met � jour la position du projectile en fonction de sa vitesse et du temps �coul�.
	void update(float dt);

	// D�tecte et r�soud une potentielle collision entre le projectile actuel et le projectile donn�.
	// En cas de collision, les deux projectiles sont repositionn�s et une acc�l�ration leur est appliqu�e.
	void collideWith(CircleRigidBody& other);

	// Retourne la hitbox du projectile.
	ch::Circle getCircle() const;

	// Calcule l'�nergie cin�tique actuellement contenue dans le projectile.
	float computeKineticEnergy() const;

	// Retourne la masse du projectile.
	float getMass() const;

	// Retourne le vecteur de v�locit� du projectile.
	ch::vec_t getVelocity() const;
private:
	// Retourne l'inverse de la masse du projectile (= 1/m). Utile pour la r�solution de collisions.
	float inverseMass() const;

	// Sauvegarde la position actuelle et met � jour la "trace" du projectile.
	void savePosition();

	// M�thode h�rit�e de sf::Drawable. Affiche le projectile sur la fen�tre.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// Hitbox du projectile
	ch::Circle circle_;

	// Vecteur de v�locit�
	ch::vec_t vel_;

	// Masse du projectile.
	float mass_;

	// Trace du projectile : une queue de vecteurs repr�sentant des positions.
	std::deque<ch::vec_t> trace_;

	// Temps �coul� depuis la derni�re sauvegarde d'une position.
	float timeSinceLastTraceSave_;

	// Label affichant la masse du projectile.
	Label massLabel_;

	// Forme SFML repr�sentant le projectile.
	sf::CircleShape shape_;
};

