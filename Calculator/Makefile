.PHONY: all debug release clean

all: debug release

debug: calculator-dbg

hello-dbg: calculator.cpp
	g++ -g -O0 calculator.cpp -o calculator-dbg -Wall

release: calculator

hello: calculator.cpp
	g++ -O2 calculator.cpp -o calculator -DNDEBUG -Wall

clean:
	rm -f calculator calculator-dbg
