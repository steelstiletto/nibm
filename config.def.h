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

/* define each action in specific here */
static const struct Action a_demo = {do_demo, ""};

/* define each chain here */
static const struct Chain _chain1 = {
	,
	1
};

/* create the master chain */
static const struct Chain[1] masterChain = {
	_chain1;
};
