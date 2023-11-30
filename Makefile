ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname)
endif

CC = g++

ifeq ($(detected_OS),Windows)
	LIBS += libglew32.dll.a glfw3dll.a -I include -lOpenGL32 -L ./ -lglew32 -lglfw3 -lm
endif
ifeq ($(detected_OS),Linux)
	LIBS += -lglfw -lGLEW -I include -lGL -x11 -lXxf86vm -lXrandr -lpthread -lXi -lm
endif

ODIR	= src/obj
SDIR	= src

SOURCES_C := $(wildcard $(SDIR)/*.c) 
SOURCES_CPP += $(wildcard $(SDIR)/*.cpp) 

OBJECTS_C := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES_C))
OBJECTS_CPP += $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES_CPP))

OBJECTS := $(OBJECTS_C) $(OBJECTS_CPP)
SOURCES := $(SOURCES_C) $(SOURCES_CPP)

app: $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

$(ODIR)/%.o: $(SOURCES)
	$(CC)-c $< -o $@
	
.PHONY: clean

clean:
	-rm -rfv app app.dSYM

run:
	make clean
	make
	./app
