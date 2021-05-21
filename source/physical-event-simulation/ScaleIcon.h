#pragma once

#include "color_palette.h"
#include <SFML/Graphics.hpp>
#include "Label.h"

// Repr�sente une �chelle.
// Consiste simplement en l'affichage d'une distance ainsi que d'un label donnant la valeur de cette distance.
// Cette classe est utilis�e pour afficher la distance prise par un m�tre dans les simulations.
// H�rite de sf::Drawable pour pouvoir �tre affich� sur une fen�tre.
class ScaleIcon : public sf::Drawable {
public:
	// Construit une nouvelle �chelle � partir d'une position centrale et du nombre de pixels dans un m�tre.
	ScaleIcon(ch::vec_t center, float pixelsPerMeter);

	// Change la couleur de l'�chelle pour qu'elle soit totalement opaque.
	void makeOpaque();

	// Change la couleur de l'�chelle pour qu'elle soit semi-transparente.
	void makeSemiTransparent();
private:
	// Affiche l'�chelle sur la fen�tre donn�e.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
private:
	// Couleur actuelle de l'�chelle.
	sf::Color currentColor_;

	// Label affichant la distance en m�tres.
	Label label_;

	// Zone prise par l'�chelle (sans compter le label qui, lui, est d�cal� vers le haut).
	ch::AABB zone_;
};

