#include "../headers/text_renderer.h"
#include "../headers/file_handler.h"
#include "../headers/handle_shift_mod.h"

using namespace std;

SDL_Surface* makeText(const char* message) {
	SDL_Surface* textSurface = NULL;
	SDL_Color textColor = TEXTCOLOR;
	TTF_Font* font = TTF_OpenFont(FONT_NAME, FONT_SIZE);
	textSurface = TTF_RenderText_Solid(font, message, textColor);
	if (!textSurface) {
		SDL_LogError(0, "makeText: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_LogInfo(0, "makeText: Text Surface created!");
	return textSurface;
}

SDL_Rect createTextSurfaceRectangle(SDL_Surface* textSurface, int carriageReturn) {
	SDL_Rect texture_rect;
	texture_rect.x = 0; //the x coordinate
	texture_rect.y = textSurface->h * carriageReturn;
	texture_rect.w = textSurface->w; //the width of the texture
	texture_rect.h = textSurface->h; //the height of the texture
	return texture_rect;
}

void updateRenderer(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect textSurfaceRect) {
	try {
		SDL_RenderClear(renderer); //clears the renderer
		SDL_RenderCopy(renderer, texture, NULL, &textSurfaceRect);
		SDL_RenderPresent(renderer); //updates the renderer
		SDL_LogInfo(0, "updateRenderer: Renderer updated!");
	}
	catch (exception) {
		SDL_LogError(0, "updateRenderer: %s", SDL_GetError());
	}

	return;
}

void updateTextOnScreen(const char* sentence, SDL_Renderer* renderer, int carriageReturn, map<int, string> cursorSentenceMap) {


	if (cursorSentenceMap.empty()) {
		SDL_Surface* surface = makeText(sentence);
		SDL_Rect rectangle = createTextSurfaceRectangle(surface, carriageReturn);
		SDL_Texture* textureNew = SDL_CreateTextureFromSurface(renderer, surface);
		updateRenderer(renderer, textureNew, rectangle);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(textureNew);
	}
	else {
		map<int, string>::iterator it;
		int cursorCopy = carriageReturn;
		SDL_RenderClear(renderer);
		for (it = cursorSentenceMap.begin(); it != cursorSentenceMap.end(); it++) {
			SDL_Surface* oldSurface = makeText(it->second.c_str());
			SDL_Rect srcRectangle = createTextSurfaceRectangle(oldSurface, it->first);
			SDL_Texture* oldTexture = SDL_CreateTextureFromSurface(renderer, oldSurface);
			SDL_RenderCopy(renderer, oldTexture, NULL, &srcRectangle);
			cursorCopy = it->first;
			SDL_FreeSurface(oldSurface);
			SDL_DestroyTexture(oldTexture);
		}
		SDL_Surface* newSurface = makeText(sentence);
		SDL_Rect destRectangle = createTextSurfaceRectangle(newSurface, cursorCopy + 1);
		SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, newSurface);
		SDL_RenderCopy(renderer, newTexture, NULL, &destRectangle);
		SDL_RenderPresent(renderer);
		SDL_FreeSurface(newSurface);
		SDL_DestroyTexture(newTexture);
	}
}

bool checkForTypableCharacters(SDL_Event* pollEvent) {
	return (pollEvent->type == SDL_KEYDOWN && pollEvent->key.repeat == 0 && !(pollEvent->key.keysym.sym == SDLK_BACKSPACE ||
		pollEvent->key.keysym.sym == SDLK_RETURN || pollEvent->key.keysym.sym == SDLK_LSHIFT ||
		pollEvent->key.keysym.sym == SDLK_RSHIFT));
}

tuple<string, SDL_Renderer*, int, map<int, string>> getAndProcessKeyboardInputEvents(SDL_Event* pollEvent,
	string sentence, map<int, string> cursorSentenceMap, int cursor, SDL_Renderer* renderer) {

	if (checkForTypableCharacters(pollEvent)) {
		SDL_Keymod modstate = SDL_GetModState();
		if (modstate & KMOD_SHIFT) {
			SDL_LogInfo(0, "main: shift key is pressed");
			sentence = handleAndAppendShiftModCharacters(sentence, pollEvent);
		}
		else if (modstate & KMOD_CTRL) {
			if (pollEvent->key.keysym.sym == 's') {
				writeToFile(cursorSentenceMap);
			}
			else if (pollEvent->key.keysym.sym == 'o') {
				tie(cursorSentenceMap, cursor) = readFromFile();
			}
		}
		else
			sentence += pollEvent->key.keysym.sym;

		updateTextOnScreen(sentence.c_str(), renderer, cursor, cursorSentenceMap);
	}

	if ((pollEvent->key.keysym.sym == SDLK_BACKSPACE)) {
		if (sentence.size() == 1) {
			sentence = DEFAULT_SYMBOL;
		}
		else
			sentence.pop_back();

		updateTextOnScreen(sentence.c_str(), renderer, cursor, cursorSentenceMap);
	}

	if ((pollEvent->key.keysym.sym == SDLK_RETURN)) {
		cursorSentenceMap.insert(pair<int, string>(cursor, sentence));
		sentence = DEFAULT_SYMBOL;
		updateTextOnScreen(sentence.c_str(), renderer, cursor, cursorSentenceMap);
		cursor += 1;
	}

	return make_tuple(sentence, renderer, cursor, cursorSentenceMap);
}