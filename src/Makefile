G++ = g++
FLAGS = -lm -g
FILES = *.cpp
TARGET = drawBmp

all: $(TARGET) 

$(TARGET): obj
	$(G++) $(FLAGS) *.o -o $(TARGET)

obj:
	$(G++) $(FLAGS) $(FILES) -c

test: all
	./$(TARGET) image/T.bmp

clean:
	rm -rf $(TARGET) *.o