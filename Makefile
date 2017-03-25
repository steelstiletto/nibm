ARCH		= x86_64
CC		= gcc

OBJS		= nibm.o action_demo.o
TARGET		= nibm.efi

EFIINC		= /usr/include/efi
EFIINCS		= -I$(EFIINC) -I$(EFIINC)/$(ARCH) -I$(EFIINC)/protocol
LIB		= /usr/lib
EFI_CRT_OBJS	= $(LIB)/crt0-efi-$(ARCH).o
EFI_LDS		= $(LIB)/elf_$(ARCH)_efi.lds

CFLAGS		= $(EFIINCS) -fno-stack-protector -fpic -fshort-wchar \
		  -mno-red-zone -Wall -DEFI_FUNCTION_WRAPPER

LDFLAGS		= -nostdlib -znocombreloc -T $(EFI_LDS) -shared \
		  -Bsymbolic -L $(LIB) $(EFI_CRT_OBJS)

all: $(TARGET)

nibm.o: config.h

config.h: config.def.h
	@echo creating $@ from config.def.h
	@cp config.def.h $@

nibm.so: $(OBJS)
	ld $(LDFLAGS) $(OBJS) -o $@ -l:libefi.a -l:libgnuefi.a

%.efi: %.so
	objcopy -j .text -j .sdata -j .data -j .dynamic \
		-j .dynsym -j .rel -j .rela -j .reloc \
		--target=efi-app-$(ARCH) $^ $@

.PHONY: clean clean-build

clean:
	@rm -f nibm.o nibm.so nibm.efi config.h

clean-build:
	@rm -f nibm.o nibm.so config.h
