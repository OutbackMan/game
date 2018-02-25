#include "status-codes.h"
#include <string.h>

#define STATUS_MESSAGE_BUFFER_SIZE ((unsigned int)100)

const char* str_rgame_status(rgame_status_t status_code)
{
	char message_buffer[STATUS_MESSAGE_BUFFER_SIZE] = {0};

	switch (status_code) {
		case RGAME_SUCCESS:
			sscanf_s(&message_buffer, "(Status Code: %d) RGame Success\n", RGAME_SUCCESS);  
			break;
		case RGAME_FAILURE:
			sscanf_s(&message_buffer, "(Status Code: %d) RGame Failure\n", RGAME_FAILURE);  
			break;
		default:
			sscanf_s(&message_buffer, "Unknown status code given\n");
	}

	return message_buffer;
}
