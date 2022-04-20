#include "MapTexture.h"
#include "TextureManager.h"

MapTexture::MapTexture(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	
	xpose = x;
	ypose = y;

	//xpose = 0;
	//ypose = 0;
	

	srcRect.h = 512;
	srcRect.w = 512;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = 512;
	destRect.w = 512;
	destRect.x = 0;
	destRect.y = 0;
}

MapTexture::~MapTexture()
{

}

//void MapTexture::Uptade()
//{
//	//xpose++;
//	//ypose++;
//
//
//	//srcRect.h = 32;
//	//srcRect.w = 32;
//	//srcRect.x = 0;
//	//srcRect.y = 0;
//
//	//destRect.x = xpose;
//	//destRect.y = ypose;
//	//destRect.w = srcRect.w * 2;
//	//destRect.h = srcRect.h * 2;
//
//}

void MapTexture::Render()
{
	SDL_RenderCopy(Loop::renderer, objTexture, &srcRect, &destRect);
}
