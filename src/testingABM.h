/*
 * testingABM.h
 * Author: Gabriel Servia
 */

#ifndef TESTINGABM_H_
#define TESTINGABM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"

void testing_salonAdd(Salon* list, int len, int i, int id, char* name, char* address, int type, int* lastIdSalon, int* flagSalonAdded);

void testing_arcadeAdd(Arcade* list, int len, int i, int id, char* nationality, int typeOfSound, int numberOfPlayers, int maxCapacityOfCoins,
						char* gameName, int idSalon, int* lastIdArcade, int* flagArcadeAdded);

#endif /* TESTINGABM_H_ */
