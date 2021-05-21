#pragma once

#include "Label.h"

// Repr�sente un bouton.
// Le bouton est d�clench� lorsque le bouton de la souris est rel�ch�. Cela peut �tre d�tect� � l'aide de la m�thode checkForMouseRelease().
// H�rite de sf::Drawable pour pouvoir �tre affichable sur une fen�tre SFML.
class Button : public sf::Drawable {
public:
	// Constructeur par d�faut
	Button();

	// Construit un bouton � partir d'une AABB (un rectangle), d'une taille de police et d'un texte � afficher.
	Button(ch::AABB clickableZone, unsigned characterSize, std::string text);

	// Permet d'initialiser un bouton apr�s coup si jamais il a �t� construit par d�faut.
	void init(ch::AABB clickableZone, unsigned characterSize, std::string text);

	// Met � jour l'�tat du bouton et v�rifie si l'�v�nement donn� ainsi que la position de la souris indiquent qu'il a �t� d�clench�.
	// Le bouton est d�clench� lorsque le bouton a �t� cliqu� et que le bouton de la souris est rel�ch� lorsque la souris survole le bouton.
	bool checkForMouseRelease(ch::vec_t mousePos, sf::Event event);

	// Retourne true si la position donn�e se trouve dans la zone du bouton, sinon false.
	bool isHovered(ch::vec_t mousePos) const;

	// Permet de changer le texte affich� sur le bouton.
	void setText(std::string newText);

	// D�finit la couleur du texte du bouton.
	void setTextColor(sf::Color newColor);
private:
	// M�thode h�rit�e de la classe abstraite sf::Drawable. Affiche le bouton sur la cible de rendu donn�e.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// Label qui sera affich� sur le bouton.
	Label buttonLabel_;

	// �tat du bouton : Est-ce qu'il est actuellement press� ?
	bool isClicked_;
};

