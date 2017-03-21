/* define actions here by including the correct file */
/* #include "action_demo.h" */

/* These define how to store actions and chains */
typedef int (*ActionFunc)(string);
typedef struct Action {
	ActionFunc *func;
	string args;
} Action;
typedef struct Chain {
	*Action[] actions;
	int size;
} Chain;

/* define each chain here */
/* static const *Action[1] _chain1 = {
 *	{ ActionFunction, ActionArgs }
 * } */
static const Chain _chain1 = {
	actions = (Action){ func = do_demo;
			    args = ""; };
	size = 1;
}

/* create the master chain */
/* static const chain_struct masterChain = {
 *	{ _chain#, _chain#(length) }
 * } */
static const *Chain[1] masterChain = {
	_chain1;
}
