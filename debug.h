#ifndef __debug_h__
#define __debug_h__

#include <stdio.h>
#include <errno.h>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define rgame_error(MSG) fprintf(stderr, "[RGAME_ERROR] (errno: %s) " MSG " (%s:%s:%d).\n",\
                            clean_errno(), __FILE__, __func__, __LINE__)

#ifndef NDEBUG
#define rgame_log(MSG) fprintf(stderr, "[RGAME_LOG]" MSG " (%s:%s:%d).\n",\
                            __FILE__, __func__, __LINE__)
#else
#define rgame_log(MSG)
#endif

inline static void rgame_sdl_error(const char message[restrict static 1])
{
    fprintf(stderr, "[RGAME_SDL_ERROR] %s.\n", message);
}

#endif
