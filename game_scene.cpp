#include "game_scene.h"
#include "zombie1.h"
#include "zombie2.h"

#include "player.h"


Game_Scene::Game_Scene()
	: Scene("Game")
{
	Game_Object* zombie1 = new Zombie1("Zombie1");
	_game_objects[zombie1->id()] = zombie1;

	Game_Object* zombie2 = new Zombie2("Zombie2");
	_game_objects[zombie2->id()] = zombie2;


	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}