/*
 * main.c
 *
 *  Created on: Oct 21, 2014
 *      Author: javier
 */

#include "memory.h"

int main(int argc, char **argv)
{
    AJ_InterfaceDescription *data, *array;

    array = AJ_InterfacesCreate();

    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Bus.sample");
    if(!data)
        return 1;
    AJ_InterfaceDescriptionAdd(&data, "?Dummy foo<i");
    AJ_InterfaceDescriptionAdd(&data, "?Dummy2 fee<i");
    AJ_InterfaceDescriptionAdd(&data, "?cat inStr1<s inStr2<s outStr>s");

    AJ_InterfacesAdd(array, data);


    data = AJ_InterfaceDescriptionCreate("org.alljoyn.Bus");
    if(!data)
        return 1;
    AJ_InterfaceDescriptionAdd(data, "!SessionLost >u");
    AJ_InterfaceDescriptionAdd(data, "!FoundAdvertisedName >s >q >s");
    AJ_InterfaceDescriptionAdd(data, "!LostAdvertisedName >s >q >s");
    AJ_InterfaceDescriptionAdd(data, "!MPSessionChanged >u >s >b");
    AJ_InterfaceDescriptionAdd(data, "?AdvertiseName <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelAdvertiseName <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?FindAdvertisedName <s >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelFindAdvertisedName <s");
    AJ_InterfaceDescriptionAdd(data, "?BindSessionPort <q <a{sv} >u >q");
    AJ_InterfaceDescriptionAdd(data, "?UnbindSessionPort <q >u");
    AJ_InterfaceDescriptionAdd(data, "?JoinSession <s <q <a{sv} >u >u >a{sv}");
    AJ_InterfaceDescriptionAdd(data, "?LeaveSession <u >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelSessionlessMessage <u >u");
    AJ_InterfaceDescriptionAdd(data, "?FindAdvertisedNameByTransport <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?CancelFindAdvertisedNameByTransport <s <q >u");
    AJ_InterfaceDescriptionAdd(data, "?SetLinkTimeout <u <u >u >u");
    AJ_InterfaceDescriptionAdd(data, "?RemoveSessionMember <us >u");
    AJ_InterfaceDescriptionAdd(data, "!SessionLostWithReason >u >u");
    AJ_InterfaceDescriptionAdd(data, "?Ping <s <u >u");

    AJ_InterfacesAdd(array, data);
    return 0;
}
