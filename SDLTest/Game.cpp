#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

////////////////////////////////////////////////////////////////////////////////

const char *getKey(SDL_Keycode keycode)
{
	return SDL_GetKeyName(keycode);
}

////////////////////////////////////////////////////////////////////////////////

Game::Game(SDL_Window* window, GameConfig config)
	: m_window(window),
	m_config(config),
	m_running(false),
	m_time_since_tick(0)
{
	std::cout << "Hello! Let's start!" << std::endl;
}

Game::~Game()
{
	std::cout << "Thanks bye!" << std::endl;
}

void Game::initialize()
{
	std::cout << "Initialized with config: " << m_config.to_string() << std::endl;

	m_running = true;
}

void Game::update(double delta_time)
{
	m_time_since_tick += delta_time;

	if (m_time_since_tick >= m_config.update_time) {
		m_time_since_tick = 0;

		std::cout << "Tick game" << std::endl;

		setTitle("SDL Test | FPS: " + std::to_string(1000 / delta_time));
	}
}

void Game::handleKeyDown(SDL_KeyboardEvent& key)
{
	m_active_keys.insert(key.keysym.sym);

	switch (key.keysym.sym) {
		case SDLK_LEFT:
			moveBlockLeft();
			break;
		case SDLK_RIGHT:
			moveBlockRight();
			break;
		case SDLK_UP:
			rotateBlock();
			break;
		case SDLK_DOWN:
			moveBlockDown();
			break;
		case SDLK_q:
			stop();
			break;
		default:
			break;
	}
}

void Game::handleKeyUp(SDL_KeyboardEvent& key)
{
	m_active_keys.erase(key.keysym.sym);
}

void Game::stop()
{
	m_running = false;
}

void Game::moveBlockLeft()
{
	std::cout << "Block:Left" << std::endl;
}

void Game::moveBlockRight()
{
	std::cout << "Block:Right" << std::endl;
}

void Game::rotateBlock()
{
	std::cout << "Block:Rotate" << std::endl;
}

void Game::moveBlockDown()
{
	std::cout << "Block:Down" << std::endl;
}

void Game::setTitle(std::string title)
{
	SDL_SetWindowTitle(m_window, title.c_str());
}
