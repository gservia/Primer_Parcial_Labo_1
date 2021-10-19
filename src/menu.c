/*
 * menu.c
 * Author: Gabriel Servia
 */
#include "menu.h"

/**
 * \brief Options Menu. Request a option to user
 * \return Return selected option
 */
int menu()
{
	int option;
	int optionAux;

	printf("\n========== MENU ==========\n");
	printf("1. ALTA DE SALON\n");
	printf("2. ELIMINAR SALON\n");
	printf("3. IMPRIMIR SALONES\n");
	printf("4. INCORPORAR ARCADE\n");
	printf("5. MODIFICAR ARCADE\n");
	printf("6. ELIMINAR ARCADE\n");
	printf("7. IMPRIMIR ARCADE\n");
	printf("8. IMPRIMIR JUEGOS\n");
	printf("9. INFORMES\n");
	printf("10. SALIR DEL SISTEMA\n");

	if (utn_getInt(&optionAux, "\nINGRESAR UNA OPCION: ", "ERROR: Comando no valido.\n", 1, 10, 0) == 0)
	{
		option = optionAux;
	}
	return option;
}


/**
 * \brief Options SubMenu. Request a option to user
 * \return Return selected option
 */
char subMenu()
{
	char option;
	char optionAux;

	printf(" A. Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.\n");
	printf(" B. Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del\n"
		   "    juego y nombre del salón al que pertenece.\n");
	printf(" C. Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección\n"
		   "    y cantidad de arcades que posee.\n");
	printf(" D. Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar\n"
		   "    todos los arcades con sus datos junto con el nombre del juego que lo compone.\n");
	printf(" E. Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de\n"
		   "    arcades que posee.\n");
	printf(" F. Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede recaudar\n"
		   "    el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos ingresado)\n");
	printf(" G. Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.\n");
	printf(" S. SALIR DEL SUBMENU\n");

	if (utn_getText(&optionAux, 2, "\nINGRESAR UNA OPCION: ", "ERROR: Comando no valido.\n", 0) == 0)
	{
		option = optionAux;
	}
	return option;
}
