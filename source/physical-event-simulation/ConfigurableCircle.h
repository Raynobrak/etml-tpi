#pragma once

#include <SFML/Graphics.hpp>
#include "CircleRigidBody.h"
#include "DraggableCircle.h"
#include "Label.h"

// Repr�sente un cercle configurable.
// Les propri�t�s d'un cercle configurable sont sa masse (qui peut �tre modifi�e � l'aide de la molette
// de la souris) et sa position (que l'on peut changer en glissant-d�posant le cercle).
//
// Concr�tement, un cercle configurable est un widget permettant � l'utilisateur de configurer un futur CircleRigidBody.
//
// H�rite de DraggableCircle pour g�rer le drag&drop.
class ConfigurableCircle : public DraggableCircle {
public:
	// Construit un nouveau cercle configurable � partir d'une hitbox, de ses limites (la zone dans laquelle
	// le cercle peut �tre d�plac�) et de sa masse de d�part.
	ConfigurableCircle(ch::Circle circle, ch::AABB boundaries, float defaultMass = 1.f);

	// Met � jour l'objet en fonction d'un �v�nement qui s'est produit et de la position de la souris.
	// Si la position est modifi�e, cette m�thode retourne true, sinon false.
	bool update(const sf::Event& event, ch::vec_t mousePosOnWindow);

	// Retourne la hitbox du cercle.
	ch::Circle getCircle() const;

	// Construit un nouveau corps physique � partir de la configuration actuelle.
	CircleRigidBody constructCircleRigidBody() const;
private:
	// M�thode h�rit�e de sf::Drawable (dont DraggableCircle h�rite elle-m�me). Affiche le cercle et ses propri�t�s sur la cible de rendu donn�.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// Masse du futur corps physique
	float mass_;

	// Label affichant la masse.
	Label massLabel_;
};

