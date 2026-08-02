CXX = g++
CXXFLAGS = -O2 -std=c++17

TARGET = simple_matrix_mult_exec

SRCS = main.cpp gemm.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run:
	./$(TARGET) gemm_test_01.txt

clean:
	rm -f $(TARGET)