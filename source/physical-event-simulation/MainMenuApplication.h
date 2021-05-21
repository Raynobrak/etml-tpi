#pragma once

#include "SFMLApplicationBase.h"
#include "CollisionSimulationApp.h"
#include "BallisticSimulationApp.h"

#include "Label.h"
#include "Button.h"

// Repr�sente l'application qui g�re le menu principal.
// H�rite de SFMLApplicationBase car cette application n�cessite l'affichage d'une fen�tre.
class MainMenuApplication : public SFMLApplicationBase {
public:
	// Constructeur par d�faut
	MainMenuApplication();
private:
	// Traite l'�v�nement donn�
	void handleEvent(const sf::Event& event) override;

	// Met � jour l'application en fonction du temps �coul� depuis la derni�re mise � jour.
	void update(float dt) override;

	// Affiche l'application
	void customRender() override;
private:
	// Label pour le titre principal
	Label menuTitle_;

	// Bouton permettant d'ouvrir la simulation de collisions.
	Button collisionsSimButton_;

	// Bouton permettant d'ouvrir la simulation de balistique.
	Button ballisticSimButton_;

	// Bouton permettant de quitter le programme.
	Button leaveButton_;
};

