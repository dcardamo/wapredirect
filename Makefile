# $ID$

CC = g++
CFLAGS = -O
LDFLAGS = 

all: about wapredir.cgi

about:
	@echo "------------------------------------------"
	@echo "This program is released under the GNU GPL"
	@echo "Copyright 2002 Dan Cardamore <dan@hld.ca> "
	@echo "------------------------------------------"

wapredir.cgi: wapredir.cc
	@echo "Building C version."
	@echo "If you prefer the perl version, rename wapredir.pl to wapredir.cgi"
	$(CC) $(CFLAGS) $? $(LDFLAGS) -o $@

clean:
	rm -f wapredir.cgi

install:
	@echo "Copy the .cgi file to your web server root directory"

test:
	sh test.sh
