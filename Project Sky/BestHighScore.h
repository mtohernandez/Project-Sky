#pragma once

//Useless


#include <SFML/Graphics.hpp>
#include "DefinitionsControl.h"
#include "StarShip.h"
#include "Obstacles.h"
#include "GameControl.h"

namespace Sky {
	class AIControl : public StarShip, public Obstacles
	{
	public:
		AIControl(GameDataRef data);
		~AIControl();

		void Init();
		void Draw();
		void Update();
	
	private:

		GameDataRef _data;

		std::vector<sf::FloatRect> _centerdot;

		sf::RectangleShape detection;

	};
}


