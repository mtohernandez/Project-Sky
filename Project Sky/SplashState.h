#pragma once

#include <SFML/Graphics.hpp>
#include "StateControl.h"
#include "GameControl.h"

namespace Sky
{
	class SplashState : public SkyControl
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}