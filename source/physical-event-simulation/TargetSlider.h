#pragma once

#include "DraggableCircle.h"
#include "CircleRigidBody.h"

// Repr�sente la cible dans la simulation de balistique.
// Permet � l'utilisateur de drag&drop la cible pour changer sa hauteur.
class TargetSlider : public DraggableCircle {
public:
	// Construit une nouvelle cible � partir de la position horizontale, de la hauteur de la zone d'�dition et du rayon de la cible.
	TargetSlider(float xPos, float height, float targetRadius);

	// Met � jour le drag&drop en fonction de l'�v�nement survenu ainsi que de la position de la souris sur la fen�tre.
	void update(sf::Event event, ch::vec_t mousePos);

	// Retourne true si le projectile donn� est en collision avec la cible.
	bool checkForCollision(const CircleRigidBody& body) const;
private:
	// Affiche la cible sur la fen�tre donn�e.
	// M�thode h�rit�e de sf::Drawable (dont DraggableCircle h�rite) permettant l'affichage sur une fen�tre.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	// "rail" sur lequel la cible peut se d�placer.
	sf::VertexArray sliderRail_;
};

