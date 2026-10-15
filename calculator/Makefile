.PHONY: all test clean

CXX = g++
CXXFLAGS = -Wall -O2
TARGET = calculator

all: $(TARGET)

$(TARGET): calculator.cpp
	$(CXX) $(CXXFLAGS) calculator.cpp -o $(TARGET)

test: all
	./$(TARGET) -o summa 45 13 -2
	./$(TARGET) --operation subtract 45 13 -2

clean:
	rm -f $(TARGET) *.o
