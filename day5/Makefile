CXX=g++
TARGET=day5
CXXFLAGS=-g -std=c++20
UTILSPATH=../utilities

objects = $(TARGET).o $(UTILSPATH)/input.o

all: $(TARGET)

input.o:
	cd .. && $(MAKE)

day5: $(objects)
	$(CXX) -o $(TARGET) $(objects)

run: $(TARGET)
	./$(TARGET)

clean:
	rm *.o $(TARGET)
	rm ../utilities/*.o