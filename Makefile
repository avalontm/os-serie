src_source_files := $(shell find src -name *.c)
src_object_files:= $(patsubst src/%.c, build/%.o, $(src_source_files))

boot_asm_source_files := $(shell find src/boot -name *.asm)
boot_asm_object_files := $(patsubst src/boot/%.asm, build/boot/%.bin, $(boot_asm_source_files))

asm_source_files := $(shell find src/intr -name *.asm)
asm_object_files := $(patsubst src/intr/%.asm, build/intr/%.o, $(asm_source_files))

object_files := $(asm_object_files) $(src_object_files) 

$(boot_asm_object_files): build/%.bin : src/%.asm
	mkdir -p $(dir $@) && \
	nasm -f bin $(patsubst build/%.bin, src/%.asm, $@) -o $@

$(asm_object_files): build/%.o : src/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/%.o, src/%.asm, $@) -o $@

$(src_object_files): build/%.o : src/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src -ffreestanding $(patsubst build/%.o, src/%.c, $@) -o $@

.PHONY: build clean

build: $(object_files) $(boot_asm_source_files)
	mkdir -p dist/x86_64 && \
	x86_64-elf-ld -n -o dist/x86_64/kernel.bin -T targets/x86_64/linker.ld $(object_files) && \
	cp dist/x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/kernel.iso targets/x86_64/iso

clean:
	rm -r build/* 