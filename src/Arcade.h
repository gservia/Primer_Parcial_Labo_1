/*
 * Arcade.h
 * Author: Gabriel Servia
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

// Valores isEmpty:
#define LOAD 0
#define EMPTY 1
// Valores typeOfSound:
#define MONO 1
#define ESTEREO 2

typedef struct {
	char nationality[128];
	int typeOfSound;
	int numberOfPlayers;
	int maxCapacityOfCoins;
	char gameName[63];
	int id;
	int idSalon;
	int isEmpty; // 0: Load | 1: Empty
}Arcade;

int arcade_initList(Arcade* list, int len);

int arcade_findEmptyPlace(int* emptyPlace, Arcade* list, int len);

int arcade_add(Arcade* list, int len, int emptyPosition, int idSalon);

int arcade_edit(Arcade* list, int len, Arcade* pArcade);

int arcade_printGameNameList(Arcade* list, int len);

int arcade_printOne(Arcade* list, int position);

int arcade_printList(Arcade* list, int len);

int arcade_findById(Arcade* list, int len, int id);

int arcade_remove(Arcade* list, int len, int id);

#endif /* ARCADE_H_ */
