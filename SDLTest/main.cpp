#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{
	SDL_Window* window = nullptr;
	SDL_Surface* imgSurface = nullptr;
	SDL_Surface* windowSurface = nullptr;

	// init SDL2
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	// create the window
	window = SDL_CreateWindow(
		"SDL Test",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_ALLOW_HIGHDPI
	);

	// get the surface of the window we just created
	windowSurface = SDL_GetWindowSurface(window);
		
	if (window == NULL)
	{
		std::cout << "Window creation error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	// init SDL_image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "Could not init SDL_image for PNG: " << IMG_GetError() << std::endl;
	}


	// Start doing stuff...

	imgSurface = IMG_Load("sample_image.bmp");
	if (imgSurface == NULL)
	{
		std::cout << "Could not load the sample image: "<< SDL_GetError() << std::endl;
	}

	// the Game
	Game game = Game();
	game.initialize();

	SDL_Event event;

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	double deltaTime = 0;

	while (game.isRunning())
	{
		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());

		game.update(deltaTime);

		// if there are events pending...
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN: {
					game.handleKeyDown(event.key);
					break;
				}
				case SDL_KEYUP: {
					game.handleKeyUp(event.key);
					break;
				}
				case SDL_QUIT: {
					game.stop();
					break;
				}
				default:
					break;
			}

			std::cout << "Active keys: " << std::endl;
			for (auto key : game.activeKeys)
			{
				std::cout << getKey(key) << ", ";
			}
			std::cout << std::endl;
		}

		SDL_BlitSurface(imgSurface, NULL, windowSurface, NULL);
		SDL_UpdateWindowSurface(window);
	}

	// Before exiting, let's clean up our resources.
	SDL_FreeSurface(imgSurface);
	SDL_FreeSurface(windowSurface);

	windowSurface = nullptr;
	imgSurface = nullptr;

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
