#pragma once
#include "init.h"
#include <map>

using namespace std;

pair<SDL_Window*, SDL_Renderer*> createWindowAndRenderer();
void shutDownApplication(SDL_Window*, SDL_Renderer*);