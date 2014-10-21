/*
 * memory.h
 *
 *  Created on: Oct 21, 2014
 *      Author: javier
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include "ajtcl.h"
AJ_InterfaceDescription* AJ_InterfacesCreate();
AJ_Status AJ_InterfacesAdd(AJ_InterfaceDescription *, AJ_InterfaceDescription *);
AJ_InterfaceDescription* AJ_InterfaceDescriptionCreate(char *);
AJ_Status AJ_InterfaceDescriptionAdd(AJ_InterfaceDescription *, char *);

#endif /* MEMORY_H_ */
