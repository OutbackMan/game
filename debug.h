#ifndef __debug_h__
#define __debug_h__

#include "status-codes.h"
#include <stdio.h>
#include <errno.h>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#ifndef NDEBUG
#define WANT_LOGGING
#endif

static inline rgame_status_t rgame_status_null_argument(const char file_location[restrict static 1], const char function_name[restrict static 1], const int line_number)
{
    #ifdef WANT_LOGGING
        fprintf(stderr, "[RGAME_NULL_ARGUMENT] (errno: %s) Null argument passed to callee which requires a non-null argument (%s:%s:%d).\n");
    #else
        return RGAME_NULL_ARGUMENT;
    #endif
}

static inline rgame_status_t rgame_sdl_error(const char message[restrict static 1])
{
    fprintf(stderr, "[RGAME_SDL_ERROR] %s.\n", message);
    return RGAME_SDL_ERROR;
}

#endif
