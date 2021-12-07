#pragma once

#include <SFML/Graphics.hpp>
#include "StateControl.h"
#include "GameControl.h"

namespace Sky
{
	class MainMenuState : public SkyControl
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void AnimationPlay(float dt);
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
	
		std::vector<sf::Texture> _animationFramesPlay;
		sf::Clock _clock;
		int _animationrunnerPlay;

	};
}
