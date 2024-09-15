# CC:  Cross Compiler
CC=arm-none-eabi-gcc
MACH=cortex-m4

# std: Standard, O0:  No optimazations
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

# this command try to resolve main.o and led.o dependencies.
all:main.o led.o

# $@:  Target, $^:  Dependency
main.o:	main.c
	$(CC) $(CFLAGS) -o $@ $^
led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^
