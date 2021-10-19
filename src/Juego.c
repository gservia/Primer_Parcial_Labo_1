/*
 * Juego.c
 * Author: Gabriel Servia
 */
#include "Juego.h"


/**
 * \brief To indicate that all position in the array are empty
 * \param list Juego* Pointer to array
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int juego_initList(Juego* list, int len)
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
 * \brief Load Juegos array
 * \param list Juego* Pointer to array of juegos
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int juego_loadList(Juego* juegoList, int juegoLen, Arcade* arcadeList, int arcadeLen)
{
	int state = -1;
	int i;
	int j = 0;

	if (arcadeList != NULL && arcadeLen > 0 && juegoList != NULL && juegoLen > 0)
	{
		for (i = 0; i < arcadeLen; i++)
		{
			if (arcadeList[i].isEmpty == LOAD)
			{
				if (juegoList[j].isEmpty == EMPTY)
				{
					if (j < juegoLen)
					{
						if (juego_gameRepeated(juegoList, juegoLen, arcadeList[i]) != 0)
						{
							strncpy(juegoList[j].gameName, arcadeList[i].gameName, sizeof(juegoList[j].gameName));
							juegoList[j].isEmpty = LOAD;
							j++;
						}
					}
				}
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Print the content of Juegos array
 * \param list Juego* Pointer to array of juegos
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int juego_printList(Juego* list, int len)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				printf("%s\n", list[i].gameName);
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief To indicate that Juego already exist in array
 * \param list Juego* Pointer to array
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int juego_gameRepeated(Juego* list, int len, Arcade pArcade)
{
	int state = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (strcmp(list[i].gameName, pArcade.gameName) == 0)
			{
				state = 0;
				break;
			}
		}
	}
	return state;
}

