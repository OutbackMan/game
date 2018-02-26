#include "rgame.h"
#include "common.h"
#include "status-codes.h"
#include <stdbool.h>

rgame_status_t rgame_init(const char title[restrict static 1], int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* restrict rgame_instance)
{
    if (rgame_instance == NULL) {
        return rgame_status_null_argument(__FILE__, __func__, __LINE__);
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return rgame_status_sdl_error(__FILE__, __func__, __LINE__);
    }
    
    rgame_log("SDL subsystems successfully initialised");
    
    int window_flags = 0;
    
    if (want_fullscreen) {
        window_flags = SDL_WINDOW_FULLSCREEN;
    }
    
    rgame_instance->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, window_flags);
    
    if (rgame_instance->window == NULL) {
        rgame_sdl_error(SDL_GetError());
        return RGAME_SDL_ERROR;
    }
    
    rgame_log("SDL window created");
    
    rgame_instance->renderer = SDL_CreateRenderer(rgame->window, -1, 0);
    
    if (rgame_instance->renderer == NULL) {
        rgame_sdl_error(SDL_GetError());
        return RGAME_SDL_ERROR;
    }
    
    rgame_log("SDL renderer created");
    
    rgame_instance->is_running = true;
    
    return RGAME_SUCCESS;
}

void rgame_handle_events()
void rgame_update();
void rgame_render();
void rgame_clean();

bool rgame_is_running(const struct RGame* restrict rgame)
{
    return rgame->is_running;
}
