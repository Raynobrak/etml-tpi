#pragma once

#include "Label.h"

constexpr float DEFAULT_FADING_TIME = 3.f;

// Un FadingText est un label dont l'opacit� diminue avec le temps.
// Cette classe est utilis�e pour afficher un message lorsque la cible de la simulation de balistique est atteinte (ou non).
// Elle h�rite donc de Label.
class FadingText : public Label {
public:
	// Construit un nouveau FadingText en fonction de sa position centrale, du texte � afficher et
	// du temps n�cessaire � sa disparition totale.
	FadingText(ch::vec_t center, std::string text, float fadingTime = DEFAULT_FADING_TIME);

	// Met � jour l'opacit� du texte en fonction du temps �coul� depuis la derni�re mise � jour.
	void update(float dt);

	// Retourne true si le texte a totalement disparu. Permet de savoir si l'objet peut �tre supprim�.
	bool hasDisappeared() const;
private:
	// Temps restant avant la disparition totale du texte.
	float timeLeft_;
	
	// Dur�e totale pendant laquelle le texte est affich�.
	float fadingTime_;
};

