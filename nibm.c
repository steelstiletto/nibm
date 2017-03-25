#include <efi.h>
#include <efilib.h>
#include "config.h"

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);
	Print(L"Hello, world!\n");
	return EFI_SUCCESS;

	/* Main loop */
	/* for chain in masterchain (defined in config.h) */
	int masterChainSize = (sizeof(masterChain) / sizeof(*masterChain));
	for (int i=0; i < masterChainSize; i++) {
		struct Chain curChain = masterChain[i];
		for (int j=0; j < curChain.size; j++) {
			if(!curChain.actions[j].func(ImageHandle, SystemTable, curChain.actions[j].args))
				break;
		}
	}
}
