#ifndef __debug_h__
#define __debug_h__

#include <stdio.h>
#include <errno.h>
#include <signal.h>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

// NDEBUG will stop asserts
#ifndef NDEBUG
#define debug_log(MSG) fprintf(stderr, "[RGAME_LOG]" MSG " (%s:%s:%d)\n",\
                            __FILE__, __func__, __LINE__)
#define debug_error(MSG) fprintf(stderr, "[RGAME_ERROR] (errno: %s) " MSG " (%s:%s:%d)\n",\
                            clean_errno(), __FILE__, __func__, __LINE__)
#define breakpoint() raise(SIGTRAP)
#else
#define debug_log(MSG)
#define debug_error(MSG)
#define breakpoint()
#endif

#endif
