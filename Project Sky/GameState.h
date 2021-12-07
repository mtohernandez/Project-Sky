#pragma once

#include <SFML/Graphics.hpp>
#include "StateControl.h"
#include "GameControl.h"
#include "Obstacles.h"
#include "SpaceRocks.h"
#include "StarShip.h"
#include "Collisions.h"
#include "Score.h"

//AI
#include "Sky.h"

namespace Sky
{
	class GameState : public SkyControl
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	protected:
		GameDataRef _data;

		sf::Sprite _background;

		Obstacles* Ob; //Pointer of obstacles

		SpaceRocks* sR;

		StarShip* STS;

		Collisions collision;

		Score *_score;

		sf::Clock clock;

		int _gameActualState;

		int numberDetectionScore;
	};
}