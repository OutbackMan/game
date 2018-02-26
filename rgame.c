#include "rgame.h"
#include "status-codes.h"
#include <stdbool.h>

// __STDC_VERSION__ == 201112L
rgame_status_t rgame_init(const char title[restrict static 1], int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* restrict rgame)
{
    // Check parameters
    if (rgame == NULL) {
        debug_error("Null argument passed to callee which requires a non-null argument."); // Log error with context
        return RGAME_ERROR;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        // Handle error: printf("%s", SDL_GetError());
        return RGAME_SDL_ERROR;
    }
    
    debug_log("SDL subsystems successfully initialised.");
    
    int window_flags = 0;
    
    if (want_fullscreen) {
        window_flags = SDL_WINDOW_FULLSCREEN;
    }
    
    rgame->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, window_flags);
    
    if (rgame->window == 0) {
        // Handle error
    }
    
    debug_log("SDL window created.");
    
    rgame->renderer = SDL_CreateRenderer(rgame->window, -1, 0);
    
    if (rgame->renderer == 0) {
        // Handle error
    }
    
    debug_log("SDL renderer created.");
    
    rgame->is_running = true;
    
    
}

void rgame_handle_events()
void rgame_update();
void rgame_render();
void rgame_clean();

bool rgame_is_running(const struct RGame* restrict rgame)
{
    return rgame->is_running;
}
