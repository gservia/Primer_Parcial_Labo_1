/*
 * testingABM.c
 * Author: Gabriel Servia
 */
#include "testingABM.h"

/**
 * \brief Forcing add to Salon list
 */
void testing_salonAdd(Salon* list, int len, int i, int id, char* name, char* address, int type, int* lastIdSalon, int* flagSalonAdded)
{
	if (list != NULL && len > 0 && i < len && i >= 0)
	{
		list[i].id = id;
		strncpy(list[i].name, name, sizeof(list[i].name));
		strncpy(list[i].address, address, sizeof(list[i].address));
		list[i].type = type;
		list[i].isEmpty = LOAD;

		*lastIdSalon = id;
		*flagSalonAdded = id;
	}
}

/**
 * \brief Forcing add to Arcade list
 */
void testing_arcadeAdd(Arcade* list, int len, int i, int id, char* nationality, int typeOfSound, int numberOfPlayers, int maxCapacityOfCoins,
						char* gameName, int idSalon, int* lastIdArcade, int* flagArcadeAdded)
{
	if (list != NULL && len > 0 && i < len && i >= 0)
	{
		list[i].id = id;
		strncpy(list[i].nationality, nationality, sizeof(list[i].nationality));
		list[i].typeOfSound = typeOfSound;
		list[i].numberOfPlayers = numberOfPlayers;
		list[i].maxCapacityOfCoins = maxCapacityOfCoins;
		strncpy(list[i].gameName, gameName, sizeof(list[i].gameName));
		list[i].idSalon = idSalon;
		list[i].isEmpty = LOAD;

		*lastIdArcade = id;
		*flagArcadeAdded = id;
	}
}

