#include "Sky.h"

namespace Sky {

	SkyAI::SkyAI(GameDataRef data) : SpaceRocks(data), StarShip(data), Obstacles(data), _data(data) {}
	SkyAI::~SkyAI() {}

	void SkyAI::Reset() {
		//This is better --> Use the default height and then update it
		sf::Sprite sprite(_data->assets.GetTexture("Obstacle Up Element"));

		gapStart = (_data->window.getSize().y + 70 - sprite.getGlobalBounds().height);
		gapSize = (_data->window.getSize().y + 70 - (sprite.getGlobalBounds().height * 2));

		STpostX = _starship.getGlobalBounds().width + sprite.getGlobalBounds().width - (_starship.getGlobalBounds().width / 2);
		STpostY = gapStart + gapSize - _starship.getGlobalBounds().height;

		fpbdora = false;
		gamma = 1;
		alpha = 0.7;

		_actionSet["STAY"] = 0;
		_actionSet["JUMP"] = 1; 
	}

	void SkyAI::getState() {
		
		//X
		if (_obstacles.size() > 0) {
			if (_starship.getPosition().x <= _obstacles.at(0).getPosition().x) {
				STpostX = _obstacles.at(0).getPosition().x - _starship.getPosition().x;
			}
			else if(_starship.getPosition().x <= _obstacles.at(1).getPosition().x && _starship.getPosition().x > _obstacles.at(0).getPosition().x){
				STpostX = _obstacles.at(1).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(2).getPosition().x && _starship.getPosition().x > _obstacles.at(1).getPosition().x) {
				STpostX = _obstacles.at(2).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(3).getPosition().x && _starship.getPosition().x > _obstacles.at(2).getPosition().x) {
				STpostX = _obstacles.at(3).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(4).getPosition().x && _starship.getPosition().x > _obstacles.at(3).getPosition().x) {
				STpostX = _obstacles.at(4).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(5).getPosition().x && _starship.getPosition().x > _obstacles.at(4).getPosition().x) {
				STpostX = _obstacles.at(5).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(6).getPosition().x && _starship.getPosition().x > _obstacles.at(5).getPosition().x) {
				STpostX = _obstacles.at(6).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(7).getPosition().x && _starship.getPosition().x > _obstacles.at(6).getPosition().x) {
				STpostX = _obstacles.at(7).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(8).getPosition().x && _starship.getPosition().x > _obstacles.at(7).getPosition().x) {
				STpostX = _obstacles.at(8).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(9).getPosition().x && _starship.getPosition().x > _obstacles.at(8).getPosition().x) {
				STpostX = _obstacles.at(9).getPosition().x - _starship.getPosition().x;
			}
			else if (_starship.getPosition().x <= _obstacles.at(10).getPosition().x && _starship.getPosition().x > _obstacles.at(9).getPosition().x) {
				STpostX = _obstacles.at(10).getPosition().x - _starship.getPosition().x;
			}	
		}

		//Y
		if (_obstacles.size() > 0) {
			if (_starship.getPosition().x <= _obstacles.at(0).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 -_obstacles.at(0).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(0).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(1).getPosition().x && _starship.getPosition().x > _obstacles.at(0).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(1).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(1).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(2).getPosition().x && _starship.getPosition().x > _obstacles.at(1).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(2).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(2).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(3).getPosition().x && _starship.getPosition().x > _obstacles.at(2).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(3).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(3).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(4).getPosition().x && _starship.getPosition().x > _obstacles.at(3).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(4).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(4).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(5).getPosition().x && _starship.getPosition().x > _obstacles.at(4).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(5).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(5).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(6).getPosition().x && _starship.getPosition().x > _obstacles.at(5).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(6).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(6).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(7).getPosition().x && _starship.getPosition().x > _obstacles.at(6).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(7).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(7).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(8).getPosition().x && _starship.getPosition().x > _obstacles.at(7).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(8).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(8).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(9).getPosition().x && _starship.getPosition().x > _obstacles.at(8).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(9).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(9).getGlobalBounds().height * 2));
			}
			else if (_starship.getPosition().x <= _obstacles.at(10).getPosition().x && _starship.getPosition().x > _obstacles.at(9).getPosition().x) {
				STpostY = (_data->window.getSize().y + 70 - _obstacles.at(10).getGlobalBounds().width) + (_data->window.getSize().y + 70 - (_obstacles.at(10).getGlobalBounds().height * 2));
			}
		}

		_s[0] = (int)STpostX;
		_s[1] = (int)STpostY;
		_s[2] = mom;

	}

	//This should be in the game state.cpp
	bool SkyAI::implementAction(int a) {
		if (a == 1) {
			return true;
		}
		return false;
	}

	std::vector<int>& SkyAI::getQ(std::vector<float> s, int a) {
		std::vector<float> config;
		std::vector<int> defaultP;

		defaultP[0] = 0;

		config[0] = _s[0];
		config[1] = _s[1];
		config[2] = _s[2];
		config[3] = a;

		for (int i = 0; i < sizeof Q_table; i++) {
			if (config[i] != Q_table[i]) {
				return defaultP;
			}
		}

		return Q_table = {(int)config[0],(int)config[1],(int)config[2],(int)config[3],a}; //Q_table[config]
	}

	std::vector<int>& SkyAI::setQ(std::vector<float> s, int a, std::vector<float> r) {
		std::vector<float> config;
		config[0] = _s[0];
		config[1] = _s[1];
		config[2] = _s[2];
		config[3] = a;

		for (int i = 0; i < sizeof Q_table; i++) {
			if (config[i] != Q_table[i]) {
				return Q_table = {0,0,0,0};
			}
		}

		std::transform(config.begin(), config.end(), r.begin(), r.begin(), std::plus<int>());

		return Q_table = { (int)config[0],(int)config[1],(int)config[2],(int)config[3],a}; //Q_table[config]
		
	}

	int SkyAI::getAction(std::vector<float> s) {
		
		std::vector<int> rewardStay = getQ(s,_actionSet["STAY"]);
		std::vector<int> rewardJump = getQ(s, _actionSet["JUMP"]);

		if (rewardStay > rewardJump) {
			return _actionSet["STAY"];
		}
		else if (rewardStay < rewardJump) {
			return _actionSet["JUMP"];
		}
		else
		{
			return _actionSet["STAY"];
		}
	}

	void SkyAI::reward(std::vector<float> s, int a) {
		int reward = 0;
		std::vector<float> futureState;

		futureState[0] = _s[0];
		futureState[1] = _s[1];
		futureState[2] = _s[2];

		

		if (ControlState::Over) {
			reward = -1000;
		}
		else {
			reward = 1;
		}


		std::vector<int> OptimalFutureValue = std::max(getQ(futureState, _actionSet["STAY"]), getQ(futureState, _actionSet["JUMP"]));
		std::vector<float> UpdateValue;
		UpdateValue[0] = alpha * (reward + gamma * OptimalFutureValue[0]);

		std::transform(UpdateValue.begin(), UpdateValue.end(), getQ(s,a).begin(), getQ(s, a).begin(), std::minus<int>());

		setQ(s, a, UpdateValue);
	}

	int SkyAI::Play() {
		bool actionJump;
		getState();
		int action = getAction(_s);
		implementAction(action);
		reward(_s, action);

		if (ControlState::Start) {
			getState();
			action = getAction(_s);
			actionJump = implementAction(action);
			if (actionJump == true) {
				return 1;
			}
			
		}
		else {
			return 0;
		}
	}

}