#include <sstream>
#include "DefinitionsControl.h"
#include "MainMenuState.h"
#include "GameState.h"

#include <iostream>

namespace Sky
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
		_animationrunnerPlay = 0;
	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("PlayButton frame 1", PLAYBUTTON_FRAME_1_FILE);
		this->_data->assets.LoadTexture("PlayButton frame 2", PLAYBUTTON_FRAME_2_FILE);
		this->_data->assets.LoadTexture("PlayButton frame 3", PLAYBUTTON_FRAME_3_FILE);
		this->_data->assets.LoadTexture("PlayButton frame 4", PLAYBUTTON_FRAME_4_FILE);
		this->_data->assets.LoadTexture("PlayButton frame 5", PLAYBUTTON_FRAME_5_FILE);
		//this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_animationFramesPlay.push_back(_data->assets.GetTexture("PlayButton frame 1"));
		_animationFramesPlay.push_back(_data->assets.GetTexture("PlayButton frame 2"));
		_animationFramesPlay.push_back(_data->assets.GetTexture("PlayButton frame 3"));
		_animationFramesPlay.push_back(_data->assets.GetTexture("PlayButton frame 4"));
		_animationFramesPlay.push_back(_data->assets.GetTexture("PlayButton frame 5"));



		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(_animationFramesPlay.at(_animationrunnerPlay));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Game State
				this->_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::AnimationPlay(float dt) {
		
		if (_clock.getElapsedTime().asSeconds() > PLAYBUTTON_ANIMATION_CONTROL / _animationFramesPlay.size()) {
			if (_animationrunnerPlay < _animationFramesPlay.size() - 1) {
				_animationrunnerPlay++;
			}
			else {
				_animationrunnerPlay = 0;
			}

			_playButton.setTexture(_animationFramesPlay.at(_animationrunnerPlay));
			_clock.restart();
		}
	}


	void MainMenuState::Update(float dt)
	{
		AnimationPlay(dt);
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);

		this->_data->window.display();
	}
}