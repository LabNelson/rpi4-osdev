CFILES = $(wildcard *.c lib/*.c kernel/*.c net/*.c)
SFILES = $(wildcard boot/*.S lib/*.S kernel/*.S)
OFILES = $(CFILES:.c=.o) $(SFILES:.S=.o)
GCCFLAGS = -Wall -O0 -ffreestanding -nostdlib -nostartfiles
GCCPATH = ../../gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin
BOOTMNT ?= /media/cvdeveloper/bootfs

all: clean kernel8.img

%.o: %.c
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

%.o: %.S
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: $(OFILES)
	$(GCCPATH)/aarch64-none-elf-ld -nostdlib $(OFILES) -T boot/link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img
	
	cp kernel8.img $(BOOTMNT)/kernel8.img
	cp config.txt $(BOOTMNT)/
	sync

clean:
	/bin/rm kernel8.elf */*.o *.img > /dev/null 2> /dev/null || true
