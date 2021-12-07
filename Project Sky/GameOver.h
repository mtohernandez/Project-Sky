#pragma once

#include <SFML/Graphics.hpp>
#include "StateControl.h"
#include "GameControl.h"

namespace Sky
{
	class GameOverState : public SkyControl
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
	};
}