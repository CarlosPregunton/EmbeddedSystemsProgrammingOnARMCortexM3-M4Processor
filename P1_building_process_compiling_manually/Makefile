# CC:  Cross Compiler
CC=arm-none-eabi-gcc
MACH=cortex-m4

# std: Standard, Wall: Turn on all warnings, O0:  No optimazations
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0

# this command try to resolve main.o and led.o dependencies.
all:main.o led.o stm32f303_startup.o

# $@:  Target, $^:  Dependency
main.o:	main.c
	$(CC) $(CFLAGS) -o $@ $^
led.o: led.c
	$(CC) $(CFLAGS) -o $@ $^
stm32f303_startup.o: stm32f303_startup.c
	$(CC) $(CFLAGS) -o $@ $^
clean: 
	rm -rf *.o *.elf
