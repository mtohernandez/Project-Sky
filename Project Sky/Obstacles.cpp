#include "Obstacles.h"
#include <time.h>


namespace Sky {
	Obstacles::Obstacles(GameDataRef data) : _data(data) {
		_spaceheight = _data->assets.GetTexture("Space Rocks").getSize().y;
		_rocksSpawnY = 0;
		srand((unsigned)time(0));
	}

	void Obstacles::SpawnBottomOb() {

		sf::Sprite sprite(_data->assets.GetTexture("Obstacle Up Element"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y + 70 - sprite.getGlobalBounds().height - _rocksSpawnY);

		_obstacles.push_back(sprite); //Adds the sprite element at the end
	}

	void Obstacles::SpawnTopOb() {

		sf::Sprite sprite(_data->assets.GetTexture("Obstacle Down Element"));
		sprite.setPosition(_data->window.getSize().x, -_rocksSpawnY - 60);

	

		_obstacles.push_back(sprite);

	}

	void Obstacles::SpawnInvisibleOb() {

		sf::Sprite sprite(_data->assets.GetTexture("Obstacle Up Element"));
		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y + 70 - sprite.getGlobalBounds().height);

		sprite.setColor(sf::Color(0, 0, 0, 0)); //Set to invisible

		_obstacles.push_back(sprite);

	}

	void Obstacles::SpawnPassDetection() {

		sf::Sprite sprite(_data->assets.GetTexture("Detection Obstacle"));
		sprite.setPosition(_data->window.getSize().x,0);

		_detectionnumber.push_back(sprite);

	}

	void Obstacles::MoveOb(float dt) {

		for (unsigned short int i = 0; i < _obstacles.size(); i++) {
			
			if (_obstacles.at(i).getPosition().x < 0 - _obstacles.at(i).getGlobalBounds().width) {
				_obstacles.erase(_obstacles.begin() + i);
			}
			else {
				float movement = OBSTACLE_MOVEMENT_SPEED * dt;

				_obstacles.at(i).move(-movement, 0); //Because is a Transformable statement we can move it with the sf::Transformable::move
			}
		}

		for (unsigned short int i = 0; i < _detectionnumber.size(); i++) {

			if (_detectionnumber.at(i).getPosition().x < 0 - _detectionnumber.at(i).getGlobalBounds().width) {
				_detectionnumber.erase(_detectionnumber.begin() + i);
			}
			else {
				float movement = OBSTACLE_MOVEMENT_SPEED * dt;

				_detectionnumber.at(i).move(-movement, 0); //Because is a Transformable statement we can move it with the sf::Transformable::move
			}
		}
	}


	void Obstacles::DrawObs() {
		for (unsigned short int i = 0; i < _obstacles.size(); i++) {
			_data->window.draw(_obstacles.at(i));
		}
	}

	void Obstacles::RandomizeObstacles() {
		_rocksSpawnY = rand() % (_spaceheight + RANDOM_VARIATION);
	}

	const std::vector<sf::Sprite>& Obstacles::GetSprites() const {
		return _obstacles;
	}

	std::vector<sf::Sprite>& Obstacles::DetectionObstacles(){
		return _detectionnumber;
	}
}

