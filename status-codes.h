#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>
#include <stdbool.h>

typedef const enum status_codes {
	RGAME_ERROR,
	RGAME_SDL_ERROR,
	RGAME_SUCCESS
} rgame_status_t;

static const size_t NUMBER_OF_STATUS_CODES = 3;

static inline const bool is_valid_status_code(rgame_status_t status_code)
{
	static const size_t MAX_STATUS_CODE_VALUE = 2;
	return (status_code < 0 || status_code >= MAX_STATUS_CODE_VALUE);
}

#if defined(WANT_LOGGING1)
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status_log(1, STATUS_CODE, __FILE__, __func__, __LINE__)
#elif defined(WANT_LOGGING2) || defined(WANT_LOGGING3)
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status_log(3, STATUS_CODE, __FILE__, __func__, __LINE__)
#else
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status(STATUS_CODE)
#endif

rgame_status_t rgame_status(rgame_status_t status_code);
rgame_status_t rgame_status_log(const int log_level, rgame_status_t status_code, const char file_location[restrict static 1], 
							const char function_name[restrict static 1], const int line_number);

const char* str_rgame_status(rgame_status_t status_code);

#endif
