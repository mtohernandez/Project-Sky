#pragma once

#include<SFML/Graphics.hpp>

namespace Sky {
	class Collisions
	{
	public:
		Collisions();

		bool checkIfColliding(sf::Sprite sprite1, sf::Sprite sprite2); //Does not work well.
		bool checkIfColliding(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2); //<-this
	};
}


