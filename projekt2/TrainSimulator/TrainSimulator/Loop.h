#pragma once

#include <stdio.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Loop {

private:

	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	


public:
	Loop();
	~Loop();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void HandleEvents();
	void Uptade();
	void Render();
	void Clean();
	bool Running() { return isRunning; };
	
	static SDL_Renderer* renderer;
};