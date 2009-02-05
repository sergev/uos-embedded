/*
 * Testing task switching.
 */
#include "runtime/lib.h"
#include "kernel/uos.h"

ARRAY (task, 200);

void hello (void *arg)
{
	for (;;) {
		debug_printf ("Hello from `%S'! (Press Enter)\n", arg);
		debug_getchar ();
	}
}

void uos_init (void)
{
	/* Baud 19200. */
	outw (((int) (KHZ * 1000L / 19200) + 8) / 16 - 1, UBRR);

	debug_puts ("\nTesting task.\n");
	task_create (hello, "task", "hello", 1, task, sizeof (task));
}