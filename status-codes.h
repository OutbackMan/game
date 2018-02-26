#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>
#include <stdbool.h>

typedef enum status_codes {
	RGAME_ERROR,
	RGAME_SDL_ERROR,
	RGAME_SUCCESS
} rgame_status_t;

static const size_t NUMBER_OF_STATUS_CODES = 3
static const size_t MAX_STATUS_CODE_VALUE = 2;

static inline bool is_valid_status_code(rgame_status_t status_code)
{
	if (status_code < 0 || status_code >= MAX_STATUS_CODE_VALUE) {
		return false;
	} else {
		return true;
	}
}

#if defined(WANT_LOGGING1)
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status_log(1, STATUS_CODE, __FILE__, __func__, __LINE__)
#elif defined(WANT_LOGGING2)
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status_log(2, STATUS_CODE, __FILE__, __func__, __LINE__)
#elif defined(WANT_LOGGING3)
#define RGAME_STATUS(STATUS_CODE) \
		rgame_status_log(3, STATUS_CODE, __FILE__, __func__, __LINE__)
#endif

const rgame_status_t rgame_status_log(const int log_level, const rgame_status_t status_code, const char file_location[restrict static 1], 
							const char function_name[restrict static 1], const int line_number);

const char* str_rgame_status(rgame_status_t status_code);

#endif
