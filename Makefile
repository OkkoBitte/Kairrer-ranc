
CXX = clang++

CXXFLAGS = -std=c++17 -Wall -static

OUT = krr

SRC = C++/main.cpp


all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)


clean:
	rm -f $(OUT)


.PHONY: all clean
