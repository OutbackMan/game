#include "rgame.h"
#include "common.h"
#include "status-codes.h"
#include "debug.h"
#include <stdbool.h>

rgame_status_t rgame_init(const char title[restrict static 1], int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* restrict rgame_instance)
{
    // Check parameters
    if (rgame_instance == NULL) {
        rgame_error("Null argument passed to callee which requires a non-null argument");
        return RGAME_ERROR;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        rgame_sdl_error(SDL_GetError());
        return RGAME_SDL_ERROR;
    }
    
    rgame_log("SDL subsystems successfully initialised");
    
    int window_flags = 0;
    
    if (want_fullscreen) {
        window_flags = SDL_WINDOW_FULLSCREEN;
    }
    
    rgame_instance->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, window_flags);
    
    if (rgame_instance->window == 0) {
        // Handle error
    }
    
    rgame_log("SDL window created");
    
    rgame_instance->renderer = SDL_CreateRenderer(rgame->window, -1, 0);
    
    if (rgame_instance->renderer == 0) {
        // Handle error
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
