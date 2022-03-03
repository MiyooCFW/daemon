all:
	arm-linux-gcc main.c -o daemon -ggdb -lSDL -lc
clean:
	rm -rf daemon
