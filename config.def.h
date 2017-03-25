/* define actions used by including the correct file */
#include "action_demo.h"

/* These define how to store actions and chains */
struct Action {
	EFI_STATUS (*func) (EFI_HANDLE, EFI_SYSTEM_TABLE*, char*);
	char *args;
};
struct Chain {
	struct Action *actions;
	int size;
};

/* create the master chain */
static const struct Chain masterChain[1] = { { &(struct Action){do_demo, ""}, 1 } };
