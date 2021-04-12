CC=g++

CFLAGS=-Ofast -march=native -mtune=native -std=c++14

LDFLAGS=

EXEC=VectorDrawing

SRC=./src/Format/CBitmap.cpp   \
    ./src/Image/CImage.cpp     \
    ./src/Image/CLigne.cpp     \
    ./src/Image/CPixel.cpp     \
		./src/Shapes/CDrawing.cpp  \
		./src/Shapes/CPoint.cpp    \
		./src/Shapes/CRectangle.cpp    \
		./src/Shapes/CDisk.cpp    \
		./src/Shapes/CLine.cpp    \
    ./src/VectorDrawing.cpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

VectorDrawing: $(OBJ)
	$(CC) $(CFLAGS) -o ./bin/$@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean mrproper

clean:
	find ./bin -name VectorDrawing -exec rm {} \;
	find ./src -name *.o  -exec rm {} \;

mrproper: clean
	rm $(EXEC)
