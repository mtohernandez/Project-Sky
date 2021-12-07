#include "SpaceRocks.h"
#include "DefinitionsControl.h"

namespace Sky {

	SpaceRocks::SpaceRocks(GameDataRef data) : _data(data) {

		sf::Sprite sprite(_data->assets.GetTexture("Space Rocks"));
		sf::Sprite sprite2(_data->assets.GetTexture("Space Rocks"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite2.getGlobalBounds().height);

		_spaceRocks.push_back(sprite);
		_spaceRocks.push_back(sprite2);
	}

	void SpaceRocks::MoveRocks(float dt) {
		for (unsigned short int i = 0; i < _spaceRocks.size(); i++) {
			float movement = OBSTACLE_MOVEMENT_SPEED * dt;
			_spaceRocks.at(i).move(-movement, 0.0f);
			if (_spaceRocks.at(i).getPosition().x < 0 - _spaceRocks.at(i).getGlobalBounds().width) {
				sf::Vector2f position(_data->window.getSize().x, _spaceRocks.at(i).getPosition().y);

				_spaceRocks.at(i).setPosition(position);
			}
		
		}

	}

	void SpaceRocks::DrawRocks() {
		for (unsigned short int i = 0; i < _spaceRocks.size(); i++) {
		
			_data->window.draw(_spaceRocks.at(i));
		
		}
	}

	const std::vector<sf::Sprite>& SpaceRocks::GetSprites() const {
		return _spaceRocks;
	}
}
