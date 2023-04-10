/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef GAME_H
#define GAME_H

#include "title.h"
#include "stage0.h"
#include "stage1.h"

#include "Input.h"
#include "library.h"
#include "player.h"
#include "nemo.h"
#include "anemone.h"
#include "wall.h"

class Game {
public:
	Game();
	~Game();
	void initialize(int stage_no);
	static Game& instance() {
		static Game instance;
		return instance;
	}
	void update();
	void draw();

	static CS230::Input& get_input() { return instance().input; }

private:
	CS230::Input input;
	bool title_on = true;
	int current_stage = 0;
	bool did_initialize = false;
	Title* title = new Title();
	Stage0* stage0 = new Stage0();
	Stage1* stage1 = new Stage1();

};

#endif