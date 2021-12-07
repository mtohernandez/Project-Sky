#pragma once
/*
* SpawnInvisible() --> It is to fix the issue with the lag 
* 
*/

#include <SFML/Graphics.hpp>
#include "GameControl.h"
#include <vector>
#include "DefinitionsControl.h"

namespace Sky {
	class Obstacles
	{
	public:
		Obstacles(GameDataRef data);

		void SpawnBottomOb();
		void SpawnTopOb();
		void SpawnInvisibleOb();
		void MoveOb(float dt);
		void DrawObs();
		void RandomizeObstacles();

		void SpawnPassDetection();

		const std::vector<sf::Sprite>& GetSprites() const;
		std::vector<sf::Sprite>& DetectionObstacles();

	protected:
		GameDataRef _data;
		std::vector<sf::Sprite> _obstacles;
		std::vector<sf::Sprite> _detectionnumber;

		int _spaceheight, _rocksSpawnY;

	};
}



