#include "rgame.h"
#include "common.h"
#include "status-codes.h"
#include <stdbool.h>

rgame_status_t rgame_init(const char title[restrict static 1], int x_pos, int y_pos, int width, int height, bool want_fullscreen, struct RGame* restrict rgame_instance)
{
    if (rgame_instance == NULL) {
        return rgame_status(RGAME_NULL_ARGUMENT, __FILE__, __func__, __LINE__);
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return rgame_status(RGAME_SDL_ERROR, __FILE__, __func__, __LINE__);
    }
    
    rgame_log("SDL subsystems successfully initialised", __FILE__, __func__, __LINE__);
    
    int window_flags = 0;
    
    if (want_fullscreen) {
        window_flags = SDL_WINDOW_FULLSCREEN;
    }
    
    rgame_instance->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, window_flags);
    
    if (rgame_instance->window == NULL) {
        return rgame_status(RGAME_SDL_ERROR, __FILE__, __func__, __LINE__);
    }
    
    rgame_log("SDL window created", __FILE__, __func__, __LINE__);
    
    rgame_instance->renderer = SDL_CreateRenderer(rgame->window, -1, 0);
    
    if (rgame_instance->renderer == NULL) {
        return rgame_status(RGAME_SDL_ERROR, __FILE__, __func__, __LINE__);
    }
    
    rgame_log("SDL renderer created", __FILE__, __func__, __LINE__);
    
    rgame_instance->is_running = true;
    
    return rgame_status(RGAME_SUCCESS, __FILE__, __func__, __LINE__);
}

const rgame_status_t rgame_handle_events(const struct RGame* restrict rgame_instance)
{
    if (rgame_instance == NULL) {
        return rgame_status(RGAME_NULL_ARGUMENT, __FILE__, __func__, __LINE__);
    }
    
    SDL_Event event = {0};
    SDL_Poll(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            rgame_instance->is_running = false;
            break;
        default:
            break;
    }
    
    return rgame_status(RGAME_SUCCESS, __FILE__, __func__, __LINE__);
}

void rgame_update();

const rgame_status_t rgame_render(const struct RGame* restrict rgame_instance)
{
    if (rgame_instance == NULL) {
        return rgame_status(RGAME_NULL_ARGUMENT, __FILE__, __func__, __LINE__);
    }
    
    SDL_RenderClear(rgame_instance->renderer);
    SDL_RenderPresent(rgame_instance->renderer);
    
    return rgame_status(RGAME_SUCCESS, __FILE__, __func__, __LINE__);
}

void rgame_clean();

bool rgame_is_running(const struct RGame* restrict rgame)
{
    return rgame->is_running;
}
