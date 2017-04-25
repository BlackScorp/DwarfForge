OBJECTS = main.cpp\
	  source/Game.cpp
	     
OUTPUT_FILE_NAME = DwarfForge
COMPILER = g++

	
INCLUDE_PATHS = -I"$(SDL_PATH)\include"
	
LIBRARY_PATHS = -L"$(SDL_PATH)\lib"
	

COMPILER_FLAGS = -Wall

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 

all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILER_FLAGS) -o $(OUTPUT_FILE_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS)    
	cp -f $(SDL_DLL_PATH) SDL2.dll 