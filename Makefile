OBJECTS = main.cpp\
	  source/Game.cpp\
	  source/MainScene.cpp\

	     
OUTPUT_FILE_NAME = DwarfForge
COMPILER = g++

SDL_PATH = C:\SDL2-2.0.5\i686-w64-mingw32
	
INCLUDE_PATHS = -I"$(SDL_PATH)\include"
	
LIBRARY_PATHS = -L"$(SDL_PATH)\lib"
	
SDL_DLL_PATH = $(SDL_PATH)\bin\SDL2.dll

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 

all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILER_FLAGS) -o $(OUTPUT_FILE_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS)    
	cp -f $(SDL_DLL_PATH) SDL2.dll 