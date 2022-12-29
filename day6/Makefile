CXX=g++
TARGET=day6
CXXFLAGS=-g -std=c++20
UTILSPATH=../utilities

objects = $(TARGET).o $(UTILSPATH)/input.o

all: $(TARGET)

input.o:
	cd .. && $(MAKE)

day6: $(objects)
	$(CXX) -o $(TARGET) $(objects)

run: $(TARGET)
	./$(TARGET)

clean:
	rm *.o $(TARGET)
	rm ../utilities/*.o