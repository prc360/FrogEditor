#include "headers/init.h"
#include "headers/file_handler.h"
#include "headers/text_renderer.h"
#include "headers/manage_window.h"

using namespace std;

string sentence = DEFAULT_SYMBOL;
map<int, string> cursorSentenceMap;
int cursor = 0;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event* pollEvent = new SDL_Event;


int SDL_main(int argc, char* argv[]) {
	SDL_LogInfo(0, START_LOG);
	try {
		tie(window, renderer) = createWindowAndRenderer();
		while (1) {
				SDL_PollEvent(pollEvent);

				if ((pollEvent->type == SDL_KEYDOWN && pollEvent->key.repeat == 0)) {
					tie(sentence, renderer, cursor, cursorSentenceMap) = getAndProcessKeyboardInputEvents(pollEvent, 
						sentence, cursorSentenceMap, cursor, renderer);
				}
				if ((pollEvent->type == SDL_QUIT || (pollEvent->type == SDL_KEYDOWN && 
					(SDL_GetModState() & KMOD_SHIFT) && pollEvent->key.keysym.sym == SDLK_TAB))) {
					shutDownApplication(window, renderer);
					break;
				}
			}
		}
	catch(exception) {
		SDL_LogError(0, "main: Could not create a window. %s", SDL_GetError());
		return 1;
	}

	delete pollEvent;
	SDL_LogInfo(0, END_LOG);
	return 0;
}