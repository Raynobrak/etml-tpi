#pragma once

#include <SFML/Graphics.hpp>
#include <charbrary.h>

const sf::Color DEFAULT_ARROW_COLOR = sf::Color::White;

// Widget repr�sentant un vecteur, c'est � dire, une fl�che avec une longueur, une direction et un point d'origine.
// H�rite de sf::Drawable pour permettre l'affichage sur une fen�tre.
class VectorArrow : public sf::Drawable {
public:
	// Construit une nouvelle fl�che � partir de la valeur du vecteur sous-jacent, de son point de d�part et de sa couleur.
	VectorArrow(ch::vec_t value = ch::NULL_VEC, ch::vec_t origin = ch::NULL_VEC, sf::Color color = DEFAULT_ARROW_COLOR);

	// Red�finit la valeur du vecteur sous-jacent
	void setLength(ch::vec_t newLength);

	// Red�finit le point de d�part de la fl�che.
	void setOrigin(ch::vec_t newOrigin);
private:
	// Affiche la fl�che sur la cible de rendu donn�e.
	// M�thode h�rit�e de sf::Drawable.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// Point de d�part
	ch::vec_t origin_;

	// Vecteur repr�sentant la fl�che.
	ch::vec_t length_;

	// Couleur de la fl�che
	sf::Color color_;
};

