#pragma once

#include <iostream>
#include <string>
#include <set>
#include <SDL.h>

////////////////////////////////////////////////////////////////////////////////

const char *getKey(SDL_Keycode keycode);

////////////////////////////////////////////////////////////////////////////////

// Tetris
//
// Always keep a small queue of blocks. One block is always falling. If no blocks
// are falling, spawn a new one.
// 
// * Game initialize:
//   * Initialize map (e.g. 20x60 tiles)
//   * Initialize block queue (e.g. 4 blocks)
// * Game update:
//   * If no block is falling:
//     * Dequeue first block and spawn new block to queue
//	 * Update falling block position (move 1 tile down)
//   * For all full rows:
//     * Explode row and give points
//     * Move all above (floating) blocks down
// * Key down (Left/Right):
//   * Move falling block once left/right
// * Key down (Up):
//   * Rotate falling block once
// * Key down (Down):
//   * Move falling block once down
struct GameConfig {
	unsigned int map_width;
	unsigned int map_height;
	double update_time;		// TODO: Use progression to make the game speed up

	std::string to_string()
	{
		return "map_width: " + std::to_string(map_width) + ", " +
			"map_height: " + std::to_string(map_height) + ", " +
			"update_time: " + std::to_string(update_time);
	}
};

class Game
{
private:
	bool m_running;
	GameConfig m_config;
	std::set<SDL_Keycode> m_active_keys;

	void moveBlockLeft();
	void moveBlockRight();
	void rotateBlock();
	void moveBlockDown();

public:

	Game(GameConfig config);
	~Game();

	void initialize();
	void update(double delta_time);
	void handleKeyDown(SDL_KeyboardEvent& key);
	void handleKeyUp(SDL_KeyboardEvent& key);
	void stop();

	[[nodiscard]] std::set<SDL_Keycode> get_active_keys() { return m_active_keys; };
	[[nodiscard]] bool isRunning() { return m_running; };
};
