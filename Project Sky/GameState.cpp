#pragma once
#include "GameState.h"
#include <sstream>
#include "DefinitionsControl.h"
#include "MainMenuState.h"
#include <iostream>



namespace Sky
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
		
	}

	void GameState::Init()
	{
		
		this->_data->assets.LoadTexture("Game State Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Obstacle Up Element", OBSTACLES_UP_FILEPATH);
		this->_data->assets.LoadTexture("Obstacle Down Element", OBSTACLES_DOWN_FILEPATH);
		this->_data->assets.LoadTexture("Space Rocks", SPACE_ROCKS);
		this->_data->assets.LoadTexture("StarShip Texture Frame 1", STARSHIP_FRAME_1_FILE);
		this->_data->assets.LoadTexture("StarShip Texture Frame 2", STARSHIP_FRAME_2_FILE);
		this->_data->assets.LoadTexture("StarShip Texture Frame 3", STARSHIP_FRAME_3_FILE);
		this->_data->assets.LoadTexture("StarShip Texture Frame 4", STARSHIP_FRAME_4_FILE);
		this->_data->assets.LoadTexture("Starship Explosion", STARSHIP_FRAME_EXPLOSION);
		this->_data->assets.LoadTexture("Detection Obstacle", DETECTION_OBSTACLE);
		this->_data->assets.LoadFont("Score Font", SCORE_FONT);

		Ob = new Obstacles(_data); //Now it can acces everything in the window
		sR = new SpaceRocks(_data); 
		STS = new StarShip(_data);
		_score = new Score(_data);

		//AI TEST
		//_ai = new SkyAI(_data);

		

		_background.setTexture(this->_data->assets.GetTexture("Game State Background"));

		_gameActualState = ControlState::Start;

		numberDetectionScore = 0;
		
		//AI TEST
		//_ai->Reset();


		_score->Update(numberDetectionScore);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window) || _data->input.IsSpriteClicked2(sf::Keyboard::Space)) {
				if (ControlState::Over != _gameActualState) {
					_gameActualState = ControlState::Start;
					STS->Up();
				}

				
				
			}
		}
	}

	void GameState::Update(float dt)
	{
		int aux;
		

		if (ControlState::Over != _gameActualState) {
			STS->Animation(dt);
			sR->MoveRocks(dt);	
		}
		
		if (ControlState::Start == _gameActualState) {

			Ob->MoveOb(dt);
			

			if (clock.getElapsedTime().asSeconds() > OBSTACLE_SPAWN_SPEED) {
				Ob->RandomizeObstacles();
				Ob->SpawnInvisibleOb();
				Ob->SpawnBottomOb();
				Ob->SpawnTopOb();
				Ob->SpawnPassDetection();

				clock.restart();
			}

			
			STS->Update(dt);


			std::vector<sf::Sprite> _rockssprites = sR->GetSprites();
			std::vector<sf::Sprite> _obstacless = Ob->GetSprites();
			std::vector<sf::Sprite> &_detectionnumber = Ob->DetectionObstacles();

			for (int i = 0; i < _rockssprites.size(); i++) {
				if (collision.checkIfColliding(STS->GetSprite(),0.625f, _rockssprites.at(i),1.0f)) {
					_gameActualState = ControlState::Over;

					STS->Explosion();
					
				}
			}
			for (int i = 0; i < _obstacless.size(); i++) {
				if (collision.checkIfColliding(STS->GetSprite(), 0.625f, _obstacless.at(i),1.0f)) {
					_gameActualState = ControlState::Over;

					STS->Explosion();
					
				}
			}

			for (int i = 0; i < _detectionnumber.size(); i++) {
				if (collision.checkIfColliding(STS->GetSprite(), _detectionnumber.at(i))) {
					aux = numberDetectionScore;
					numberDetectionScore++;

					_score->Update(numberDetectionScore);

					if (numberDetectionScore > aux) {
						//Special Mode, para activarlo solo desactive los comentarios
						OBSTACLE_MOVEMENT_SPEED += 100;
						OBSTACLE_SPAWN_SPEED -= 0.01;
					}

					if (OBSTACLE_SPAWN_SPEED <= 0) {
						OBSTACLE_SPAWN_SPEED = 0.1;
					}

					_detectionnumber.erase(_detectionnumber.begin() + i);
				}
			}
		}

		if (ControlState::Over == _gameActualState) {
			OBSTACLE_MOVEMENT_SPEED = 100.0f;
			OBSTACLE_SPAWN_SPEED = 1.5f;
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}

		//AI TEST
		//_ai->Play();
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		Ob->DrawObs();
		sR->DrawRocks();
		STS->Draw();
		_score->Draw();
		

		this->_data->window.display();
	}
}