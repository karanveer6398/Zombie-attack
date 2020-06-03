#pragma once

#include "zombie2.h"

Zombie2::Zombie2(std::string id)
	: Game_Object(id, "Texture.Zombie2")
{
	// _x = 50;
	// _y = 50;
	_translation = Vector_2D(450, 50);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Zombie2::~Zombie2()
{
}
void Zombie2::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
