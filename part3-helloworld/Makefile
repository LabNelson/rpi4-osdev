CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib -nostartfiles
GCCPATH = ../../gcc-arm-10.3-2021.07-mingw-w64-i686-aarch64-none-elf/bin
BOOTMNT ?= /media/cvdeveloper/bootfs

all: clean kernel8.img

boot.o: boot.S
	$(GCCPATH)/aarch64-none-elf-gcc.exe $(GCCFLAGS) -c boot.S -o boot.o

%.o: %.c
	$(GCCPATH)/aarch64-none-elf-gcc.exe $(GCCFLAGS) -c $< -o $@

kernel8.img: boot.o $(OFILES)
	$(GCCPATH)/aarch64-none-elf-ld.exe -nostdlib boot.o $(OFILES) -T link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy.exe -O binary kernel8.elf kernel8-rpi4.img
	
	cp kernel8-rpi4.img $(BOOTMNT)/kernel8-rpi4.img
	cp config.txt $(BOOTMNT)/
	sync

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true
