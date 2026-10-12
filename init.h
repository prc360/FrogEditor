#pragma once

#define main_predef main
#include "SDL.h"
#include "SDL_main.h"
#include "SDL_log.h"
#include "SDL_video.h"
#include "SDL_ttf.h"

#define SDL_MAIN_HANDLED
#define SDL_TTF_HANDLED
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 500

#define FONT_SIZE 16
#define FONT_NAME "OpenSans-Regular.ttf"
#define TEXTCOLOR { 255, 255, 255 }

#define START_LOG "main: Hello World! Running an application FrogEditor..."
#define END_LOG "main: Application Exit successfully"

#define DEFAULT_SYMBOL ">"

#define APPLICATION_NAME "FrogEditor"


int initAll();