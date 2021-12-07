#pragma once

#include <SFML/Graphics.hpp>
#include "GameControl.h"
#include "DefinitionsControl.h"

namespace Sky {
	class StarShip
	{
	public:
		StarShip(GameDataRef data);
		void Draw();
		void Animation(float dt);
		void Explosion();
		void Update(float dt);
		void Up();

		const sf::Sprite& GetSprite() const;

	protected:
		GameDataRef _data;
		sf::Sprite _starship;

		std::vector<sf::Texture> _animationFrames;
		sf::Texture _FIRE;
	
		unsigned int _animationrunner;

		sf::Clock _clock;
		sf::Clock _jumpmovement;
	
		int _starShipState;
	};

}

