#ifndef __rgame_h__
#define __rgame_h__

#include "status-codes.h"
#include <stdbool.h>
#include <SDL2/SDL.h>

struct RGame {
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

rgame_status_t rgame_init(const char* title, int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* rgame);
void rgame_event_handle();
void rgame_update();
void rgame_render();
void rgame_clean();
bool rgame_is_running();



#endif
