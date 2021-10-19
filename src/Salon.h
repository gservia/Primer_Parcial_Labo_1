/*
 * Salon.h
 * Author: Gabriel Servia
 */

#ifndef SALON_H_
#define SALON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

// Valores isEmpty:
#define LOAD 0
#define EMPTY 1
// Valores type:
#define SHOPPING 1
#define LOCAL 2

typedef struct {
	char name[128];
	char address[128];
	int type;
	int id;
	int isEmpty;
}Salon;

int salon_initList(Salon* list, int len);

int salon_findEmptyPlace(int* emptyPlace, Salon* list, int len);

int salon_add(Salon* list, int len, int emptyPlace);

int salon_printOne(Salon* list, int position);

int salon_printList(Salon* list, int len);

int salon_findById(Salon* list, int len, int id);

int salon_remove(Salon* list, int len, int id); // Al eliminar un Salon, tambien se eliminan los Arcades que lo componen.

#endif /* SALON_H_ */
