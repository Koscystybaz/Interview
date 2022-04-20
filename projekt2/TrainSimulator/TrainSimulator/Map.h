#pragma once

#include "Loop.h"

class Map
{
private:

	SDL_Rect src, dest;
	SDL_Texture* rail, *rail2, *rail3, *rail4, *rail5, *rail6;
	
	SDL_Texture* grass;

	int map[20][25];

public:
		Map();
		~Map();

		void LoadMap(int arr[20][25]);
		void DrawMap();

}; 