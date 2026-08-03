CXX = g++
CXXFLAGS = -O2 -std=c++17

TARGET = matrix_mult_exec

SRCS = main.cpp gemm_simple.cpp gemm_blocking.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)