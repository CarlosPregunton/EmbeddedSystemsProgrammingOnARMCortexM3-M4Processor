# Directorio base del proyecto
PROJECT_DIR=/home/carlos/Documents/EmbeddedSystemsProgrammingOnARMCortexM3-M4Processor

# Compilador y opciones
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib
CPPFLAGS=-DSTM32F303xE \
	 -I$(PROJECT_DIR)/P2_CMSIS/CMSIS \
	 -I$(PROJECT_DIR)/P2_CMSIS/Device

# Archivo de linker
LINKER_FILE=$(PROJECT_DIR)/P2_CMSIS/Device/stm32f303re_ls.ld
LDFLAGS=-T $(LINKER_FILE)

# Directorio de salida
BUILD_DIR=$(PROJECT_DIR)/P2_CMSIS/build

# Objetivo principal
all: $(BUILD_DIR)/blink.elf

# Objetivo .elf
$(BUILD_DIR)/blink.elf: $(BUILD_DIR)/main.o $(BUILD_DIR)/startup_stm32f303xe.o $(BUILD_DIR)/system_stm32f3xx.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

# Compilación de archivos fuente
$(BUILD_DIR)/main.o: $(PROJECT_DIR)/P2_CMSIS/application/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/startup_stm32f303xe.o: $(PROJECT_DIR)/P2_CMSIS/Device/startup_stm32f303xe.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/system_stm32f3xx.o: $(PROJECT_DIR)/P2_CMSIS/Device/system_stm32f3xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpieza de archivos generados
clean: 
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf

# Cargar el archivo en el microcontrolador
load:
	openocd -f board/stm32f3discovery.cfg
