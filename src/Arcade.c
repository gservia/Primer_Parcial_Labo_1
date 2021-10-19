/*
 * Arcade.c
 * Author: Gabriel Servia
 */
#include "Arcade.h"

static int getNewId(void);


/**
 * \brief To indicate that all position in the array are empty
 * \param list Arcade* Pointer to array
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int arcade_initList(Arcade* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = EMPTY;
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Find empty place in array
 * \param int* emptyPlace
 * \param Arcade* list
 * \param int len
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int arcade_findEmptyPlace(int* emptyPlace, Arcade* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == EMPTY)
			{
				*emptyPlace = i;
				state = 0;
				break;
			}
		}
	}
	return state;
}


/**
 * \brief Add in a existing list of Arcades the values in the empty position
 * \param Arcade* list
 * \param int len
 * \param int emptyPosition Receives an empty position of Arcade array
 * \param int idSalon
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int arcade_add(Arcade* list, int len, int emptyPosition, int idSalon)
{
	int state = -1;
	char nationalityAux[128];
	int typeOfSoundAux;
	int numberOfPlayersAux;
	int maxCapacityOfCoinsAux;
	char gameNameAux[63];

	if (list != NULL && len > 0)
	{
		puts("\nALTA DE ARCADE");
		if (utn_getText(nationalityAux, 128, "\nINGRESAR NACIONALIDAD DE ORIGEN: ",
				"\nERROR: Debe ingresar la nacionalidad del arcade, con maximo de 128 caracteres.\n", 0) == 0)
		{
			if (utn_getInt(&typeOfSoundAux, "SELECCIONE TIPO DE SONIDO\n 1. Mono\n 2. Estereo\nINGRESAR OPCION DESEADA: ",
						"\nERROR: Debe seleccionar entre la opcion 1 o 2.\n", 1, 2, 0) == 0)
			{
				if (utn_getInt(&numberOfPlayersAux, "INGRESAR LA CANTIDAD DE JUGADORES (Entre 1 y 8 jugadores): ",
									"\nERROR: Debe ingresar un numero que indique la cantidad de jugadores que soporta el arcade (Min: 1. Max: 8).\n",
									1, 8, 0) == 0)
				{
					if (utn_getInt(&maxCapacityOfCoinsAux, "INGRESAR LA CAPACIDAD MAXIMA DE FICHAS QUE SOPORTA (Max: 100): ",
										"\nERROR: Debe ingresar un numero que indique la capacidad de fichas que soporta el arcade (Min: 1. Max: 100).\n",
										1, 100, 0) == 0)
					{
						if (utn_getText(gameNameAux, 63, "INGRESAR EL NOMBRE DEL VIDEOJUEGO QUE CONTIENE: ",
											"\nERROR: Debe ingresar el nombre del videojuego del arcade, con maximo de 63 caracteres.\n", 0) == 0)
						{
							list[emptyPosition].id = getNewId();
							strncpy(list[emptyPosition].nationality, nationalityAux, sizeof(list[emptyPosition].nationality));
							list[emptyPosition].typeOfSound = typeOfSoundAux;
							list[emptyPosition].numberOfPlayers = numberOfPlayersAux;
							list[emptyPosition].maxCapacityOfCoins = maxCapacityOfCoinsAux;
							strncpy(list[emptyPosition].gameName, gameNameAux, sizeof(list[emptyPosition].gameName));
							list[emptyPosition].idSalon = idSalon;
							list[emptyPosition].isEmpty = LOAD;

							printf("\nID	| NACIONALIDAD	| TIPO DE SONIDO	| JUGADORES	| CAP. MAX. DE FICHAS	| NOMBRE DEL JUEGO | SALON ASIGNADO\n");
							if (arcade_printOne(list, emptyPosition) == 0)
							{
								state = 0;
							}
						}
					}
				}
			}
		}
	}
	return state;
}

/**
 * \brief Create a new ID number
 */
static int getNewId(void) // Privada del archivo
{
	static int counter = 1; // Es global. Mantiene su valor
	return (counter++);
}


/**
 * \brief Print one Arcade
 * \param Arcade* pArcade
 * \return int Return (-1) if Error - (0) if OK
 */
int arcade_printOne(Arcade* list, int position)
{
	int state = -1;
	char typeOfSoundAux[8];

	if (list != NULL)
	{
		switch (list[position].typeOfSound)
		{
			case MONO:
				strncpy(typeOfSoundAux, "MONO", sizeof(typeOfSoundAux));
				break;
			case ESTEREO:
				strncpy(typeOfSoundAux, "ESTEREO", sizeof(typeOfSoundAux));
				break;
		}
		printf("%d	| %s		| %s		| %d		| %d			| %s		| %d\n", list[position].id, list[position].nationality,
				typeOfSoundAux, list[position].numberOfPlayers, list[position].maxCapacityOfCoins, list[position].gameName, list[position].idSalon);
		state = 0;
	}
	return state;
}


/**
 * \brief Print the content of Arcades array
 * \param list Arcade* Pointer to array of arcades
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int arcade_printList(Arcade* list, int len)
{
	int state = -1;
	int i;
	char typeOfSoundAux[8];

	if (list != NULL && len > 0)
	{
		printf("\nID	| NACIONALIDAD	| TIPO DE SONIDO	| JUGADORES	| CAP. MAX. DE FICHAS	| NOMBRE DEL JUEGO | SALON ASIGNADO\n");
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == LOAD)
			{
				switch (list[i].typeOfSound)
				{
					case MONO:
						strncpy(typeOfSoundAux, "MONO", sizeof(typeOfSoundAux));
						break;
					case ESTEREO:
						strncpy(typeOfSoundAux, "ESTEREO", sizeof(typeOfSoundAux));
						break;
				}
				printf("%d	| %s		| %s		| %d		| %d			| %s		| %d\n", list[i].id, list[i].nationality,
						typeOfSoundAux, list[i].numberOfPlayers, list[i].maxCapacityOfCoins, list[i].gameName, list[i].idSalon);
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Edit an arcade in an existing list of arcades
 * \param list Arcade*
 * \param len int
 * \param pArcade Pointer to a Arcade struct
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int arcade_edit(Arcade* list, int len, Arcade* pArcade)
{
	int state = -1;
	int option;
	int numberOfPlayersAux;
	char gameNameAux[63];
	int flagContinue;

	flagContinue = 1;

	if (pArcade != NULL)
	{
		puts("\nMODIFICACION DE ARCADE");

		do {
			printf("SELECCIONE EL CAMPO A EDITAR:\n");
			printf(" 1. Cantidad de jugadores\n 2. Nombre del videojuego\n");

			if (utn_getInt(&option, "\nINGRESE LA OPCION: ", "ERROR: Comando no valido.\n", 1, 2, 0) == 0)
			{
				switch (option)
				{
					case 1:
						if (utn_getInt(&numberOfPlayersAux, "MODIFICAR LA CANTIDAD DE JUGADORES (Entre 1 y 8 jugadores): ",
										"\nERROR: Debe ingresar un numero que indique la cantidad de jugadores que soporta el arcade (Min: 1. Max: 8).\n",
													1, 8, 0) == 0)
						{
							pArcade->numberOfPlayers = numberOfPlayersAux;
							state = 0;
						}
						break;

					case 2:
						printf("\n== LISTA DE JUEGOS EN SISTEMA ==\n");
						if (arcade_printGameNameList(list, len) != 0)
						{
							printf("\n== No es posible imprimir la lista de juegos ==\n");
						}

						if (utn_getText(gameNameAux, 63, "\nMODIFICAR EL NOMBRE DEL VIDEOJUEGO QUE CONTIENE: ",
								"\nERROR: Debe ingresar el nombre del videojuego del arcade, con maximo de 63 caracteres.\n", 0) == 0)
						{
							strncpy(pArcade->gameName, gameNameAux, sizeof(pArcade->gameName));
							state = 0;
						}
						break;
					default:
						printf("\nElija una opcion entre 1 y 2. Vuelva intentar.\n");
				}
			}

			utn_getInt(&flagContinue, "¿Desea continuar editando?\n 1. Si\n 2. No\nSeleccione una opcion: ", "ERROR: Comando no valido\n", 1, 2, 0);

		} while (flagContinue == 1);

	}
	return state;
}


/**
 * \brief Print the list of gameName of Arcade array without repeating titles
 * \param list Arcade* Pointer to array of arcades
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int arcade_printGameNameList(Arcade* list, int len)
{
	int state = -1;
	int i;
	int j;
	int flagRepeated;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == LOAD)
			{
				flagRepeated = -1;

				for (j = i + 1; j < len; j++)
				{
					if (strcmp(list[i].gameName, list[j].gameName) == 0)
					{
						flagRepeated = 0;
					}
				}

				if (flagRepeated == -1)
				{
					printf("%s\n", list[i].gameName);
				}
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Find a Arcade by Id and returns the index position in array
 * \param list Arcade*
 * \param len int
 * \param id int
 * \return Return arcade index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int arcade_findById(Arcade* list, int len, int id)
{
	int position = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == LOAD)
			{
				position = i;
				break;
			}
		}
	}
	return position;
}


/**
 * \brief Remove a Arcade by Id (put isEmpty Flag in 1)
 * \param list Arcade*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if OK
 */
int arcade_remove(Arcade* list, int len, int id)
{
	int state = -1;
	int position;
	int flagContinue;

	flagContinue = 2;

	if (list != NULL && len > 0)
	{
		position = arcade_findById(list, len, id);

		puts("\nBAJA");
		utn_getInt(&flagContinue, "¿Esta seguro que quiere dar de baja a este arcade?\n 1. Si\n 2. No\nSeleccione una opcion: ",
						"ERROR: Comando no valido", 1, 2, 0);

		if (flagContinue == 1)
		{
			list[position].isEmpty = 1;
			state = 0;
		}
	}
	return state;
}


