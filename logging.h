#ifndef __logging_h__
#define __logging_h__

#include "common.h"

#if defined(LOGGING1)
# define LOG_LEVEL 1
#elif defined(LOGGING2) || defined(IN_DEBUG_MODE)
# define LOG_LEVEL 2
#elif define(LOGGING3)
# define LOG_LEVEL 3
#else
# define LOG_LEVEL 0
#endif

#define RGAME_LOG(MSG) \
		rgame_log(LOG_LEVEL, MSG, __FILE__, __func__, __LINE__)

static inline void rgame_log(const char msg[restrict static 1], const char file_name[restrict static 1], 
					const char function_name[restrict static 1], const int line_number)
{
		fprintf(stderr, "[RGAME_LOG] %s (%s:%s:%d).\n", msg, file_name, function_name, line_number);
}


#endif
