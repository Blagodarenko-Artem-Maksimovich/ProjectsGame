#include <iostream>
#include "visual.h"
#include <random>
#include <algorithm> 

class Game {
public:
	int width = 1080, height = 1920;
	int scene_menu = 0,
		scene_game = 1,
		scene_gameover = 2,
		scene_pause = 3,
		current_scene_index = scene_menu;
	bool game_over;
	Game ();

	int random();

	void main_loop();

	bool mainmenu();
	
	bool gameovermenu();
};



