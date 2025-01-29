#pragma once 

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1

// Disable or enable debug and trace logging based on the build (relase/debug)
#if SDB_RELEASE == 1
	#define LOG_DEBUG_ENABLED 0
	#define LOG_TRACE_ENABLED 0
#else 
	#define LOG_DEBUG_ENABLED 1
	#define LOG_TRACE_ENABLED 1
#endif

typedef enum log_level {
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_ERROR = 1,
	LOG_LEVEL_WARN  = 2,
	LOG_LEVEL_INFO  = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5
	
} log_level;

b8 Log_Initialize(); 
void Log_Shutdown(); 

SDB_API void Log_Output(log_level level, const char* message, ...);

// Logs a fatal-level message
#define SDB_Log_Fatal(message, ...) Log_Output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef SDB_Log_Error
	// Logs an error-level message
	#define SDB_Log_Error(message, ...) Log_Output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
	// Logs a warn-level message
	#define SDB_Log_Warn(message, ...) Log_Output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
	// Does nothing when LOG_WARN_ENABLED != 1
	#define SDB_Log_Warn(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
	// Logs a info-level message
	#define SDB_Log_Info(message, ...) Log_Output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
	// Does nothing when LOG_INFO_ENABLED != 1
	#define SDB_Log_Info(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
	// Logs a debug-level message
	#define SDB_Log_Debug(message, ...) Log_Output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
	// Does nothing when LOG_DEBUG_ENABLED != 1
	#define SDB_Log_Debug(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
	// Logs a trace-level message
	#define SDB_Log_Trace(message, ...) Log_Output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
	// Does nothing when LOG_TRACE_ENABLED != 1
	#define SDB_Log_Trace(message, ...)
#endif

