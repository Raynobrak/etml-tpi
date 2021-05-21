#pragma once

#include <SFML/Graphics.hpp>
#include <charbrary.h>
#include "DraggableCircle.h"
#include "color_palette.h"
#include "constants.h"

// Le LauncherSling est un partie du ProjectileLauncher correspondant � la partie "catapulte" du lancuer.
// Concr�tement, cette classe permet de g�rer le drag&drop du bras de lancement ainsi que de calculer
// la vitesse et la direction du lancer.
// H�rite de sf::Drawable pour pouvoir �tre affich� sur une cible de rendu SFML.
class LauncherSling : public sf::Drawable {
public:
	// Construit une nouvelle "catapulte" � partir des limites dans laquelle le bras peut �tre d�plac�, du DraggableCircle repr�sentant
	// le projectile et du nombre de pixels contenus dans un m�tre (servira pour la conversion en m/s).
	LauncherSling(ch::AABB zone, const DraggableCircle& circle, float pixelsPerMeter);

	// Met � jour le drag&drop � partir d'un �v�nement qui s'est produit et de la position de la souris.
	void updateDragAndDrop(const sf::Event& event, ch::vec_t mousePosOnWindow);

	// Retourne un vecteur unitaire repr�sentant la direction du projectile.
	ch::vec_t getProjectileDirection() const;

	// Retourne la vitesse du projectile au lancer en m�tres par seconde.
	float getProjectileInitialVelocityInMetersPerSecond() const;

	// Retourne true si le projectile est survol� avec la souris.
	bool isProjectileHovered(ch::vec_t mousePos) const;
private:
	// Met � jour la position du bras de lancement.
	void updatePosition(ch::vec_t newPos);
private:
	// Forme SFML repr�sentant le bout du bras de lancement.
	sf::RectangleShape rectShape_;

	// Bout du bras de lancement : un rectangle.
	ch::AABB rect_;

	// Limites dans laquelle le bras de lancement peut �tre d�plac�.
	ch::AABB boundaries_;

	// R�f�rence constante vers le projectile duquel le bras de lancement part.
	const DraggableCircle& projectile_;

	// Affiche le bras de lancement sur la cible de rendu donn�e.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Valeur permettant la conversion de pixels en m�tres
	float pixelsPerMeter_;
};

