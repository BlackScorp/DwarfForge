OBJECTS = main.cpp\
	  source/Game.cpp\
	  source/MainScene.cpp\
	  source/Shapes/Rect.cpp\
	  source/Entity.cpp\
	  source/EntityManager.cpp\
	
OUTPUT_FILE_NAME = DwarfForge
COMPILER = g++

SDL_PATH = C:\SDL2-2.0.5\i686-w64-mingw32
SDL_IMAGE_PATH = C:\SDL2_image-2.0.1\i686-w64-mingw32
	
INCLUDE_PATHS = -I"$(SDL_PATH)\include"\
		-I"$(SDL_PATH)\include\SDL2"\
		-I"$(SDL_IMAGE_PATH)\include"
	
LIBRARY_PATHS = -L"$(SDL_PATH)\lib"\
		-L"$(SDL_IMAGE_PATH)\lib"
	
SDL_DLL_PATH = $(SDL_PATH)\bin\SDL2.dll
SDL_IMAGE_DLL_PATH = $(SDL_IMAGE_PATH)\bin\SDL2_image.dll
LIB_PNG_DLL_PATH = $(SDL_IMAGE_PATH)\bin\libpng16-16.dll

COMPILER_FLAGS = -Wall -std=c++11

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_Image

all: $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILER_FLAGS) -o $(OUTPUT_FILE_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS)    
	cp -f $(SDL_DLL_PATH) SDL2.dll 
	cp -f $(SDL_IMAGE_DLL_PATH) SDL2_image.dll 
	cp -f $(LIB_PNG_DLL_PATH) libpng16-16.dll 