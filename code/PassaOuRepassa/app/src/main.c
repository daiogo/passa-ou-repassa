

/**
 * main.c
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "PassaOuRepassa.h"

int main(void)
{
    // Init peripherals required to run app
    POR_Init();

    // Run app
    POR_Run();

    // Return the Answer to the Ultimate Question of Life, the Universe, and Everything ;)
	return 42;
}
