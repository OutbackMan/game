#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>

typedef enum status_codes {
	RGAME_FAILURE,
	RGAME_SUCCESS
} rgame_status_t;

char* str_rgame_status(rgame_status_t status_code);

#endif
