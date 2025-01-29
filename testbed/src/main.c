#include <core/assertions.h>
#include <core/logger.h>
#include <defines.h>

//test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
//

int main(void) {
	SDB_ASSERT(1 == 0);
	SDB_ASSERT_MSG(1 == 0, "TEST MESSAGE!!!");
	

	

	
	return 0;
}