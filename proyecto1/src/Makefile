CXX=g++
CXXFLAGS=-g -std=c++11
BIN=kyc-ip

SRC=$(wildcard *.cpp *.cc)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -g -std=c++11 -o $(BIN) $^ -lfl

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean :
	rm -f $(BIN) *.o

.PHONY: flex
flex:
	flex++ lexer.lex
