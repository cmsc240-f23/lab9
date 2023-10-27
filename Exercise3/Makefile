# Rule for making the executable
main: main.o IntMatrix.cpp IntMatrix.h
	g++ main.o IntMatrix.cpp -o main

# Rule for compiling main.cpp to main.o
main.o: main.cpp IntMatrix.h
	g++ main.cpp -c 

# Clean up generated files
clean:
	rm -f *.o main
