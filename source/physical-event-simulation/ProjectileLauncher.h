#pragma once

#include <SFML/Graphics.hpp>
#include "Label.h"
#include "DraggableCircle.h"
#include "LauncherSling.h"
#include "constants.h"
#include "CircleRigidBody.h"

// Repr�sente le lanceur de projectile. Le lanceur est une partie de l'interface graphique permettant de
// positionner le futur projectile, de sp�cifier la direction et la vitesse de d�part et de visualiser ces donn�es.
// H�rite de sf::Drawable pour pouvoir �tre affich� sur une fen�tre.
class ProjectileLauncher : public sf::Drawable {
public:
	// Construit le lanceur � partir de la zone cliquable, du nombre de pixels par m�tre et du rayon du projectile en m�tres.
	ProjectileLauncher(ch::AABB zone, float pixelsPerMeter, float projectileRadiusInMeters);

	// Met � jour le lanceur pour prendre en compte les nouveaux �v�nements.
	void update(const sf::Event& event, ch::vec_t mousePosOnWindow);

	// Construit le futur projectile � partir de l'�tat actuel du lanceur.
	CircleRigidBody constructCircleRigidBody() const;
private:
	// Met � jour le label montrant les propri�t�s du futur projectile.
	void updateInformations();

	// Affiche le lanceur sur la fen�tre donn�e.
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// Label montrant les propri�t�s du futur projectile.
	Label topLeftInformations_;

	// Forme SFML repr�sentant la zone cliquable du lanceur. 
	sf::RectangleShape zone_;

	// Un cercle que l'on peut drag&drop repr�sentant le futur projectile.
	DraggableCircle projectile_;

	// Partie "catapulte" du lanceur. G�re la position du bras de lancement.
	LauncherSling sling_;
	
	// Masse du futur projectile.
	float projectileMass_;

	// Valeur permettant la conversion de pixels en m�tres et inversement.
	float pixelsPerMeter_;
};

