/*
 * Salon.c
 * Author: Gabriel Servia
 */
#include "Salon.h"

static int getNewId(void);


/**
 * \brief To indicate that all position in the array are empty
 * \param list Salon* Pointer to array
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int salon_initList(Salon* list, int len)
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
 * \param Salon* list
 * \param int len
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if OK
 */
int salon_findEmptyPlace(int* emptyPlace, Salon* list, int len)
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
 * \brief Add in a existing list of Salones the values in the empty position
 * \param Salon* list
 * \param int len
 * \param int emptyPosition Receives an empty position of Salon array
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if OK
 */
int salon_add(Salon* list, int len, int emptyPosition)
{
	int state = -1;
	char nameAux[128];
	char addressAux[128];
	int typeAux;

	if (list != NULL && len > 0)
	{
		puts("\nALTA DE SALON");
		if (utn_getText(nameAux, 128, "\nINGRESAR NOMBRE: ", "\nERROR: Debe ingresar el nombre del salon, con maximo de 128 caracteres.\n", 0) == 0)
		{
			if (utn_getText(addressAux, 128, "INGRESAR DIRECCION: ", "\nERROR: Debe ingresar la direccion del salon, con maximo de 128 caracteres.\n", 0) == 0)
			{
				if (utn_getInt(&typeAux, "SELECCIONE TIPO DE SALON\n 1. Shopping\n 2. Local\nINGRESAR OPCION DESEADA: ",
						"\nERROR: Debe seleccionar entre la opcion 1 o 2.\n", 1, 2, 0) == 0)
				{
				    list[emptyPosition].id = getNewId();
					strncpy(list[emptyPosition].name, nameAux, sizeof(list[emptyPosition].name));
					strncpy(list[emptyPosition].address, addressAux, sizeof(list[emptyPosition].address));
					list[emptyPosition].type = typeAux;
					list[emptyPosition].isEmpty = LOAD;

					printf("\nID	| NOMBRE		| DIRECCION		| TIPO\n");
					if (salon_printOne(list, emptyPosition) == 0)
					{
						state = 0;
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
 * \brief Print one Salon
 * \param Salon* pSalon
 * \return int Return (-1) if Error - (0) if OK
 */
int salon_printOne(Salon* list, int position)
{
	int state = -1;
	char typeAux[9];

	if (list != NULL)
	{
		switch (list[position].type)
		{
			case SHOPPING:
				strncpy(typeAux, "SHOPPING", sizeof(typeAux));
				break;
			case LOCAL:
				strncpy(typeAux, "LOCAL", sizeof(typeAux));
				break;
		}
		printf("%d	| %s		| %s		| %s\n", list[position].id, list[position].name, list[position].address, typeAux);
		state = 0;
	}
	return state;
}


/**
 * \brief Print the content of Salones array
 * \param list Salon* Pointer to array of salones
 * \param len int Array length
 * \return int Return (-1) if Error - (0) if OK
 */
int salon_printList(Salon* list, int len)
{
	int state = -1;
	int i;
	char typeAux[9];

	if (list != NULL && len > 0)
	{
		printf("ID	| NOMBRE		| DIRECCION		| TIPO\n");
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == LOAD)
			{
				switch (list[i].type)
						{
							case SHOPPING:
								strncpy(typeAux, "SHOPPING", sizeof(typeAux));
								break;
							case LOCAL:
								strncpy(typeAux, "LOCAL", sizeof(typeAux));
								break;
						}
						printf("%d	| %s		| %s		| %s\n", list[i].id, list[i].name, list[i].address, typeAux);
			}
		}
		state = 0;
	}
	return state;
}


/**
 * \brief Find a Salon by Id and returns the index position in array
 * \param list Salon*
 * \param len int
 * \param id int
 * \return Return salon index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 */
int salon_findById(Salon* list, int len, int id)
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
 * \brief Remove a Salon by Id (put isEmpty Flag in 1)
 * \param list Salon*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if OK
 */
int salon_remove(Salon* list, int len, int id)
{
	int state = -1;
	int position;
	int flagContinue;

	flagContinue = 2;

	if (list != NULL && len > 0)
	{
		position = salon_findById(list, len, id);

		if (position != -1)
		{
			puts("\nBAJA DE SALON");
			utn_getInt(&flagContinue, "¿Esta seguro que quiere dar de baja a este salon y los arcades que lo componen?\n 1. Si\n 2. No\nSeleccione una opcion: ",
							"ERROR: Comando no valido", 1, 2, 0);

			if (flagContinue == 1)
			{
				list[position].isEmpty = EMPTY;
				state = 0;
			}
		}
		else
		{
			printf("\nEl ID ingresado no existe o fue dado de baja.\n");
		}
	}
	return state;
}
