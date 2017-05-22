#include <iostream>
#include "SDL2/SDL.h"

int main() {
	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL init error! Code: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	// Create window
	SDL_Window *w = SDL_CreateWindow("Hello world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	// Check if window is created
	if (w == nullptr) {
		std::cout << "SDL error while creating window! Code: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	// Create renderer and check it
 	SDL_Renderer *ren = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		std::cout << "SDL error while creating renderer! Code: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	// Load bitmap
	SDL_Surface *bmp = SDL_LoadBMP("images/sense.bmp");
	if (bmp == nullptr) {
		std::cout << "Can't load sense.bmp! Code: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	// Create texture from surface
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr) {
		std::cout << "SDL error while creating texture from bitmap! Code: " << SDL_GetError() << std::endl;
		return 0;
	}
	
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);
	
	SDL_Delay(3000);
	
	// Clean after work
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(w);
	SDL_Quit();
}
