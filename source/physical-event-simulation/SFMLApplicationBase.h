#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

#include "SFMLApplicationSettings.h"

// Classe de base abstraite pouvant �tre utilis�e pour les applications comportant une fen�tre.
// Le but de cette classe est d'encapsuler la boucle principale de l'application ainsi que le fonctionnement d'une fen�tre SFML.
class SFMLApplicationBase {
public: 
	// Initialise l'application avec les param�tres donn�s.
	void initApplication(SFMLApplicationSettings settings = SFMLApplicationSettings());

	// Lance l'application
	void run();
protected: 
	// M�thode virtuelle pure (devant �tre surcharg�e dans les classes d�riv�es).
	// Les surcharges devront s'occuper de mettre � jour l'application en fonction du pas de temps.
	virtual void update(float dt) = 0;

	// M�thode utilitaire permettant d'obtenir la position de la souris par rapport � l'origine (le coin haut-gauche) de la fen�tre.
	sf::Vector2f getMousePosOnWindow() const;

	// Retourne la taille de la fen�tre sous forme d'un vecteur.
	sf::Vector2f getWindowSize() const;

	// Quitte l'application.
	void exitApplication();

	// Ferme la fen�tre sans quitter l'application.
	void closeWindow();

	// Affiche la fen�tre si ce n'�tait pas d�j� le cas.
	void showWindow();

	// M�thode utilitaire permettant d'afficher un sf::Drawable sur la fen�tre.
	void drawOnWindow(const sf::Drawable& d, const sf::RenderStates states = sf::RenderStates::Default);

	// Change l'ic�ne de la fen�tre
	void setWindowIcon();

	// Fen�tre SFML sous-jacente.
	sf::RenderWindow window_;
private: 
	// M�thode virtuelle appell�e lorsque un �v�nement est d�tect�.
	virtual void handleEvent(const sf::Event& event) = 0;

	// Efface la fen�tre, appelle customRender() et affiche la fen�tre.
	void render();

	// M�thode virtuelle pure (devant �tre surcharg�es dans les classes d�riv�es) qui devra contenir les appels � la m�thode drawOnWindow().
	virtual void customRender() = 0;
	
private:
	// Background de la fen�tre
	sf::Color windowClearColor_;

	// Pas de temps s�parant chaque frame et avec laquel l'application est mise � jour.
	float fixedTimeStep_;

	// Nombre de rafra�chissements de la fen�tre par secondes.
	float fps_;

	// Indique si l'application doit s'arr�ter. Si vrai, la boucle principale sera quitt� lors de la prochain v�rification.
	bool exitApplication_;

	// Param�tres initiaux donn�s lors de la cr�ation de l'application.
	SFMLApplicationSettings originalSettings_;
};

