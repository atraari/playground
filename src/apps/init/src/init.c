/*
 * Copyright 2016, atraari
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE" for details.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <playground/stub.h>
#include <playground/dprintf.h>

const char* dprintfServerName = "INIT";
int dprintfServerColour = 33;

int main(void)
{
    SET_MUSLC_SYSCALL_TABLE;
    
    dprintf("Init started...\n");
    playground_stub();
    dprintf("Init exiting...\n");
    return 0;
}
