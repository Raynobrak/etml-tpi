#pragma once

#include "SFMLApplicationBase.h"
#include "ProjectileLauncher.h"
#include "color_palette.h"
#include "Button.h"
#include "ScaleIcon.h"
#include "TargetSlider.h"
#include "CircleRigidBody.h"
#include "FadingText.h"
#include "WindPicker.h"
#include "VectorArrow.h"
#include "utils.h"

// Repr�sente l'application qui g�re la simulation de balistique.
// H�rite de SFMLApplicationBase car cette application n�cessite l'affichage d'une fen�tre.
class BallisticSimulationApp : public SFMLApplicationBase {
public:
	// Constructeur par d�faut
	BallisticSimulationApp();
private:
	// Traite l'�v�nement donn�
	// M�thode h�rit�e de SFMLApplicationBase
	void handleEvent(const sf::Event& event) override;

	// Met � jour les diff�rents widgets de l'interface
	void updateWidgets(const sf::Event& event, ch::vec_t mousePos);

	// Met � jour l'application en fonction du pas de temps donn�
	// M�thode h�rit�e de SFMLApplicationBase
	void update(float dt) override;

	// Met � jour les forces de frottement s'appliquant sur le projectile
	void applyDragForce(float dt);

	// Affiche la simulation sur la fen�tre.
	// M�thode h�rit�e de SFMLApplicationBase
	void customRender() override;

	// D�marre ou stoppe la simulation (en fonction de son �tat actuel)
	void switchSimulationMode();

	// Met � jour le texte du bouton permettant de lancer/arr�ter la simulation
	void updateLaunchButtonText();

	// Retourne true si le projectile est en dehors des limites, sinon false.
	bool projectileIsOutOfBounds() const;

	// Affiche un message au milieu de l'�cran qui va progressivement dispara�tre.
	void spawnFadingText(std::string text);
private:
	// Lanceur de projectile
	ProjectileLauncher launcher_; 

	// Bouton de d�marrage/arr�t de la simulation
	Button launchSimulationButton_; 

	// �tat de la simulation (en cours/arr�t�e). True si la simulation est en cours.
	bool simulationRunning_;

	// Un pointeur vers le projectile.
	// Lorsque le projectile existe, le pointeur pointera vers une instance de projectile, sinon, il aura la valeur nullptr.
	std::unique_ptr<CircleRigidBody> projectile_;

	// Un pointeur vers le potentiel texte � afficher au milieu de l'�cran.
	// �tant donn� qu'un FadingText est in�vitablement vou� � dispara�tre (par d�finition), un pointeur est utilis� pour
	// permettre de repr�senter le cas o� il n'y a pas (ou plus) de texte � afficher.
	std::unique_ptr<FadingText> fadingText_;

	// Ic�ne affichant l'�chelle de la simulation avec une l�gende.
	ScaleIcon scale_;

	// Cible dont la position peut �tre modifi�e par l'utilisateur.
	TargetSlider target_;

	// Widget permettant � l'utilisateur de s�lectionner l'intensit� et la direction du vent
	WindPicker windPicker_;

	// Label affichant l'intensit� du vent
	Label windIntensityLabel_;
};

