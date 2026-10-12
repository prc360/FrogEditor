#include "headers/manage_window.h"

pair<SDL_Window*, SDL_Renderer*> createWindowAndRenderer() {
	initAll();
	SDL_Window* window = SDL_CreateWindow(APPLICATION_NAME,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	if (!window)
		SDL_LogError(0, SDL_GetError());
	SDL_LogInfo(0, "main: Created a Window successfully!");
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
		SDL_LogError(0, "main: %s", SDL_GetError());

	return make_pair(window, renderer);
}

void shutDownApplication(SDL_Window* window, SDL_Renderer* renderer) {
	SDL_LogInfo(0, "main: Quitting application %s", APPLICATION_NAME);
	SDL_LogWarn(0, "main: Destroying renderer");
	SDL_DestroyRenderer(renderer);
	SDL_LogWarn(0, "main: Destroying Window surface");
	SDL_DestroyWindowSurface(window);
	SDL_LogWarn(0, "main: Destroying Window");
	SDL_DestroyWindow(window);
}