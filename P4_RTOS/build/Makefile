# Directorio base del proyecto
PROJECT_DIR=/home/carlos/Documents/EmbeddedSystemsProgrammingOnARMCortexM3-M4Processor

# Compilador y opciones
CC=arm-none-eabi-gcc
CFLAGS=-mcpu=cortex-m4 -mthumb -nostdlib -O0 -mfloat-abi=hard -mfpu=fpv4-sp-d16
CPPFLAGS=-DSTM32F303xE \
	 -DUSE_HAL_DRIVER \
	 -I$(PROJECT_DIR)/P4_RTOS/application \
	 -I$(PROJECT_DIR)/P4_RTOS/CMSIS \
	 -I$(PROJECT_DIR)/P4_RTOS/Device \
	 -I$(PROJECT_DIR)/P4_RTOS/Drivers/Inc \
	 -I$(PROJECT_DIR)/P4_RTOS/FreeRTOS/include
	 
# Archivo de linker
LINKER_FILE=$(PROJECT_DIR)/P4_RTOS/Device/STM32F303RETx_FLASH.ld
LDFLAGS=-T $(LINKER_FILE)

# Directorio de salida
BUILD_DIR=$(PROJECT_DIR)/P4_RTOS/build

# Objetivo principal
all: $(BUILD_DIR)/blink.elf

# Objetivo .elf
$(BUILD_DIR)/blink.elf: $(BUILD_DIR)/main.o $(BUILD_DIR)/startup_stm32f303xe.o $(BUILD_DIR)/system_stm32f3xx.o \
	$(BUILD_DIR)/stm32f3xx_hal.o $(BUILD_DIR)/stm32f3xx_hal_gpio.o $(BUILD_DIR)/stm32f3xx_hal_rcc.o \
	$(BUILD_DIR)/stm32f3xx_hal_cortex.o $(BUILD_DIR)/cmsis_os2.o \
	$(BUILD_DIR)/queue.o $(BUILD_DIR)/tasks.o $(BUILD_DIR)/list.o $(BUILD_DIR)/port.o $(BUILD_DIR)/heap_1.o \
	$(BUILD_DIR)/timers.o $(BUILD_DIR)/event_groups.o 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@
	
#$(BUILD_DIR)/blink.bin: $(BUILD_DIR)/blink.elf
#	arm-none-eabi-objcopy -O binary blink.elf blink.bin

# Compilación de archivos fuente
$(BUILD_DIR)/main.o: $(PROJECT_DIR)/P4_RTOS/application/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/startup_stm32f303xe.o: $(PROJECT_DIR)/P4_RTOS/Device/startup_stm32f303xe.s
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/system_stm32f3xx.o: $(PROJECT_DIR)/P4_RTOS/Device/system_stm32f3xx.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Compilación de archivos HAL
$(BUILD_DIR)/stm32f3xx_hal.o: $(PROJECT_DIR)/P4_RTOS/Drivers/Src/stm32f3xx_hal.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_hal_gpio.o: $(PROJECT_DIR)/P4_RTOS/Drivers/Src/stm32f3xx_hal_gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/stm32f3xx_hal_rcc.o: $(PROJECT_DIR)/P4_RTOS/Drivers/Src/stm32f3xx_hal_rcc.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/stm32f3xx_hal_cortex.o: $(PROJECT_DIR)/P4_RTOS/Drivers/Src/stm32f3xx_hal_cortex.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

#v$(BUILD_DIR)/stm32f3xx_it.o: $(PROJECT_DIR)/P4_RTOS/Device/stm32f3xx_it.c
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
#$(BUILD_DIR)/cmsis_os1.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/cmsis_os1.c 
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/cmsis_os2.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/cmsis_os2.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/queue.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/queue.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/tasks.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/tasks.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/list.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/list.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/port.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/port.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR)/heap_1.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/heap_1.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/timers.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/timers.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	
$(BUILD_DIR)/event_groups.o: $(PROJECT_DIR)/P4_RTOS/FreeRTOS/source/event_groups.c 
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Limpieza de archivos generados
clean: 
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin

# Cargar el archivo en el microcontrolador
load:
	openocd -f board/stm32f3discovery.cfg

