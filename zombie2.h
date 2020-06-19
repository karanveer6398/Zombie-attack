#pragma once


#include "game_object.h"

#include <time.h>
#include <random>

class Zombie2 : public Game_Object
{
public:
	Zombie2(std::string id);
	~Zombie2();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;


private:
	Animated_Texture* _texture;
	int _change_direction_timer;
	std::minstd_rand0 _generator;
	int _time_until_spawn_projectile;
};