# Demo action, supposedly it loads fs0:/refind.efi...
#   Maybe it will eventually.
#include <efi.h>
#include <efilib.h>

EFI_STATUS do_demo(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable, char *args) {
	InitializeLib(ImageHandle, SystemTable);
	Print(L"Hello, world!\n");
	return EFI_SUCCESS;
}
