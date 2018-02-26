#ifndef __common_h__
#define __common_h__

#include <assert.h>

#if __STDC_VERSION__ == 201112L
#define HAVE_C11
#endif

#ifndef HAVE_C11
#error "RGame requires a compiler with C11 capabilities."
#endif

#if !defined(NDEBUG)
#define IN_DEBUG_MODE
#endif

#if defined(IN_DEBUG_MODE) || defined(LOGGING) // Specify with -D LOGGING
#define WANT_LOGGING
#endif

static inline void rgame_log(const char msg[restrict static 1], const char file_name[restrict static 1], 
					const char function_name[restrict static 1], const int line_number)
{
	#ifdef WANT_LOGGING
		fprintf(stderr, "[RGAME_LOG] %s (%s:%s:%d).\n", msg, file_name, function_name, line_number);
	#else
		return;
	#endif
}

#endif
