#pragma once

#include "SFMLApplicationBase.h"
#include "ProjectileLauncher.h"
#include "DraggableCircle.h"
#include "color_palette.h"
#include "Button.h"
#include "CircleRigidBody.h"
#include "ConfigurableCircle.h"
#include "utils.h"
#include "ScaleIcon.h"

// Repr�sente l'application qui g�re la simulation de collisions.
// H�rite de SFMLApplicationBase car cette application n�cessite l'affichage d'une fen�tre.
class CollisionSimulationApp : public SFMLApplicationBase {
public:
	// Constructeur par d�faut
	CollisionSimulationApp();
private:
	// Traite l'�v�nement donn�.
	// M�thode h�rit�e de SFMLApplicationBase
	void handleEvent(const sf::Event& event) override;

	// Met � jour les diff�rents widgets de l'interface
	void updateWidgets(const sf::Event& event, ch::vec_t mousePos);

	// Met � jour la simulation en fonction du temps �coul�
	// M�thode h�rit�e de SFMLApplicationBase
	void update(float dt) override;

	// Affiche l'application sur la fen�tre.
	// M�thode h�rit�e de SFMLApplicationBase
	void customRender() override;

	// Met � jour le texte du bouton permettant de lancer/stopper la simulation.
	void updateLaunchButtonText();

	// D�marre ou stoppe la simulation (en fonction de son �tat actuel)
	void switchSimulationMode();

	// Ajoute des nouveaux objets � des positions al�atoires.
	void spawnRandomCircles();
private:
	// Lanceur de projectiles
	ProjectileLauncher launcher_;

	// Contient tous les ConfigurableCircle lorsque la simulation est arr�t�e.
	std::vector<ConfigurableCircle> configurableCircles_;

	// Contient tous les projectiles de la simulation.
	std::vector<CircleRigidBody> circleRigidBodies_;

	// Bouton permettant de lancer/arr�ter la simulation.
	Button launchSimulationButton_;

	// �tat de la simulation : true si elle est en cours, sinon false.
	bool simulationRunning_;

	// Ic�ne permettant de visualiser l'�chelle de la simulation.
	ScaleIcon scale_;
};

