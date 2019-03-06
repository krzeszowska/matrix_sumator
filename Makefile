OBJS = main.o 
SOURCE = main.cpp 
HEADER = Tester.hpp Matrix.hpp 
OUT = sumator 
CC = g++ 
FLAGS = -g -c -Wall 
LFLAGS = 
all: $(OBJS) 
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) 

main.o: main.cpp 
	$(CC) $(FLAGS) main.cpp 

clean: 
	rm -f $(OBJS) $(OUT) 