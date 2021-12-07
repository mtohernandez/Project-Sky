#pragma once

#include "SFML\Graphics.hpp"

/*
* INPUTMANAGER.H
* 
* IsSpriteClicked --> to check if a texture is being clicked, using a sprite object, mouse input and the renderwindow
* 
* Vector2i GetMousePosition --> To get the mouse position in the current renderwindow
* 
*/

namespace Sky
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window); //Mouse Input
		bool IsSpriteClicked2(sf::Keyboard::Key button); //Keyboard Input

		sf::Vector2i GetMousePosition(sf::RenderWindow& window);
	};
}