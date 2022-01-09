CXX=g++

all: main

main: main.cpp
        $(CXX) $(CXXFLAGS) main.cpp -std=c++11 -o boxstacking

test:
        ./testes.sh casos.entrada casos.respostas

clean:
        rm boxstacking
