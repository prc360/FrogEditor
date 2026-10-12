#include "../headers/init.h"

int initAll() {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	return 0;
}