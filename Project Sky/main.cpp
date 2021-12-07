#include "GameControl.h"
#include "DefinitionsControl.h"

float OBSTACLE_MOVEMENT_SPEED = 100.0f;
float OBSTACLE_SPAWN_SPEED = 1.5f;
int STARSHIP_MASS = 0.1;
int JUMP_COUNT = 10;

int main()
{
	Sky::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Sky");

	return EXIT_SUCCESS;
}