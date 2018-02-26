#include "rgame.h"
#include "common.h"
#include "status-codes.h"
#include <stdbool.h>

rgame_status_t rgame_init(const char title[restrict static 1], int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* rgame_instance[static 1])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return RGAME_STATUS(RGAME_SDL_ERROR);
    }
    
    RGAME_LOG("SDL subsystems successfully initialised");
    
    int window_flags = 0;
    
    if (want_fullscreen) {
        window_flags = SDL_WINDOW_FULLSCREEN;
    }
    
    rgame_instance->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, window_flags);
    
    if (rgame_instance->window == NULL) {
        return RGAME_STATUS(RGAME_SDL_ERROR);
    }
    
    RGAME_LOG("SDL window created");
    
    rgame_instance->renderer = SDL_CreateRenderer(rgame->window, -1, 0);
    
    if (rgame_instance->renderer == NULL) {
        return RGAME_STATUS(RGAME_SDL_ERROR);
    }
    
    RGAME_LOG("SDL renderer created");
    
    rgame_instance->is_running = true;
    
    return RGAME_STATUS(RGAME_SUCCESS);
}

void rgame_handle_events(const struct RGame rgame_instance[restrict static 1])
{
    SDL_Event event = {0};
    
	if (SDL_Poll(&event) == 1) {
    
		switch (event.type) {
			case SDL_QUIT:
				rgame_instance->is_running = false;
				break;
			default:
				break;
		}
	}
}

void rgame_update();

const rgame_status_t rgame_render(const struct RGame* rgame_instance[restrict static 1])
{
    if (SDL_RenderClear(rgame_instance->renderer) < 0) {
		return RGAME_STATUS(RGAME_SDL_ERROR);
	}

    SDL_RenderPresent(rgame_instance->renderer);
    
    return RGAME_STATUS(RGAME_SUCCESS);
}

void rgame_clean();

bool rgame_is_running(const struct RGame* restrict rgame)
{
    return rgame->is_running;
}
