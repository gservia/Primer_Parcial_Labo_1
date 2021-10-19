/*
 * informes.c
 * Author: Gabriel Servia
 */
#include "informes.h"


/**
 * \brief List of salones with more than 4 arcades
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_salonesOverFourArcades(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade)
{
	int state = -1;
	int i;
	int j;
	int k;
	int counter;
	Salon salonListAux[lenSalon];

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		k = 0;
		printf("\nSALONES CON MAS DE 4 ARCADES:\n");
		for (i = 0; i < lenSalon; i++)
		{
			counter = 0;

			if (salonList[i].isEmpty == LOAD)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (arcadeList[j].isEmpty == LOAD)
					{
						if (arcadeList[j].idSalon == salonList[i].id)
						{
							counter++;
						}
					}
				}
				if (counter > 4)
				{
					salonListAux[k] = salonList[i];
					k++;
					state = 0;
				}
			}
		}
		if (state == 0)
		{
			salon_printList(salonListAux, k);
		}
	}
	return state;
}


/**
 * \brief List of arcades with more than 2 number of players
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_arcadesOverTwoPlayers(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade)
{
	int state = -1;
	int i;
	int position;
	char nameSalonAux[128];

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		printf("\nLISTA DE ARCADES PARA MAS DE 2 JUGADORES:\n");
		printf("ID	| JUGADORES	| NOMBRE DEL JUEGO	| NOMBRE DEL SALON\n");
		for (i = 0; i < lenArcade; i++)
		{
			if (arcadeList[i].isEmpty == LOAD)
			{
				if (arcadeList[i].numberOfPlayers > 2)
				{
					position = salon_findById(salonList, lenSalon, arcadeList[i].idSalon);
					strncpy(nameSalonAux, salonList[position].name, sizeof(nameSalonAux));

					printf("%d	| %d		| %s		| %s\n", arcadeList[i].id, arcadeList[i].numberOfPlayers,
							arcadeList[i].gameName, nameSalonAux);
					state = 0;
				}
			}
		}
	}
	return state;
}


/**
 * \brief List information of one requested Salon
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \param lastIdSalon Last Salon ID input in system
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_dataListOfSalon(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon)
{
	int state = -1;
	int idToFind;
	int position;
	int i;
	int numberOfArcades;
	char typeAux[9];

	numberOfArcades = 0;

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		printf("\nLISTA DE SALONES\n");
		salon_printList(salonList, lenSalon);

		if (utn_getInt(&idToFind, "\nSELECCIONE UN ID PARA MOSTRAR INFORMACION: ", "\nError: Comando no valido.\n", 1, lastIdSalon, 0) == 0)
		{
			position = salon_findById(salonList, lenSalon, idToFind);

			for (i = 0; i < lenArcade; i++)
			{

				if (arcadeList[i].isEmpty == LOAD && arcadeList[i].idSalon == idToFind)
				{
					numberOfArcades++;
				}
			}

			switch (salonList[position].type)
			{
				case SHOPPING:
					strncpy(typeAux, "SHOPPING", sizeof(typeAux));
						break;
				case LOCAL:
					strncpy(typeAux, "LOCAL", sizeof(typeAux));
						break;
			}

			printf("\nNOMBRE		| TIPO		| DIRECCION		| CANTIDAD DE ARCADES ASIGNADOS\n");
			printf("%s	| %s		| %s		| %d\n", salonList[position].name, typeAux, salonList[position].address, numberOfArcades);
			state = 0;
		}
		else
		{
			printf("\n== ERROR: ID no existe ==\n");
		}
	}
	return state;
}


/**
 * \brief List information of one requested Salon
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \param lastIdSalon Last Salon ID input in system
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_arcadesOfOneSalon(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon)
{
	int state = -1;
	int idToFind;
	int position;
	int i;
	char typeAux[9];
	int flagAtLeastOneArcade;

	flagAtLeastOneArcade = -1;

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		printf("\nLISTA DE SALONES\n");
		salon_printList(salonList, lenSalon);

		if (utn_getInt(&idToFind, "\nSELECCIONE UN ID PARA MOSTRAR INFORMACION: ", "\nError: Comando no valido.\n", 1, lastIdSalon, 0) == 0)
		{
			position = salon_findById(salonList, lenSalon, idToFind);

			switch (salonList[position].type)
			{
				case SHOPPING:
					strncpy(typeAux, "SHOPPING", sizeof(typeAux));
						break;
				case LOCAL:
					strncpy(typeAux, "LOCAL", sizeof(typeAux));
						break;
			}

			printf("\nNOMBRE DE SALON	| TIPO\n");
			printf("%s	| %s\n", salonList[position].name, typeAux);

			printf("\nLISTA DE ARCADES QUE TIENE ASIGNADOS:\n");
			printf("\nID	| NACIONALIDAD	| TIPO DE SONIDO	| JUGADORES	| CAP. MAX. DE FICHAS	| NOMBRE DEL JUEGO | SALON ASIGNADO\n");
			for (i = 0; i < lenArcade; i++)
			{
				if (arcadeList[i].isEmpty == LOAD && arcadeList[i].idSalon == idToFind)
				{
					arcade_printOne(arcadeList, i);
					flagAtLeastOneArcade = 0;
				}
			}
			if (flagAtLeastOneArcade == -1)
			{
				printf("\n== Salon ingresado no tiene arcades asignados ==\n");
			}
			state = 0;
		}
		else
		{
			printf("\n== ERROR: ID no existe ==\n");
		}
	}
	return state;
}


/**
 * \brief Print Salon info with more Arcades assigned
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_printSalonWithMoreArcades(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade)
{
	int state = -1;
	int i;
	int j;
	int counterArcades;
	int maxArcades;
	int idSalonMaxArcades;
	int flagFirstInput;
	int position;

	flagFirstInput = 0;

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		for (i = 0; i < lenSalon; i++)
		{
			counterArcades = 0;

			if (salonList[i].isEmpty == LOAD)
			{
				for (j = 0; j < lenArcade; j++)
				{
					if (arcadeList[j].isEmpty == LOAD)
					{
						if (arcadeList[j].idSalon == salonList[i].id)
						{
							counterArcades++;
						}
					}
				}
				if (flagFirstInput == 0)
				{
					maxArcades = counterArcades;
					idSalonMaxArcades = salonList[i].id;
					flagFirstInput = 1;
				}
				else
				{
					if (counterArcades > maxArcades)
					{
						maxArcades = counterArcades;
						idSalonMaxArcades = salonList[i].id;
					}
				}
			}
		}

		position = salon_findById(salonList, lenSalon, idSalonMaxArcades);

		printf("\nSALON CON LA MAYOR CANTIDAD DE ARCADES:\n");
		printf("\nID	| NOMBRE		| DIRECCION		| TIPO\n");
		salon_printOne(salonList, position);
		printf("\nCANTIDAD DE ARCADES ASIGNADOS: %d\n", maxArcades);

		state = 0;
	}
	return state;
}


/**
 * \brief List information of one requested Salon
 * \param salonList Salon*
 * \param lenSalon int
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \param lastIdSalon Last Salon ID input in system
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_salonMaxIncome(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon)
{
	int state = -1;
	int i;
	int idToFind;
	int position;
	char typeAux[9];
	float price;
	float incomePerArcade;
	float totalIncome;

	totalIncome = 0;

	if (salonList != NULL && lenSalon > 0 && arcadeList != NULL && lenArcade > 0)
	{
		printf("\nLISTA DE SALONES\n");
		salon_printList(salonList, lenSalon);

		if (utn_getInt(&idToFind, "\nSELECCIONE UN ID PARA MOSTRAR INFORMACION: ", "\nError: Comando no valido.\n", 1, lastIdSalon, 0) == 0)
		{
			position = salon_findById(salonList, lenSalon, idToFind);

			if (salonList[position].isEmpty == LOAD)
			{
				utn_getFloat(&price, "\nINGRESAR EL PRECIO POR FICHA $: ", "\nError: Comando no valido.\n", 0, 999999, 0);

				for (i = 0; i < lenArcade; i++)
				{
					if (arcadeList[i].isEmpty == LOAD && arcadeList[i].idSalon == idToFind)
					{
						incomePerArcade = arcadeList[i].maxCapacityOfCoins * price;
						totalIncome += incomePerArcade;
					}
				}

				switch (salonList[position].type)
				{
					case SHOPPING:
						strncpy(typeAux, "SHOPPING", sizeof(typeAux));
							break;
					case LOCAL:
						strncpy(typeAux, "LOCAL", sizeof(typeAux));
							break;
				}

				printf("\nNOMBRE DE SALON	| DIRECCION		| TIPO\n");
				printf("%s	| %s		| %s\n", salonList[position].name, salonList[position].address, typeAux);
				printf("\nMONTO MAXIMO EN PESOS QUE PUEDE RECAUDAR: $ %.2f\n", totalIncome);
				state = 0;
			}
		}
	}
	return state;
}


/**
 * \brief Print number of Arcades that contains requested game
 * \param arcadeList Arcade*
 * \param lenArcade int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int info_numberOfArcadesWithGame(Arcade* arcadeList, int lenArcade)
{
	int state = -1;
	int i;
	char gameNameAux[63];
	char gameNameInput[63];
	int counter;

	counter = 0;

	if (arcadeList != NULL && lenArcade > 0)
	{
		printf("\nLISTA DE JUEGOS\n");
		arcade_printGameNameList(arcadeList, lenArcade);

		if (utn_getText(gameNameAux, 63, "\nINGRESAR UN NOMBRE DE LA LISTA DE VIDEOJUEGOS (Respetar mayusculas y minusculas): ",
				"\nERROR: Debe ingresar un nombre de la lista de videojuegos, con maximo de 63 caracteres.\n", 0) == 0)
		{
			strncpy(gameNameInput, gameNameAux, sizeof(gameNameInput));

			for (i = 0; i < lenArcade; i++)
			{
				if (arcadeList[i].isEmpty == LOAD)
				{
					if (strcmp(arcadeList[i].gameName, gameNameInput) == 0)
					{
						counter++;
					}
				}
			}
			if (counter == 0)
			{
				printf("\nEL VIDEOJUEGO INGRESADO NO SE ENCUENTRA EN SISTEMA. VUELVA INTENTAR\n");
			}
			else
			{
				printf("\nCANTIDAD DE ARCADES QUE CONTIENEN EL VIDEOJUEGO INGRESADO: %d\n", counter);
				state = 0;
			}
		}
	}
	return state;
}


