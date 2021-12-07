#include "Score.h"
#include <string>

namespace Sky {
	Score::Score(GameDataRef data) : _data(data){
		_scoreText.setFont(_data->assets.GetFont("Score Font"));

		_scoreText.setString("0");

		_scoreText.setCharacterSize(100);
		
		_scoreText.setFillColor(sf::Color::White);

		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 4 + 10, _scoreText.getGlobalBounds().height / 4);
		_scoreText.setPosition(_scoreText.getGlobalBounds().width / 4 + 10, _scoreText.getGlobalBounds().height / 4);


		
	}

	Score::~Score() {}


	void Score::Draw() {
		_data->window.draw(_scoreText);
	}
	void Score::Update(int score) {
		_scoreText.setString(std::to_string(score));

	}
}