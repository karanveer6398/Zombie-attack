#include "assets.h"
#include "texture.h"
#include "animated_texture.h"
#include "sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{

	// Create zombie1 walking texture.

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;


		Asset* animated_texture = new Animated_Texture("Texture.zombie1.walking", "Assets/zombie1.walking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;

		
		
	}

	// Create Bullet entry texture.
	{
		const int frame_count = 5;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* animated_texture = new Animated_Texture("Texture.Bullet", "Assets/bullet.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[animated_texture->id()] = animated_texture;
	}


	//Create zombie2 walking texture 

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* texture = new Animated_Texture(
			"Texture.zombie2.walking",
			"Assets/zombie2.walking.png",
			renderer,
			frame_count,
			frame_duration_milliseconds);
		_assets[texture->id()] = texture;
	}

	// Zombie1 Texture.
	{
		Texture* texture = new Texture("Texture.Zombie1", "Assets/zombie1.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Zombie2 Texture.
	{
		Texture* texture = new Texture("Texture.Zombie2", "Assets/zombie2.png", renderer);
		_assets[texture->id()] = texture;
	}

	// Create player walking texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Walking", "Assets/player.walking.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player running texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Running", "Assets/player.running.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	// Create player idle texture.
	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 50;
		Asset* player_animated_texture = new Animated_Texture("Texture.Player.Idle", "Assets/player.idle.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}


	//  music sound
	{
		Sound* sound = new Sound("Sound.Music", "Assets/music.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	//  walking sound player
	{
		Sound* sound = new Sound("Sound.Walking", "Assets/walking.wav");
		_assets[sound->id()] = sound;
	}

	//  running sound player
	{
		Sound* sound = new Sound("Sound.Running", "Assets/running.wav");
		_assets[sound->id()] = sound;
	}



}

Assets::~Assets()
{

}

Asset* Assets::get_asset(std::string id)
{
	if (_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. ID: " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}