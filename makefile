# Name of the target (files will be named like that)
TARGET=animated_eyes

# Name of the Microcontroller
MCU=atmega2560

# Clock of the Microcontroller (Hz)
F_CPU=16000000

# Fuses
L_FUSE=0xFF
H_FUSE=0xD8
E_FUSE=0xFF

# Target where the files should be placed
BUILDPATH=./build

# List of all sources (only source-files)
SOURCES= main.c
SOURCES+= ssd1306.c
SOURCES+= i2cmaster.c
SOURCES+= eye.c

# Progammer
# Settings for an Arduino Mega 2560 Board
PROGRAMMER=stk500v2
PORT=-P/dev/ttyACM0
BAUD=-B115200

OBJECTS=$(SOURCES:%.c=$(BUILDPATH)/%.o)
CFLAGS  = -c
CFLAGS += -Os
CFLAGS += -Wall
CFLAGS += -fpack-struct
CFLAGS += -fshort-enums
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -std=gnu99
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -DF_CPU=$(F_CPU)UL
LDFLAGS=



all: clean hex eeprom

hex: $(TARGET).hex size

eeprom: $(TARGET)_eeprom.hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex -j .data -j .text $(BUILDPATH)/$(TARGET).elf $(BUILDPATH)/$(TARGET).hex

$(TARGET)_eeprom.hex: $(TARGET).elf
	avr-objcopy -O ihex -j .eeprom --change-section-lma .eeprom=1 $(BUILDPATH)/$(TARGET).elf $(BUILDPATH)/$(TARGET)_eeprom.hex

$(TARGET).elf: $(OBJECTS)
	avr-gcc $(LDFLAGS) -mmcu=$(MCU) $(OBJECTS) -o $(BUILDPATH)/$(TARGET).elf


$(BUILDPATH)/%.o: %.c
	mkdir -p $(BUILDPATH)
	avr-gcc $(CFLAGS) -mmcu=$(MCU) $< -o $@


size:
	avr-size --mcu=$(MCU) -C $(BUILDPATH)/$(TARGET).elf

flash_hex:
	avrdude -p $(MCU) $(PORT) $(BAUD) -c $(PROGRAMMER) -U flash:w:$(BUILDPATH)/$(TARGET).hex:a

read_fuses:
	avrdude -p $(MCU) $(PORT) $(BAUD) -c $(PROGRAMMER) -U lfuse:r:-:i

flash_fuses:
	avrdude -p $(MCU) $(PORT) $(BAUD) -c $(PROGRAMMER) -U lfuse:w:$(L_FUSE):m -U hfuse:w:$(H_FUSE):m

clean_tmp:
	rm -rf $(BUILDPATH)/*.o
	rm -rf $(BUILDPATH)/*.elf

clean:
	rm -rf $(BUILDPATH)/*.o
	rm -rf $(BUILDPATH)/*.elf
	rm -rf $(BUILDPATH)/*.hex
