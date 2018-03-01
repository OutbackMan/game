#ifndef __status_codes_h__
#define __status_codes_h__

#include <stddef.h>
#include <stdbool.h>

typedef const enum status_codes {
	RGAME_ERROR,
	RGAME_SDL_ERROR,
	RGAME_SUCCESS
} rgame_status_t;

// Want these available
static const size_t NUMBER_OF_STATUS_CODES = 3;
static const size_t MINIMUM_STATUS_CODE_VALUE = 0;
static const size_t MAXIMUM_STATUS_CODE_VALUE = 2;

rgame_status_t return_rgame_status(rgame_status_t status_code);
const char* rgame_status_code_message(rgame_status_t status_code);
const char* rgame_status_code_name(rgame_status_t status_code);

#define UV_ERRNO_MAP(XX) \
	XX(E2BIG, "argument list too long") \
	XX(EACCES, "permission denied") \

#define UV_STRERROR_GEN(name, msg) case UV_ ## name: return msg;
const char* uv_strerror(int err) {
	switch (err) {
		UV_ERRNO_MAP(UV_STRERROR_GEN)		
	}
	return uv__unknown_err_code(err);
}
#undef UV_STRERROR_GEN


typedef enum {
#define XX(code, _) UV_ ## code = UV__ ## code,
  UV_ERRNO_MAP(XX)
#undef XX
  UV_ERRNO_MAX = UV__EOF - 1
} uv_errno_t;


#endif
