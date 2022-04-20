#include "Loop.h"

Loop* loop = nullptr;


int main(int argc, char* args[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	loop = new Loop();
	loop->Init("Train SImulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, false);

	while (loop->Running()) {

		frameStart = SDL_GetTicks();

		loop->HandleEvents();
		loop->Uptade();
		loop->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	loop->Clean();




	/*SDL_Init(SDL_INIT_EVERYTHING);
	std::cout<< "Hello world";
	*/

	/*SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("Train SImulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, 1, 0);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderClear(renderer);
	
	SDL_RenderPresent(renderer);

	SDL_Delay(3000); */


	return 0;
	

}