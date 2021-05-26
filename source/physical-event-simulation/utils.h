#pragma once

#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>

namespace utils {
	// Convertit un float en string en fonction d'un nombre de chiffres apr�s la virgule � afficher.
	std::string float_to_fixed_string(float real, int digits = 2);

	// Fonction libre permettant d'obtenir une r�f�rence vers une police d'�criture.
	// L'objet retourn� est une r�f�rence vers une sf::Font de la SFML.
	const sf::Font& get_default_font();

	// Retourne une r�f�rence constante vers une sf::Image statique contenant l'ic�ne de l'application.
	const sf::Image& get_application_icon_image();
}
