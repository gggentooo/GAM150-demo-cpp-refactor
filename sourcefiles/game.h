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
#include "library.h"
#include "player.h"
#include "nemo.h"
#include "anemone.h"
#include "wall.h"
#include "../mapdata/Points0.h"

class Game {
public:
	Game();
	~Game();
	static Game& instance() {
		static Game instance;
		return instance;
	}

	Player* player = new Player({ 300, 100 });
	Light* light = new Light({300, 100});
	CS230::Input input;
	Points0 points0;
	std::vector<Nemo*> nemos;
	std::vector<Anemone*> anemones;
	std::vector<Wall*> walls;

	static Player& get_player() { return *instance().player; }
	static Light& get_light() { return *instance().light; }
	static Points0& get_points0() { return instance().points0; }
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