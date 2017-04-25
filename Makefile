OBJECTS = main.cpp\
	  source/Game.cpp
	     
OUTPUT_FILE_NAME = DwarfForge

COMPILER = g++

INCLUDE_PATHS = -I"C:\SDL2-2.0.5\x86_64-w64-mingw32\include"
	
LIBRARY_PATHS = -L"C:\SDL2-2.0.5\x86_64-w64-mingw32\lib"
	
SDL_DLL_PATH = C:\SDL2-2.0.5\x86_64-w64-mingw32\bin\SDL2.dll

COMPILER_FLAGS = -Wall

LINKER_FLAGS =  -lmingw32 -lSDL2  -lSDL2main 

all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILER_FLAGS) -o $(OUTPUT_FILE_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS)    
	cp -f $(SDL_DLL_PATH) SDL2.dll 