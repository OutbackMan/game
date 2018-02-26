#include "status-codes.h"
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

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
		"RGame Failure",
		"RGame Success",
	};
	
	return status_code_strings[status_code];
}

const char* str_rgame_status(rgame_status_t status_code)
{
	static const size_t MESSAGE_BUFFER_SIZE = 100;
	char message_buffer[MESSAGE_BUFFER_SIZE] = {0};
	
	sscanf(&message_buffer, "(Status Code: %d) %s\n", status_code, lookup_status_code_string(status_code));

	return message_buffer;
}


