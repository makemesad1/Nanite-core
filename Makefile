CC = arm-none-eabi-g++
LD = arm-none-eabi-g++

LD_SCRIPT = MEMORY.ld

CC_FLAGS = -c  -Iinc -mthumb -mfloat-abi=hard -mcpu=cortex-m7 -ffunction-sections
LD_FLAGS = -T$(LD_SCRIPT) -Wl,--gc-sections -nostartfiles -nodefaultlibs -nostdlib -Llib $(LIBS)

SRC_FOLDER = src

OUTPUT = bin/Nanite.elf 


SRC = src/init.c

OBJ = $(SRC:.c=.o)

all: bin $(OUTPUT)

$(OUTPUT): $(OBJ) 
	$(LD) $(LD_FLAGS) -o $@ $(OBJ)

## BUILD OBJECT HERE ##
%.o: %.c
	$(CC) $(CC_FLAGS)  $< -o $@

clean:
	rm $(OBJ)

clean_k:
	rm bin/Nanite.elf
	rm bin/Nanite.bin

_th:
	arm-none-eabi-objcopy -O binary bin/Nanite.elf bin/Nanite.bin
	hexdump -v -e '"%08_ax: "' -e ' 4/4 "%08x " " |"' -e '16/1 "%_p" "|\n"' bin/Nanite.bin > HEXMAP.txt

bin:
	mkdir bin