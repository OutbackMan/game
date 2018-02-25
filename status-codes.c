#include "status-codes.h"
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

const char* str_rgame_status(rgame_status_t status_code)
{
	if (!is_valid_status_code(status_code)) {
		return "Unknown Status Code\n";
	} else {
		const size_t MESSAGE_BUFFER_SIZE = 100;
		char message_buffer[MESSAGE_BUFFER_SIZE] = {0};
	
		sscanf(&message_buffer, "(Status Code: %d) %s\n", status_code, status_code_strings[status_code]);

		return message_buffer;
	}
}

static bool is_valid_status_code(rgame_status_t status_code)
{
	if (status_code < 0 || status_code >= status_code_lengths) {
		return false;
	} else {
		return true;
	}
}
