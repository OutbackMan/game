#ifndef __common_h__
#define __common_h__

#include <signal.h>
#include <stdbool.h>

#if __STDC_VERSION__ == 201112L
#define HAVE_C11
#endif

#ifndef HAVE_C11
#error "RGame requires a compiler with C11 capabilities."
#endif

#ifdef DEBUG
#define IN_DEBUG_MODE
#endif

#ifdef IN_DEBUG_MODE
#define RGAME_ASSERT(EXPR) \
		do { \
			if (!EXPR) \
				rgame_assert(#EXPR, __FILE__, __func__, __LINE__) \
		} while (0)
#else
#define RGAME_ASSERT(EXPR)
#endif

static inline void rgame_assert(const char expression[restrict static 1], const char file_name[restrict static 1],
							const char function_name[restrict static 1], const int line_number)
{
	fprintf(stderr, "[RGAME_ASSERTION_ERROR] %s (%s:%s:%d)\n", expression, file_name, function_name, line_number);
	raise(SIGABRT);
}

// MOVE INTO logging.h
// Errors, successes and logs
#ifdef LOGGING1
#define WANT_LOGGING1
#endif

// Errors and logs
#if defined(LOGGING2) || defined(IN_DEBUG_MODE)
#define WANT_LOGGING2
#endif

// Errors
#ifdef LOGGING3
#define WANT_LOGGING3
#endif

#if defined(WANT_LOGGING1) || defined(WANT_LOGGING2)
#define RGAME_LOG(MSG) \
		rgame_log(MSG, __FILE__, __func__, __LINE__)
#else
#define RGAME_LOG(MSG)
#endif

static inline void rgame_log(const char msg[restrict static 1], const char file_name[restrict static 1], 
					const char function_name[restrict static 1], const int line_number)
{
		fprintf(stderr, "[RGAME_LOG] %s (%s:%s:%d).\n", msg, file_name, function_name, line_number);
}

#endif
