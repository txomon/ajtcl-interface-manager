/*
 * main.c
 *
 *  Created on: Oct 21, 2014
 *      Author: javier
 */

#include "memory.h"

int main(int argc, char **argv)
{
    AJ_InterfaceDescription *data;
    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Bus.sample");
    if(!data)
        return 1;
    AJ_InterfaceDescriptionAdd(&data, "?Dummy foo<i");
    AJ_InterfaceDescriptionAdd(&data, "?Dummy2 fee<i");
    AJ_InterfaceDescriptionAdd(&data, "?cat inStr1<s inStr2<s outStr>s");

    return 0;
}
