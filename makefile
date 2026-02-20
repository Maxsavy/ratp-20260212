CXX = gcc
LDFLAGS = --coverage 
OPTIONS = -Wall -fexceptions -fprofile-arcs -ftest-coverage
INCS = -I.  -I"." 
OBJS = $(SRC:.c=.o)

SRC = ratp.c  main.c cmocka.o


all: $(OBJS)
	$(CXX) $(LDFLAGS) $(INCS) -o testAll  $(OBJS)

	
exec : all
	testAll.exe
%.o: %.c
	$(CXX) $(OPTIONS) -c  $< -o $@ $(INCS)
	
clean:
	rm -f $(OBJS) testAll


mrproper: clean
	rm -f *.gcda *.gcno results.*
	rm result.xml