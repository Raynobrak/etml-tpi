#pragma once

#include <SFML/Graphics.hpp>
#include <charbrary.h>

// Repr�sente un cercle que l'utilisateur peut d�placer avec la souris
// H�rite de sf::Drawable (pour l'affichage).
class DraggableCircle : public sf::Drawable {
public:
	// Construit une nouvelle instance � partir d'un cercle, d'un rectangle repr�sentant la zone de d�placement et d'un bool�en indiquant si l'objet est bloqu� horizontalement.
	DraggableCircle(ch::Circle circle, ch::AABB boundaries, bool lockHorizontally = false);

	// Retourne la position du centre du cercle.
	ch::vec_t getCirclePos() const;

	// Retourne le cercle sous-jacent.
	ch::Circle getCircle() const;

	// Met � jour le glisser-d�poser en fonction d'un �v�nement et de la position de la souris.
	bool updateDragAndDrop(const sf::Event& event, ch::vec_t mousePosOnWindow);
	
	// Change la couleur de fond du cercle.
	void setFillColor(sf::Color newColor);

	// Change la couleur de la bordure du cercle.
	void setOutlineColor(sf::Color newColor);
protected:
	// Cercle sous-jacent.
	ch::Circle circle_;

	// Zone dans laquelle le cercle peut �tre d�plac�.
	ch::AABB boundaries_;
private:
	// Retourne true si la position donn� se trouve dans le cercle.
	bool isHovered(ch::vec_t mousePos) const;

	// V�rifie si la position donn�e est valide (= dans les limites) et d�place le cercle si c'est le cas.
	void updatePosition(ch::vec_t newPos);

	// Affiche le widget
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	// Forme SFML affich�e sur l'�cran pour repr�senter le cercle.
	sf::CircleShape circleShape_;

	// True si le cercle est fix� sur un rail vertical, sinon false.
	bool lockedHorizontally_;

	// True si le cercle est en train d'�tre d�plac�, sinon false.
	bool isDragging_;

	// Point de d�part du drag&drop
	ch::vec_t dragOrigin_;
};

