#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

////////////////////////////////////////////////////////////////////////////////

const char *getKey(SDL_Keycode keycode)
{
	return SDL_GetKeyName(keycode);
}

////////////////////////////////////////////////////////////////////////////////

Game::Game() : m_running(false)
{
	std::cout << "Hello! Let's start!" << std::endl;
}

void Game::initialize()
{
	std::cout << "Initialized!" << std::endl;

	m_running = true;
}

Game::~Game()
{
	std::cout << "Thanks bye!" << std::endl;
}

void Game::update(double deltaTime)
{
	std::cout << "Updated (dt:" << deltaTime << " ms)" << std::endl;
}

void Game::handleKeyDown(SDL_KeyboardEvent& key)
{
	std::cout << "Key ("<< getKey(key.keysym.sym) <<") was pressed." << std::endl;

	activeKeys.insert(key.keysym.sym);
}

void Game::handleKeyUp(SDL_KeyboardEvent& key)
{
	std::cout << "Key ("<< getKey(key.keysym.sym) <<") was released." << std::endl;

	activeKeys.erase(key.keysym.sym);
}

void Game::stop()
{
	m_running = false;
}
