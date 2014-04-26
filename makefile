all:
	gcc search.c -o search

install: all
	mv ./search /usr/bin/
