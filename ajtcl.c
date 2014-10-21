/*
 * ajtcl.c
 *
 *  Created on: Oct 21, 2014
 *      Author: javier
 */

#include "ajtcl.h"


void* AJ_Malloc(size_t sz)
{
    return malloc(sz);
}
void* AJ_Realloc(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

void AJ_Free(void* mem)
{
    if (mem) {
        free(mem);
    }
}
