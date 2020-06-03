#pragma once

#include "zombie1.h"

Zombie1::Zombie1(std::string id)
	: Game_Object(id, "Texture.Zombie1")
{
	// _x = 250;
	// _y = 450;
	_translation = Vector_2D(150, 150);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Zombie1::~Zombie1()
{
}
void Zombie1::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
