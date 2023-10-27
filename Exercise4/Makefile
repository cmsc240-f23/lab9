# Rule for making the executable
main: main.o IntVector.cpp IntVector.h
	g++ main.o IntVector.cpp -o main

# Rule for compiling main.cpp to main.o
main.o: main.cpp IntVector.h 
	g++ main.cpp -c 

# Clean up generated files
clean:
	rm -f *.o main
