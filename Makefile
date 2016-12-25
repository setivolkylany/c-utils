
FILENAME=main
C_FILENAME=$(FILENAME).c
EXECUTABLE_FILENAME=__$(FILENAME)__

all: $(C_FILENAME)
	@ gcc -Wall -std=c11 -I /usr/include/ -o $(EXECUTABLE_FILENAME) $(C_FILENAME)
	@ ./$(EXECUTABLE_FILENAME)
	@ rm $(EXECUTABLE_FILENAME)
