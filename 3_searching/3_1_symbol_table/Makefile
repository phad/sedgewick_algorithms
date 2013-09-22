OBJS = symbol_table.o \
	templates.o \
	main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -fno-implicit-templates
LFLAGS = -Wall $(DEBUG)

symbol_table : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o symbol_table

symbol_table.o : symbol_table.h symbol_table.cpp
	$(CC) $(CFLAGS) symbol_table.cpp

templates.o : symbol_table.h templates.cpp
	$(CC) $(CFLAGS) templates.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ symbol_table

