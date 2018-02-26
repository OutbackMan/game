#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>

typedef enum status_codes {
	RGAME_ERROR,
	RGAME_SDL_ERROR,
	RGAME_SUCCESS
} rgame_status_t;

static const size_t NUMBER_OF_STATUS_CODES = 3
static const size_t MAX_STATUS_CODE_VALUE = 2;

const rgame_status_t rgame_status(const rgame_status_t status_code, const char msg[restrict static 1], const char file_location[restrict static 1], 
							const char function_name[restrict static 1], const int line_number);

const char* str_rgame_status(rgame_status_t status_code);

#endif
