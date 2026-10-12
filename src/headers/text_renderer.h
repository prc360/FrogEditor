#pragma once
#include <cstdlib>
#include <iostream>
#include "init.h"
#include <map>

using namespace std;

SDL_Surface* makeText(const char*);
SDL_Rect createTextSurfaceRectangle(SDL_Surface*, int);
void updateRenderer(SDL_Renderer*, SDL_Texture*, SDL_Rect);
void updateTextOnScreen(const char*, SDL_Renderer*, int, map<int, string>);
bool checkForTypableCharacters(SDL_Event*);
tuple<string, SDL_Renderer*, int, map<int, string>> getAndProcessKeyboardInputEvents(SDL_Event*,
	string, map<int, string>, int, SDL_Renderer*);