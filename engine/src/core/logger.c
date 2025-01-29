#include "logger.h"
#include "assertions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line) {
	Log_Output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}

b8 Log_Initialize() {
	// TODO: create a log file 
	return TRUE;
}

void Log_Shutdown() {
	// TODO: cleanup logging/write queued entries
}

void Log_Output(log_level level, const char* message, ...) {
	const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
	//b8 is_error = level < 2;
	
	__builtin_va_list arg_ptr;
	va_start(arg_ptr, message);
	
		// get the size of the string to be printed
		int str_size = vsnprintf(0, 0, message, arg_ptr);
		
		// allocate the exact amount of memory required by the string
		char* out_message = malloc(sizeof(char) * str_size);
		
		// compose the string
		vsnprintf(out_message, str_size, message, arg_ptr);
		
	va_end(arg_ptr);
	
	printf("%s%s", level_strings[level], out_message); // TODO: platform-specific output
	
	// deallocate memory to prevent memory leaks
	free(out_message);
}