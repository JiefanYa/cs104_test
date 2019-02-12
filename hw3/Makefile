CXX = g++
CXXFLAGS = -g -Wall --std=c++11

all: stringparser

stringparser: stringparser2.cpp ulliststr.o stackstring.o
	$(CXX) $(CXXFLAGS) stringparser2.cpp stackstring.o ulliststr.o -o stringparser

ulliststr.o: ulliststr.cpp ulliststr.h
	$(CXX) $(CXXFLAGS) -c ulliststr.cpp -o ulliststr.o

stackstring.o: stackstring.cpp stackstring.h ulliststr.cpp ulliststr.h
	$(CXX) $(CXXFLAGS) -c stackstring.cpp -o stackstring.o