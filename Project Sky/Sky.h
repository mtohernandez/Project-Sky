#pragma once

#include "SpaceRocks.h"
#include "StarShip.h"
#include "GameControl.h"
#include "Obstacles.h"
#include <map>

namespace Sky {
	class SkyAI: public SpaceRocks, public StarShip, public Obstacles
	{
	public:
		SkyAI(GameDataRef data);
		~SkyAI();

		void Reset();
		void getState();
		bool implementAction(int a);
		std::vector<int>& getQ(std::vector<float> s, int a);
		std::vector<int>& setQ(std::vector<float> s, int a,std::vector<float> r);
		int getAction(std::vector<float> s);
		void reward(std::vector<float> s, int a);
		int Play();

	
	private:
		GameDataRef _data;
		
		//Halp variables
		float gapStart, gapSize;

		std::vector<int> Q_table = {0,0,0,0};

		int a;
		int mom = 0;

		bool fpbdora;
		int gamma;
		float alpha;
		float STpostX, STpostY;

		std::map<std::string, char> _actionSet;
		std::vector<float> _s;
	};
}


