#pragma once

/*
* GAMECONTROL.H
* 
* Structure --> Contains all the Game engine elements 
* 
* Shared_ptr --> Shared pointer with the data and control of the game engine 
* 
* Clock --> Provides the most precise time that the undelying OS can achieve: better in seconds
* 
* Game() --> Constructor with the width and the height of the screen and the name on titlebar
* 
* dt --> Delta time to control the frames in game 
* 
* Run() --> Game loop (Sfml default)
* 
* 
*/



#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

namespace Sky
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}

