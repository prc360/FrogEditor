#include "../headers/handle_shift_mod.h"

string handleAndAppendShiftModCharacters(string sentence, SDL_Event* pollEvent) {
	switch (pollEvent->key.keysym.sym) {
	case SDLK_SLASH:
		sentence += SDLK_QUESTION;
		break;
	case SDLK_1:
		sentence += SDLK_EXCLAIM;
		break;
	case SDLK_2:
		sentence += SDLK_AT;
		break;
	case SDLK_3:
		sentence += SDLK_HASH;
		break;
	case SDLK_4:
		sentence += SDLK_DOLLAR;
		break;
	case SDLK_5:
		sentence += SDLK_PERCENT;
		break;
	case SDLK_6:
		sentence += SDLK_CARET;
		break;
	case SDLK_7:
		sentence += SDLK_AMPERSAND;
		break;
	case SDLK_8:
		sentence += SDLK_ASTERISK;
		break;
	case SDLK_9:
		sentence += SDLK_LEFTPAREN;
		break;
	case SDLK_0:
		sentence += SDLK_RIGHTPAREN;
		break;
	case SDLK_MINUS:
		sentence += SDLK_UNDERSCORE;
		break;
	case SDLK_EQUALS:
		sentence += SDLK_PLUS;
		break;
	case SDLK_BACKQUOTE:
		sentence += "~";
		break;
	case SDLK_LEFTBRACKET:
		sentence += "{";
		break;
	case SDLK_RIGHTBRACKET:
		sentence += "}";
		break;
	case SDLK_BACKSLASH:
		sentence += "|";
		break;
	case SDLK_SEMICOLON:
		sentence += SDLK_COLON;
		break;
	case SDLK_QUOTE:
		sentence += SDLK_QUOTEDBL;
		break;
	case SDLK_COMMA:
		sentence += SDLK_LESS;
		break;
	case SDLK_PERIOD:
		sentence += SDLK_GREATER;
		break;
	default:
		sentence += toupper(pollEvent->key.keysym.sym);
		break;
	}
	return sentence;
}