#include "Loop.h"
#include "TextureManager.h"
#include "AppObj.h"
#include "Map.h"
#include "MapTexture.h"


AppObj* player;

MapTexture* map;

SDL_Renderer* Loop::renderer = nullptr;

Loop::Loop()
{

}

Loop::~Loop()
{

}

void Loop::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Start" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else isRunning = false;
	
	map = new MapTexture("assets/map.png", 0, 0);
	player = new AppObj("assets/x.png", 0, 0);
	map->Render();
}

void Loop::HandleEvents()
{
	int xMouse, yMouse;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_GetGlobalMouseState(&xMouse, &yMouse);
			std::cout << "X: " << xMouse <<" Y: " << yMouse <<  std::endl;
			break;

		default:
			break;
	}
}

void Loop::Uptade()
{
	//cnt++;
	//std::cout << cnt << std::endl;
	player->Uptade();
}

void Loop::Render()
{
	SDL_RenderClear(renderer);
	map->Render();
	player->Render();
	SDL_RenderPresent(renderer);
}

void Loop::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Loop cleaned" << std::endl;
}

