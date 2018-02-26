#include "status-codes.h"
#include "common.h" 
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

static bool is_valid_status_code(rgame_status_t status_code)
{
	if (status_code < 0 || status_code >= MAX_STATUS_CODE_VALUE) {
		return false;
	} else {
		return true;
	}
}

static const char* lookup_status_code_string(rgame_status_t status_code)
{
	if (!is_valid_status_code(status_code)) {
		return "Unknown Status Code";
	}
	
	static const char* status_code_strings[NUMBER_OF_STATUS_CODES] = {
		"[RGAME_ERROR] Specific RGame operation encountered an error",
		"[RGAME_NULL_ARGUMENT] Null argument passed to RGame function which requires a non-null argument",
		"[RGAME_SDL_ERROR]",
		"[RGAME_SUCCESS] Specific RGame operation completed successfully",
	};
	
	return status_code_strings[status_code];
}

static inline const char* clean_errno(void)
{
	return (errno == 0 ? "None" : strerror(errno));
}

const rgame_status_t rgame_status(const rgame_status_t status_code, const char file_name[restrict static 1], 
							const char function_name[restrict static 1], const int line_number)
{
	assert(is_valid_status_code(status_code));
	
    #ifdef WANT_LOGGING
		if (status_code == RGAME_SDL_ERROR) {
			fprintf(stderr, "%s %s (%s:%s:%d)(errno: %s).\n", lookup_status_code_string(status_code), 
				SDL_GetError(), file_name, function_name, line_number, clean_errno());
		} else {
			fprintf(stderr, "%s (%s:%s:%d)(errno: %s).\n", lookup_status_code_string(status_code), 
				file_name, function_name, line_number, clean_errno());
		}
    #else
        return status_code;
    #endif
}

const char* str_rgame_status(rgame_status_t status_code)
{
	static const size_t MESSAGE_BUFFER_SIZE = 100;
	char message_buffer[MESSAGE_BUFFER_SIZE] = {0};
	
	sscanf(&message_buffer, "%s (Status Code: %d) \n", lookup_status_code_string(status_code), status_code);

	return message_buffer;
}

