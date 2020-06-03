#pragma once

#include "game_object.h"

class Zombie2 : public Game_Object
{
public:
	Zombie2(std::string id);
	~Zombie2();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};