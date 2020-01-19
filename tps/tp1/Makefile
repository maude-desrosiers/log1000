ifeq (rpm -q <newton>, 0)
else

DESTDIR = install1
.PHONY: install
install: newton 
	mkdir -p $(DESTDIR)/usr/local/bin
	cp $< $(DESTDIR)/usr/local/bin/newton

endif
EXEC = newton
CC=gcc
# default command, builds an executable called "newton".
# executable can be called with ./newton 49 4
all: $(EXEC)

# link the object files into the executable.
# the -lm option is to tell the linker to include math libraries.
newton: main.o newton.o comparison.o
	$(CC) -o $@ $^ -lm

# compile the main.c file into the main.o object file.
main.o: main.c newton.h comparison.h
	$(CC) -o $@ -c $<

# compile the newton.c file into the newton.o object file.
newton.o: newton.c newton.h
	$(CC) -o $@ -c $<

#compile le comparison.o 
comparison.o: comparison.c comparison.h 
	$(CC) -o $@ -c $<

# remove the executable and intermediary object files.
clean:
	rm -rf newton *.o

#install





