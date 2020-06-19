#pragma once

#include "zombie2.h"
#include <iostream>
#include "projectile.h"
#include <ctime>



Zombie2::Zombie2(std::string id)
	: Game_Object("zombie2.walking", "Texture.zombie2.walking"),
	_generator(1337)
{
	_translation = Vector_2D(800, 50);
	_velocity = Vector_2D(0.01f, 0);
	_change_direction_timer = 800;
	_time_until_spawn_projectile = 1000;
}
Zombie2::~Zombie2()
{
}

void Zombie2::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config);
}

void Zombie2::simulate_AI(Uint32 milliseconds_to_simulate, Assets*, Input*, Scene* scene)
{
	_change_direction_timer -= milliseconds_to_simulate;
	_time_until_spawn_projectile -= milliseconds_to_simulate;


	if (_change_direction_timer <= 0 && _time_until_spawn_projectile <= 0)
	{
		Projectile* projectile = new Projectile("Projectile.Time." + std::to_string(time(0)));
		Game_Object* player = scene->get_game_object("Player");

		Vector_2D this_to_player = player->translation() - _translation;
		this_to_player.normalize();
		this_to_player.scale(0.5);

		projectile->set_translation(_translation);

		projectile->set_velocity(this_to_player);

		scene->add_game_object(projectile);

		float random_x = ((float)_generator() / _generator.max()) * 2 - 1;
		float random_y = ((float)_generator() / _generator.max()) * 2 - 1;

		Vector_2D random_vector = Vector_2D(random_x, random_y);
		random_vector.normalize();
		random_vector.scale(0.01f);




		_velocity += random_vector;
		_velocity.normalize();
		_velocity.scale(0.01f);



		_time_until_spawn_projectile = 1000;

		_change_direction_timer = 800;





	}
}














