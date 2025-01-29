#include <core/logger.h>
#include <defines.h>

int main(void) {
	SDB_Log_Fatal("THIS IS A FATAL LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	SDB_Log_Error("THIS IS A ERROR LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	SDB_Log_Warn ("THIS IS A WARN LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	SDB_Log_Info ("THIS IS A INFO LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	SDB_Log_Debug("THIS IS A DEBUG LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	SDB_Log_Trace("THIS IS A TRACE LOG MESSAGE!!!! PAY ATTETION TO ME!!!");
	
	return 0;
}