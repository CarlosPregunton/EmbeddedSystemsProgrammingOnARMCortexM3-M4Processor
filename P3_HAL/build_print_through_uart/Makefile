# Directorio base del proyecto
PROJECT_DIR=/home/carlos/Documents/EmbeddedSystemsProgrammingOnARMCortexM3-M4Processor

# Compilador y opciones
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib -O0
CPPFLAGS=-DSTM32F303xE \
	 -DUSE_HAL_DRIVER \
	 -I$(PROJECT_DIR)/P3_HAL/blinking_led \
	 -I$(PROJECT_DIR)/P3_HAL/CMSIS \
	 -I$(PROJECT_DIR)/P3_HAL/Device \
	 -I$(PROJECT_DIR)/P3_HAL/Drivers/Inc # Incluir la carpeta Drivers
	
# Archivo de linker
LINKER_FILE=$(PROJECT_DIR)/P3_HAL/Device/STM32F303RETx_FLASH.ld
LDFLAGS=-T $(LINKER_FILE)

# Directorio de salida
BUILD_DIR=$(PROJECT_DIR)/P3_HAL/build_print_through_uart

# Objetivo principal
all: $(BUILD_DIR)/blink.elf $(BUILD_DIR)/blink.bin

$(BUILD_DIR)/blink.bin: $(BUILD_DIR)/blink.elf
	arm-none-eabi-objcopy -O binary $(BUILD_DIR)/blink.elf $(BUILD_DIR)/blink.bin

# Objetivo .elf
$(BUILD_DIR)/blink.elf: $(BUILD_DIR)/main.o $(BUILD_DIR)/startup_stm32f303xe.o $(BUILD_DIR)/system_stm32f3xx.o \
	$(BUILD_DIR)/stm32f3xx_hal.o $(BUILD_DIR)/stm32f3xx_hal_gpio.o $(BUILD_DIR)/stm32f3xx_hal_rcc.o \
	$(BUILD_DIR)/stm32f3xx_hal_cortex.o $(BUILD_DIR)/stm32f3xx_it.o $(BUILD_DIR)/stm32f3xx_hal_msp.o
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

# Compilación de archivos fuente
$(BUILD_DIR)/main.o: $(PROJECT_DIR)/P3_HAL/print_through_uart/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/startup_stm32f303xe.o: $(PROJECT_DIR)/P3_HAL/Device/startup_stm32f303xe.s
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/system_stm32f3xx.o: $(PROJECT_DIR)/P3_HAL/Device/system_stm32f3xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_it.o: $(PROJECT_DIR)/P3_HAL/Device/stm32f3xx_it.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_hal.o: $(PROJECT_DIR)/P3_HAL/Drivers/Src/stm32f3xx_hal.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_hal_rcc.o: $(PROJECT_DIR)/P3_HAL/Drivers/Src/stm32f3xx_hal_rcc.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/stm32f3xx_hal_cortex.o: $(PROJECT_DIR)/P3_HAL/Drivers/Src/stm32f3xx_hal_cortex.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/stm32f3xx_hal_gpio.o: $(PROJECT_DIR)/P3_HAL/Drivers/Src/stm32f3xx_hal_gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_hal_msp.o: $(PROJECT_DIR)/P3_HAL/Drivers/Src/stm32f3xx_hal_msp.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
# Limpieza de archivos generados
clean: 
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin

# Cargar el archivo en el microcontrolador
load:
	openocd -f board/stm32f3discovery.cfg

