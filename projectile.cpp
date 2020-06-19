#pragma once

#include "projectile.h"
#include <iostream>

Projectile::Projectile(std::string id)
	: Game_Object(id, "Texture.Bullet")
	
{
	_width = 50;
	_height = 50;

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
}
Projectile::~Projectile()
{
}
void Projectile::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{
	if(_translation.x() < -100.f || _translation.x() > 1200.f || _translation.y() < -100.f || _translation.y() > 1200.f)
	{
		scene->remove_game_object(id());
		std::cout << "Destroyed " << id() << std::endl;
	}
}
