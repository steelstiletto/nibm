ARCH		= $(shell uname -m | sed s,i[3456789]86,ia32,)

OBJS		= nibm.o
TARGET		= nibm.efi

EFIINC		= /usr/include/efi
EFIINCS		= -I$(EFIINC) -I$(EFIINC)/$(ARCH) -I$(EFIINC)/protocol
LIB		= /usr/lib
EFI_CRT_OBJS	= $(LIB)/crt0-efi-$(ARCH).o
EFI_LDS		= $(LIB)/elf_$(ARCH)_efi.lds

CFLAGS		= $(EFIINCS) -fno-stack-protector -fpic -fshort-wchar -mno-red-zone -Wall

ifeq ($(ARCH),x86_64)
	CFLAGS	+= -DEFI_FUNCTION_WRAPPER
endif

LDFLAGS		= -nostdlib -znocombreloc -T $(EFI_LDS) -shared \
		  -Bsymbolic -L $(LIB) $(EFI_CRT_OBJS)

all: $(TARGET)

nibm.so: $(OBJS)
	ld $(LDFLAGS) $(OBJS) -o $@ -l:libefi.a -l:libgnuefi.a

%.efi: %.so
	objcopy -j .text -j .sdata -j .data -j .dynamic \
		-j .dynsym -j .rel -j .rela -j .reloc \
		--target=efi-app-$(ARCH) $^ $@