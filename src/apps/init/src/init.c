/*
 * Copyright 2016, atraari
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE" for details.
 *
 */

#include <stdio.h>
#include <playground/stub.h>

int main(void)
{
    printf("Init started...\n");
    playground_stub();
    printf("Init exiting...\n");
    return 0;
}

void exit() {
	for(;;);
}
