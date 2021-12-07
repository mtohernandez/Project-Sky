#pragma once

#include <SFML/Graphics.hpp>
#include "GameControl.h"
#include <vector>

namespace Sky {
	class SpaceRocks
	{
	public:
		SpaceRocks(GameDataRef data);

		void MoveRocks(float dt);
		void DrawRocks();

		const std::vector<sf::Sprite>& GetSprites() const;

	protected:
		GameDataRef _data;

		std::vector<sf::Sprite>_spaceRocks;
	};
}


