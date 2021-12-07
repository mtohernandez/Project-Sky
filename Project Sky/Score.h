#pragma once

#include <SFML/Graphics.hpp>
#include "DefinitionsControl.h"
#include "GameControl.h"

namespace Sky{
	class Score
	{
	public:
		Score(GameDataRef data);
		~Score();

		void Draw();
		void Update(int score);
	private:

		GameDataRef _data;

		sf::Text _scoreText;
	};
}


