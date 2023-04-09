/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef GAME_H
#define GAME_H

#include "stage0.h"
#include "stage1.h"
#include "Input.h"

class Game {
public:
	Game();
	~Game();
	static Game& instance() {
		static Game instance;
		return instance;
	}
	static CS230::Input& get_input() { return instance().input; }
	void initialize();
	void update();
	void draw();

private:
	CS230::Input input;
	int currentstage = 0;
	Stage0* stage0 = new Stage0();
	//Stage1* stage1 = new Stage1();

};

#endif