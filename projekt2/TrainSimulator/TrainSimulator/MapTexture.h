#pragma once


#include "Loop.h"

class MapTexture
{

private:

	int xpose;
	int ypose;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


public:
	MapTexture(const char* texturesheet, int x, int y);

	~MapTexture();

	//void Uptade();
	void Render();

};
