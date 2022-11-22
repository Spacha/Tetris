#pragma once

#include <iostream>
#include <set>

#include <SDL.h>

////////////////////////////////////////////////////////////////////////////////

const char *getKey(SDL_Keycode keycode);

////////////////////////////////////////////////////////////////////////////////

class Game
{
private:
	bool m_running;

public:
	std::set<SDL_Keycode> activeKeys;

	Game();
	~Game();

	void initialize();
	void update(double deltaTime);
	void handleKeyDown(SDL_KeyboardEvent& key);
	void handleKeyUp(SDL_KeyboardEvent& key);
	void stop();

	[[nodiscard]] bool isRunning() { return m_running; };
};
