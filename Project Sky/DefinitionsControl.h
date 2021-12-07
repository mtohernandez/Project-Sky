#pragma once

#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800

#define SPLASH_STATE_SHOW_TIME 3.0

//Change directories

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Elements/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Elements/sky.png"
#define GAME_BACKGROUND_FILEPATH "Elements/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Elements/sky.png"

#define GAME_TITLE_FILEPATH "Elements/title.png"
#define PLAY_BUTTON_FILEPATH "Elements/PlayButton.png"

#define OBSTACLES_UP_FILEPATH "Elements/Obstacle-Up.png"
#define OBSTACLES_DOWN_FILEPATH "Elements/Obstacle-Down.png"

//Testing

extern float OBSTACLE_MOVEMENT_SPEED;
extern float OBSTACLE_SPAWN_SPEED;
extern int JUMP_COUNT;

#define RANDOM_VARIATION 2

#define SPACE_ROCKS "Elements/land.png"


#define STARSHIP_FRAME_1_FILE "Elements/Starship-01.png"
#define STARSHIP_FRAME_2_FILE "Elements/Starship-02.png"
#define STARSHIP_FRAME_3_FILE "Elements/Starship-03.png"
#define STARSHIP_FRAME_4_FILE "Elements/Starship-04.png"
#define STARSHIP_FRAME_EXPLOSION "Elements/Starship-Explosion.png"

#define PLAYBUTTON_FRAME_1_FILE "Elements/title-01.png"
#define PLAYBUTTON_FRAME_2_FILE "Elements/title-02.png"
#define PLAYBUTTON_FRAME_3_FILE "Elements/title-03.png"
#define PLAYBUTTON_FRAME_4_FILE "Elements/title-04.png"
#define PLAYBUTTON_FRAME_5_FILE "Elements/title-05.png"

#define DETECTION_OBSTACLE "Elements/DetectionObstacle.png"

#define STARSHIP_ANIMATION_CONTROL 0.4f
#define PLAYBUTTON_ANIMATION_CONTROL 0.4f


#define STARSHIP_STATE_STILL 1
#define STARSHIP_STATE_FALLING 2 
#define STARSHIP_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 200.0f
extern int STARSHIP_MASS;

#define FLYING_DURATION 0.2f

enum ControlState {
	Start,
	Over
};

#define SCORE_FONT "Elements/Score Font.ttf"

#define HIGH_SCORE "Elements/Scores.txt"
