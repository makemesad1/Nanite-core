CC = arm-none-eabi-g++
LD = arm-none-eabi-g++

LD_SCRIPT = MEMORY.ld

CC_FLAGS = -c -O2  -Iinc -mthumb -mfloat-abi=hard -mcpu=cortex-m7 -ffunction-sections -fno-exceptions -fno-non-call-exceptions -fno-rtti -fno-use-cxa-atexit -ffreestanding -fno-common -nostartfiles -nodefaultlibs -nostdlib
LD_FLAGS = -T$(LD_SCRIPT) -Wl,--gc-sections -nostartfiles -nodefaultlibs -nostdlib -fno-exceptions -Llib $(LIBS)

SRC_FOLDER = src

OUTPUT = bin/Nanite.elf 


SRC = src/nanitecrt.c src/rcc.cpp src/sketch.cpp

OBJ = src/nanitecrt.o src/rcc.o src/sketch.o


all: bin $(OUTPUT)


$(OUTPUT): $(OBJ) 
	$(LD) $(LD_FLAGS) -o $@ $(OBJ)


%.o: %.c
	$(CC) $(CC_FLAGS)  $< -o $@

%.o: %.cpp
	$(CC) $(CC_FLAGS)  $< -o $@


clean:
	rm $(OBJ)

clean_k:
	rm bin/Nanite.elf
	rm bin/Nanite.bin

d:
	arm-none-eabi-objdump -d bin/Nanite.elf > DIS.txt

_th:
	arm-none-eabi-objcopy -O binary bin/Nanite.elf bin/Nanite.bin
	hexdump -v -e '"%08_ax: "' -e ' 4/4 "%08x " " |"' -e '16/1 "%_p" "|\n"' bin/Nanite.bin > HEXMAP.txt

bin:
	mkdir bin