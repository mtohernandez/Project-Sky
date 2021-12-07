#include "StarShip.h"


namespace Sky {
	StarShip::StarShip(GameDataRef data) : _data(data) {
		_animationrunner = 0;

		_animationFrames.push_back(_data->assets.GetTexture("StarShip Texture Frame 1"));
		_animationFrames.push_back(_data->assets.GetTexture("StarShip Texture Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("StarShip Texture Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("StarShip Texture Frame 4"));

		_starship.setTexture(_animationFrames.at(_animationrunner));

		_starship.setPosition((_data->window.getSize().x / 4) - (_starship.getGlobalBounds().width / 2), (_data->window.getSize().y / 4) - (_starship.getGlobalBounds().height / 2));

		_starShipState = STARSHIP_STATE_STILL;
	}

	void StarShip::Draw() {
		_data->window.draw(_starship);
	}

	void StarShip::Animation(float dt) {
		if (_clock.getElapsedTime().asSeconds() > STARSHIP_ANIMATION_CONTROL / _animationFrames.size()) {
			if (_animationrunner < _animationFrames.size() - 1) {
				_animationrunner++;
			}
			else {
				_animationrunner = 0;
			}

			_starship.setTexture(_animationFrames.at(_animationrunner));
			_clock.restart();
		}
	}

	void StarShip::Explosion() {
		_FIRE.loadFromFile(STARSHIP_FRAME_EXPLOSION);
		_starship.setTexture(_FIRE);
	}

	void StarShip::Update(float dt) {
		int force,neg;
		
		if (STARSHIP_STATE_FLYING == _starShipState) {
			_starship.move(0, -pow(2,JUMP_COUNT) * 0.6 * dt);	
		}

		if (!_data->input.IsSpriteClicked2(sf::Keyboard::Space)){
			_starShipState = STARSHIP_STATE_FALLING;
		}
		
		if(STARSHIP_STATE_FALLING == _starShipState) {
			_starship.move(0, GRAVITY * dt);
		}

		
		//This does not work


		/*
		if (STARSHIP_STATE_FLYING == _starShipState) {
			
			JUMP_COUNT = 10;

			if (JUMP_COUNT >= -10) {
				neg = 1;
				if (JUMP_COUNT < 0) {
					neg = -1;
				}
				_starship.move(0, -(pow(2, JUMP_COUNT) * 1.2 * neg) * dt);
				JUMP_COUNT -= 1;
			}

			_starShipState = STARSHIP_STATE_FALLING;
		
		}else if(STARSHIP_STATE_FALLING == _starShipState){

			_starship.move(0, GRAVITY * 0.7 * dt);
		}
		*/
		/*
		if (STARSHIP_STATE_FALLING == _starShipState) {
			JUMP_COUNT = 10;
			STARSHIP_MASS = 2;
		}
		
		else if (STARSHIP_STATE_FLYING == _starShipState) {
			force = (1 / 2) * STARSHIP_MASS * (pow(2,JUMP_COUNT));
			_starship.move(0, -force * dt);

			JUMP_COUNT -= 1;

			if (JUMP_COUNT < 0) {
				STARSHIP_MASS = -1;
			}

			if (JUMP_COUNT == -10) {
				
				_starShipState = STARSHIP_STATE_FALLING;
			}
		}
		*/

	}

	void StarShip::Up() {
		_starShipState = STARSHIP_STATE_FLYING;
	}
	
	const sf::Sprite& StarShip::GetSprite() const {
		return _starship;
	}
}