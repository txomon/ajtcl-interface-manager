/*
 * memory.c
 *
 *  Created on: Oct 21, 2014
 *      Author: javier
 */

#include "memory.h"
#include <stdio.h>
#include <string.h>

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

AJ_InterfaceDescription AJ_InterfaceDescriptionCreate(char *interfaceName)
{
    char **interface;
    interface = AJ_Malloc(sizeof(char*) * 2);
    if (!interface)
        return NULL;

    interface[0] = AJ_Malloc(strlen(interfaceName) + 1);
    if (!interface[0]) {
        AJ_Free(interface);
        return NULL;
    }

    interface[1] = NULL;

    strcpy(interface[0], interfaceName);

    return (AJ_InterfaceDescription) interface;
}

AJ_Status AJ_InterfaceDescriptionAdd(AJ_InterfaceDescription *interfaceDescription, char *description)
{
    int size = 0;
    char **iter = (char **) *interfaceDescription;

    while (*iter) {
        iter++;
        size++;
    }

    iter = AJ_Realloc(*interfaceDescription, sizeof(char*) * (size + 2));
    if (!iter)
        return AJ_ERR_UNKNOWN;
    *interfaceDescription = iter;

    iter[size] = AJ_Malloc(strlen(description) + 1);
    if (!iter[size]) {
        return AJ_ERR_UNKNOWN;
    }

    strcpy(iter[size], description);

    iter[size+1] = NULL;

    return AJ_OK;
}
