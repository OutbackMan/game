#ifndef __status_codes_h__
#define __status_codes_h__

typedef enum status_codes {
	RGAME_SUCCESS = 1,
	RGAME_FAILURE = -1,
} rgame_status_t;

char* str_rgame_status(rgame_status_t status_code);

#endif
