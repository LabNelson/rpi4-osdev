CFILES = $(wildcard *.c lib/*.c)
OFILES = $(CFILES:.c=.o)
GCCFLAGS = -Wall -O2 -ffreestanding -nostdinc -nostdlib
GCCPATH = ../../gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin


all: clean kernel8.img

boot/boot.o: boot/boot.S
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c boot/boot.S -o boot/boot.o

bin/BCM4345C0.o : bin/BCM4345C0.hcd
	$(GCCPATH)/aarch64-none-elf-objcopy -I binary -O elf64-littleaarch64 -B aarch64 $< $@
	
bin/audio.o : bin/audio.bin
	$(GCCPATH)/aarch64-none-elf-objcopy -I binary -O elf64-littleaarch64 -B aarch64 $< $@

%.o: %.c
	$(GCCPATH)/aarch64-none-elf-gcc $(GCCFLAGS) -c $< -o $@

kernel8.img: boot/boot.o $(OFILES) bin/BCM4345C0.o bin/audio.o
	$(GCCPATH)/aarch64-none-elf-ld -nostdlib boot/boot.o $(OFILES) bin/BCM4345C0.o bin/audio.o -T boot/link.ld -o kernel8.elf
	$(GCCPATH)/aarch64-none-elf-objcopy -O binary kernel8.elf kernel8.img
clean:
	/bin/rm kernel8.elf *.o bin/*.o boot/*.o *.img > /dev/null 2> /dev/null || true
