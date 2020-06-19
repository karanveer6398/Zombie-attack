#pragma once

#include "bullet.h"
#include "scene.h"
#include "zombie1.h"
#include "zombie2.h"



Bullet::Bullet()
	: Game_Object("Bullet", "Texture.Bullet")
{
	_width  = 50;
	_height = 50;
	_translation = Vector_2D(0, 0);
}

Bullet::~Bullet()
{

}
void Bullet::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Bullet::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{

	Game_Object* player = scene->get_game_object("Player");
	
	Vector_2D portal_center = _translation
		+ Vector_2D((float)_width / 2, (float)_height / 2);
	Vector_2D player_center = player->translation()
		+ Vector_2D((float)player->width() / 2, (float)player->height() / 2);

	float distance_to_player = (portal_center - player_center).magnitude();

	if (distance_to_player < 50.0f)
	{
		Game_Object* Zombie1 = scene->get_game_object("Zombie1");
		Vector_2D exit_location = Zombie1->translation()
			+ Vector_2D(100.f, 0.f);

		player->set_translation(exit_location);
	}
	else if
		(distance_to_player > 50.0f)
	{
		Game_Object* Zombie2 = scene->get_game_object("Zombie2");
		Vector_2D exit_location = Zombie2->translation()
			+ Vector_2D(100.f, 0.f);

		player->set_translation(exit_location);
	}

}