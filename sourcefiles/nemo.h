/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef NEMO_H
#define NEMO_H

#include "anemone.h"
#include "library.h"
#include "Vec2.h"

class Nemo
{
public:
	Nemo(Math::vec2 position, enum LightColors color);
	~Nemo();

	Math::vec2 getposition() { return position; }

	void move(double dt, Math::vec2 player_position, enum LightColors lightcolor, std::vector<Anemone*>* anemones);
	void search_anemone(std::vector<Anemone*>* anemones);
	void update(double dt, Math::vec2 player_position, enum LightColors lightcolor, std::vector<Anemone*>*anemones);
	void draw();


private:
	Math::vec2 position = { 0, 0 };

	static constexpr int max_speed = 450;
	static constexpr int min_brake_speed = 10;
	static constexpr int acceleration = 12;
	static constexpr int brake_margin = 80;
	static constexpr int anemone_range = 100;
	Math::vec2 velocity = { 0, 0 };

	static constexpr int size = 20;

	enum LightColors color = BLUE;
	doodle::Color doodlecolor;

	bool found_anemone = false;
	int anemone_number;

	bool should_update = true;

};

#endif
