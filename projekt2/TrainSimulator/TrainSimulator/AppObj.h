#pragma once

#include "Loop.h"

class AppObj
{

private:

	int xpose;
	int ypose;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	

public:
	AppObj(const char* texturesheet, int x, int y);

	~AppObj();

	void Uptade();
	void Render();

};

