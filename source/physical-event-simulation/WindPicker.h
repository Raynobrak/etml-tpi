#pragma once

#include "Label.h"
#include "VectorArrow.h"

constexpr float WINDPICKER_RADIUS_PX = 80.f;
constexpr float MAX_WIND_SPEED = 50.f;

// Widget circulaire permettant de choisir la direction et l'intensit� du vent � l'aide de la souris.
// H�rite de sf::Drawable pour pouvoir �tre affich� sur une fen�tre.
class WindPicker : public sf::Drawable {
public:
	// Construit un nouveau WindPicker en fonction de sa position centrale.
	WindPicker(ch::vec_t center);

	// Calcule le vecteur de v�locit� du vent � partir du point s�lectionn� avec la souris.
	ch::vec_t computeWindIntensityAndDirection() const;

	// V�rifie si l'utilisateur a int�ragi avec le widget.
	void update(sf::Event event, ch::vec_t mousePos);

	// Construit une fl�che permettant de visualiser le vecteur de v�locit� du vent.
	VectorArrow buildWindArrow() const;
private:
	// Affiche le WindPicker sur la cible de rendu donn�e.
	// M�thode h�rit�e de sf::Drawable.
	void draw(sf::RenderTarget& target, sf::RenderStates) const override;
private:
	// Hitbox de la zone avec laquelle l'utilisateur peut int�ragir.
	ch::Circle clickableZone_;

	// Point s�lectionn� par l'utilisateur au sein de la zone cliquable. Bout de la fl�che.
	ch::vec_t selectedPoint_;

	// Retourne true si l'utilisateur est en train de modifier la position du bout de la fl�che.
	bool isDragging_;
};

