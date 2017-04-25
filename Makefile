OBJECTS = main.cpp\
	  source/Game.cpp

OUTPUT_FILE_NAME = DwarfForge

COMPILER = g++

INCLUDE_PATHS = -IC:\SDL2-2.0.5\x86_64-w64-mingw32\include
	
LIBRARY_PATHS = -LC:\SDL2-2.0.5\x86_64-w64-mingw32\lib

SDL_DLL_PATH = C:\SDL2-2.0.5\x86_64-w64-mingw32\bin\SDL2.dll

COMPILER_FLAGS = -w -Wall 

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

all: $(OBJECTS)
	   $(COMPILER) $(OBJECTS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OUTPUT_FILE_NAME) 
	   cp -f $(SDL_DLL_PATH) SDL2.dll 