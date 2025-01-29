#include "logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

b8 Log_Initialize() {
	// TODO: create a log file 
	return TRUE;
}

void Log_Shutdown() {
	// TODO: cleanup logging/write queued entries
}

SDB_API void Log_Output(log_level level, const char* message, ...) {
	const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
	//b8 is_error = level < 2;
	
	__builtin_va_list arg_ptr;
	va_start(arg_ptr, message);
	
		// get the size of the string to be printed
		int str_size = vsnprintf(0, 0, message, arg_ptr);
		
	va_end(arg_ptr);
	
	// allocate the exact amount of memory required by the string
	char* out_message = malloc(sizeof(char) * str_size);
	
	// compose the string
	sprintf(out_message, "%s\n", message);
	
	printf("%s%s", level_strings[level], out_message); // TODO: platform-specific output
	
	// deallocate memory to prevent memory leaks
	free(out_message);
}