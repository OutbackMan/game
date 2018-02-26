#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>

typedef enum status_codes {
	RGAME_ERROR,
	RGAME_NULL_ARGUMENT,
	RGAME_SDL_ERROR,
	RGAME_SUCCESS
} rgame_status_t;

static const size_t NUMBER_OF_STATUS_CODES = 4;
static const size_t MAX_STATUS_CODE_VALUE = 3;

const char* str_rgame_status(rgame_status_t status_code);

#endif
