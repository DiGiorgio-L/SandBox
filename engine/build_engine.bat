REM Build script for engine
@ECHO OFF
SETLOCAL EnableDelayedExpansion

REM Get a list of all the .c files.
SET cFilenames=
FOR /R %%f in (*.c) do (
	SET cFilenames=!cFilenames! %%f
)

echo "Files:" %cFilenames%

SET assembly=SDB_engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror 
REM -Wall -Werror
SET includeFlags=-I./src
SET linkerFlags=-luser32 -lopengl32
SET defines=-DSDB_DEBUG -DSDB_EXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %assembly%%..."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%