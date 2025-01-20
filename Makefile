PROG = main.exe 
SRC = src/main.cpp src/createuser.cpp src/menu.cpp src/testlogin.cpp
CFLAGS = -g -std=c++17
LIBS = -lcrypto
CC=g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC)  $(LIBS) 

clean:
	rm -f $(PROG)

.PHONY: all clean