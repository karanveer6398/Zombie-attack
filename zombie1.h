#pragma once

#include "game_object.h"

class Zombie1 : public Game_Object
{
public:
	Zombie1(std::string id);
	~Zombie1();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};