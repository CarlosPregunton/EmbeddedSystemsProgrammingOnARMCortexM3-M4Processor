# CC:  Cross Compiler
CC=arm-none-eabi-gcc
# MACH: Machine Architecture
MACH=cortex-m4

# std: Standard, Wall: Turn on all warnings, O0:  No optimazations
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0
LDFLAGS= -nostdlib -T stm32f303re_ls.ld -Wl,-Map=final.map

# this command try to resolve main.o and led.o dependencies.
all:main.o stm32f303xx_gpio.o stm32f303_startup.o final.elf

# $@:  Target, $^:  Dependency
main.o:	main.c
	$(CC) $(CFLAGS) -o $@ $^
stm32f303xx_gpio.o: stm32f303xx_gpio.c
	$(CC) $(CFLAGS) -o $@ $^
stm32f303_startup.o: stm32f303_startup.c
	$(CC) $(CFLAGS) -o $@ $^
final.elf: main.o stm32f303xx_gpio.o stm32f303_startup.o 
	$(CC) $(LDFLAGS) -o $@ $^
clean: 
	rm -rf *.o *.elf
load:
	openocd -f board/stm32f3discovery.cfg

# command for converting .elf to .bin file
# arm-none-eabi-objcopy -O binary final.elf final.bin

# command for download .bin file to stm32f303re
# monitor flash write_image final.bin 0x08000000

# location of stm32f3discovery board script 
# /usr/share/openocd/scripts/board
