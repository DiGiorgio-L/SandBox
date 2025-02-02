REM Build script for testbed
@ECHO OFF
SETLOCAL EnableDelayedExpansion

REM Get a list of all the .c files.
SET cFilenames=
FOR /R %%f in (*.c) do (
	SET cFilenames=!cFilenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=SDB_testbed
SET compilerFlags=-g 
REM -Wall -Werror
SET includeFlags=-Isrc -I../engine/src/
SET linkerFlags=-L../bin/ -lSDB_engine.lib
SET defines=-D_DEBUG -DSDB_IMPORT

ECHO "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%