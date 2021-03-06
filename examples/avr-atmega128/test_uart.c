/*
 * Testing UART.
 */
#include <runtime/lib.h>
#include <kernel/uos.h>
#include <uart/uart.h>

ARRAY (task, 200);
uart_t uart;

void hello (void *data)
{
	for (;;) {
		puts (&uart, "\nHello, World! ");
		getchar (&uart);
	}
}

void uos_init (void)
{
/*UBRR = ((int) (KHZ * 1000L / 9600) + 8) / 16 - 1;*/
	uart_init (&uart, 0, 90, KHZ, 9600);
	task_create (hello, 0, "hello", 1, task, sizeof (task));
}
