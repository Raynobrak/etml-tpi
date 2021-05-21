#pragma once

#include <SFML/Graphics.hpp>
#include <charbrary.h>

#include <iostream>

#include "color_palette.h"

// Repr�sente un label, c'est � dire un texte pouvant �tre affich� sur une fen�tre (d'o� l'h�ritage de sf::Drawable).
// Cette classe Label a pour but d'am�liorer et d'�tendre les fonctionnalit�s de la classe sf::Text de la SFML.
// Par exemple, Label va automatiquement centrer le texte au sein d'une zone (AABB), chose qui est parfois compliqu� avec sf::Text.
class Label : public sf::Drawable {
public:
	// Constructeur par d�faut
	Label();

	// Construit un nouveau label � partir d'un rectangle au sein duquel il sera centr�, d'une taille de police et d'un texte � afficher.
	Label(ch::AABB zone, unsigned characterSize, std::string text);

	// Initialise le Label apr�s sa construction. Utile si l'objet a �t� construit par d�faut.
	void init(ch::AABB zone, unsigned characterSize, std::string text);

	// D�finit le texte affich� par le label.
	void setText(std::string str);

	// D�finit la position du coin haut-gauche de la zone contenant le Label.
	void setPosition(ch::vec_t newPos);

	// D�finit la couleur de remplissage du texte.
	void setTextColor(sf::Color newColor);

	// Retourne la zone du label, c'est � dire, une AABB.
	ch::AABB getZone() const;
private:
	// Affiche le Label sur la cible de rendu donn�e
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Centre le texte au sein de la zone. Cette m�thode doit �tre appell�e lorsque la position du texte est chang�e.
	void centerText();

	// Zone invisible et conceptuelle englobant le texte et au sein de laquelle il est centr� verticalement et horizontalement.
	ch::AABB textZone_;

	// Objet sous-jacent de la SFML permettant d'afficher du texte � l'�cran.
	sf::Text text_;
};

