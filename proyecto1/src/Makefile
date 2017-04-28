CXX=g++
CXXFLAGS=-g -std=c++11
BIN=kyc-ip

SRC=$(wildcard *.cpp *.c)
OBJ=$(SRC:%.cpp=%.o)

all: flex bison fin

fin: $(OBJ)
	$(CXX) -g -std=c++11 -o $(BIN) $^ -lfl

%.o: %.c
	$(CXX) $@ -c $<

.PHONY: clean
clean :
	rm -f $(BIN) *.o

.PHONY: flex
flex:
	flex lexer.lex

.PHONY: bison
bison:
	bison -d parser.y
