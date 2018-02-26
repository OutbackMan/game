#include "status-codes.h"
#include "common.h" 
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

static const char* lookup_status_code_string(rgame_status_t status_code)
{
	if (!is_valid_status_code(status_code)) {
		return "Unknown Status Code";
	}
	
	static const char* status_code_strings[NUMBER_OF_STATUS_CODES] = {
		"[RGAME_ERROR]",
		"[RGAME_SDL_ERROR]",
		"[RGAME_SUCCESS]"
	};
	
	return status_code_strings[status_code];
}

static inline const char* clean_errno(void)
{
	return (errno == 0 ? "None" : strerror(errno));
}

const rgame_status_t rgame_status(const rgame_status_t status_code)
{
	assert(is_valid_status_code(status_code));
	return status_code;
}

const rgame_status_t rgame_status_log_1(const rgame_status_t status_code, const char file_name[restrict static 1], 
					const char function_name[restrict static 1], const int line_number)
{
	assert(is_valid_status_code(status_code));
	
    	fprintf(stderr, "%s (%s:%s:%d) %s (errno: %s).\n", lookup_status_code_string(status_code), 
			file_name, function_name, line_number, 
			(status_code == RGAME_SDL_ERROR ? SDL_GetError() : ""), clean_errno());
	
	return status_code;
}

const rgame_status_t rgame_status_log_2_and_3(const rgame_status_t status_code, const char file_name[restrict static 1], 
					const char function_name[restrict static 1], const int line_number)
{
	assert(is_valid_status_code(status_code));
	
	if (status_code != RGAME_SUCCESS) {
    		fprintf(stderr, "%s (%s:%s:%d) %s (errno: %s).\n", lookup_status_code_string(status_code), 
				file_name, function_name, line_number, 
				(status_code == RGAME_SDL_ERROR ? SDL_GetError() : ""), clean_errno());
	}
	
	return status_code;	
}

const char* str_rgame_status(rgame_status_t status_code)
{
	static const size_t MESSAGE_BUFFER_SIZE = 100;
	char message_buffer[MESSAGE_BUFFER_SIZE] = {0};
	
	sscanf(&message_buffer, "%s (Status Code: %d) \n", lookup_status_code_string(status_code), status_code);

	return message_buffer;
}

