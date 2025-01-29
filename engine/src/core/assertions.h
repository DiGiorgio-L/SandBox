#pragma once

#include "defines.h"

// Disable assertions by commenting out the line below
#define SDB_ASSERTS_ENABLED

#ifdef SDB_ASSERTS_ENABLED
	#include <intrin.h>
	#define debugBreak() __debugbreak()

	SDB_API void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

	#define SDB_ASSERT(expr)																				 \
    {                                                              \
      if (expr) {                                                  \
      } else {                                                     \
          report_assertion_failure(#expr, "", __FILE__, __LINE__); \
          debugBreak();                                            \
      }                                                            \
    }																															 

	#define SDB_ASSERT_MSG(expr, message)				                          \
    {                                                              			\
      if (expr) {                                                  			\
      } else {                                                     			\
          report_assertion_failure(#expr, message, __FILE__, __LINE__); \
          debugBreak();                                            			\
      }                                                            			\
    }
		
	#ifdef _DEBUG
		#define SDB_ASSERT_DEBUG(expr)                                      \
			{                                                              		\
				if (expr) {                                                  		\
				} else {                                                     		\
          report_assertion_failure(#expr, "", __FILE__, __LINE__); 			\
          debugBreak();                                            			\
				}                                                            		\
			}
	#else
		#define SDB_ASSERT_DEBUG(expr) // Does nothing instead
	#endif
#else
	#define SDB_ASSERT(expr)
	#define SDB_ASSERT_MSG(expr, message)
	#define SDB_ASSERT_DEBUG(expr)
#endif