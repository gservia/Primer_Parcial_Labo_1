/*
 ============================================================================
 Project     : Primer_Parcial_Labo_1
 Author      : Gabriel Servia
 Division    : 1° H
 University  : UTN FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "menu.h"
#include "Salon.h"
#include "Arcade.h"
#include "informes.h"
#include "testingABM.h"

#define SALONES_LEN 100
#define ARCADES_LEN 1000
#define JUEGOS_LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	Salon salonList[SALONES_LEN];
	Arcade arcadeList[ARCADES_LEN];

	int flagContinue;
	int menuOptionSelected;
	int emptyPlace;
	int lastIdSalon;
	int flagSalonAdded;
	int idSalonToFind;
	int positionOfSalon;
	int lastIdArcade;
	int flagArcadeAdded;
	int idArcadeToFind;
	int position;

	flagContinue = 0;
	flagSalonAdded = 0;
	flagArcadeAdded = 0;

	salon_initList(salonList, SALONES_LEN);
	arcade_initList(arcadeList, ARCADES_LEN);

	puts("=== SALONES DE ARCADES ===");
	do {
		menuOptionSelected = menu();
		switch (menuOptionSelected)
		{
			case 1:
				testing_salonAdd(salonList, SALONES_LEN, 0, 1, "Sacoa", "Guemes 200", 1, &lastIdSalon, &flagSalonAdded);
				testing_salonAdd(salonList, SALONES_LEN, 1, 2, "Play Center", "Mitre 304", 2, &lastIdSalon, &flagSalonAdded);
				testing_salonAdd(salonList, SALONES_LEN, 2, 3, "King Games", "Rivadavia 1200", 2, &lastIdSalon, &flagSalonAdded);
				testing_salonAdd(salonList, SALONES_LEN, 3, 4, "Funny Land", "Alcorta 453", 1, &lastIdSalon, &flagSalonAdded);

				/*
				if (salon_findEmptyPlace(&emptyPlace, salonList, SALONES_LEN) == 0)
				{
					if (salon_add(salonList, SALONES_LEN, emptyPlace) == 0)
					{
						printf("\n=== Alta de salon satisfatoria ===\n");
						lastIdSalon = salonList[emptyPlace].id;
						flagSalonAdded++;
					}
					else
					{
						printf("\n=== Error en alta de salon ===\n");
					}
				}
				else
				{
					printf("La lista de salones esta completa. No es posible sumar salon.\n");
				}
				*/
				break;

			case 2:
				if (flagSalonAdded > 0)
				{
					salon_printList(salonList, SALONES_LEN);
					if (utn_getInt(&idSalonToFind, "\nINGRESE EL ID QUE DESEA DAR DE BAJA: ", "ERROR: El ID ingresado no existe.\n", 1, lastIdSalon, 0) == 0)
					{
						printf("\nID DE ARCADES QUE COMPONEN AL SALON SELECCIONADO:\n");
						for (int i = 0; i < ARCADES_LEN; i++)
						{
							if (arcadeList[i].idSalon == idSalonToFind)
							{
								printf("%d\n", arcadeList[i].id);
							}
						}
						if (salon_remove(salonList, SALONES_LEN, idSalonToFind) == 0)
						{
							for (int i = 0; i < ARCADES_LEN; i++)
							{
								if (arcadeList[i].idSalon == idSalonToFind)
								{
									arcadeList[i].isEmpty = EMPTY;
									flagArcadeAdded--;
								}
							}
							printf("\n=== Baja de salon satisfatoria ===\n");
							flagSalonAdded--;
						}
						else
						{
							printf("\n=== Baja de salon cancelada ===\n");
						}
					}
				}
				else
				{
					printf("\n=== No hay salones dados de alta ===\n");
				}
				break;

			case 3:
				if (flagSalonAdded > 0)
				{
					printf("\nLISTA DE SALONES\n");
					salon_printList(salonList, SALONES_LEN);
				}
				else
				{
					printf("\n=== No hay salones dados de alta ===\n");
				}
				break;

			case 4:
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 0, 1, "Japon", 1, 2, 50, "Mario Bros", 3, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 1, 2, "USA", 2, 4, 80, "Metal Slug", 2, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 2, 3, "Japon", 1, 8, 100, "Daytona USA", 3, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 3, 4, "USA", 2, 4, 80, "Metal Slug", 3, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 4, 5, "USA", 2, 2, 90, "Mortal Kombat", 3, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 5, 6, "Japon", 2, 4, 90, "Virtua Tennis	", 3, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 6, 7, "Japon", 2, 2, 95, "Time Crisis", 2, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 7, 8, "USA", 2, 1, 95, "Rally Champions", 2, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 8, 9, "USA", 2, 2, 95, "FIFA World Cup 98", 1, &lastIdArcade, &flagArcadeAdded);
				testing_arcadeAdd(arcadeList, ARCADES_LEN, 9, 10, "USA", 2, 4, 80, "NBA Jams", 2, &lastIdArcade, &flagArcadeAdded);

				/*
				if (flagSalonAdded > 0)
				{
					salon_printList(salonList, SALONES_LEN);
					if (utn_getInt(&idSalonToFind, "\nINGRESE EL ID DEL SALON DONDE SE INCORPORA EL ARCADE: ", "ERROR: El ID ingresado no existe.\n", 1, lastIdSalon, 0) == 0)
					{
						positionOfSalon = salon_findById(salonList, SALONES_LEN, idSalonToFind);
						if (positionOfSalon != -1)
						{
							if (arcade_findEmptyPlace(&emptyPlace, arcadeList, ARCADES_LEN) == 0)
							{
								if (arcade_add(arcadeList, ARCADES_LEN, emptyPlace, idSalonToFind) == 0)
								{
									printf("\n=== Alta de arcade satisfatoria ===\n");
									lastIdArcade = arcadeList[emptyPlace].id;
									flagArcadeAdded++;
								}
								else
								{
									printf("\n=== Error en alta de arcade ===\n");
								}
							}
						}
					}
				}
				else
				{
					printf("\n=== No hay salones disponibles ===\n");
				}
				*/
				break;

			case 5:
				if (flagSalonAdded > 0 && flagArcadeAdded > 0)
				{
					if (arcade_printList(arcadeList, ARCADES_LEN) == 0)
					{
						if (utn_getInt(&idArcadeToFind, "\nINGRESE EL ID QUE DESEA MODIFICAR: ", "ERROR: El ID ingresado no existe.\n",
								1, lastIdArcade, 0) == 0)
						{
							position = arcade_findById(arcadeList, ARCADES_LEN, idArcadeToFind);
							if (position != -1)
							{
								if (arcade_edit(arcadeList, ARCADES_LEN, &arcadeList[position]) == 0)
								{
									printf("\n=== Modificacion de arcade satisfatoria ===\n");
								}
								else
								{
									printf("\n=== Error en modificacion de arcade ===\n");
								}
							}
						}
						else
						{
							printf("\n=== ERROR: El ID ingresado no existe ===\n");
						}
					}
				}
				else
				{
					printf("\n=== No hay salones o arcades disponibles ===\n");
				}
				break;

			case 6:
				if (flagArcadeAdded > 0)
				{
					if (arcade_printList(arcadeList, ARCADES_LEN) == 0)
					{
						if (utn_getInt(&idArcadeToFind, "\nINGRESE EL ID QUE DESEA DAR DE BAJA: ", "ERROR: El ID ingresado no existe.\n", 1,
								lastIdArcade, 0) == 0)
						{
							if (arcade_remove(arcadeList, ARCADES_LEN, idArcadeToFind) == 0)
							{
								printf("\n=== Baja de arcade satisfatoria ===\n");
								flagArcadeAdded--;
							}
							else
							{
								printf("\n=== Baja de arcade cancelada ===\n");
							}
						}
					}
				}
				else
				{
					printf("\n=== No hay arcades disponibles ===\n");
				}
				break;

			case 7:
				if (flagArcadeAdded > 0)
				{
					printf("\nLISTA DE ARCADES\n");
					arcade_printList(arcadeList, ARCADES_LEN);
				}
				else
				{
					printf("\n=== No hay arcades dados de alta ===\n");
				}
				break;

			case 8:
				if (flagArcadeAdded > 0)
				{
					printf("\nLISTA DE JUEGOS\n");
					arcade_printGameNameList(arcadeList, ARCADES_LEN);
				}
				else
				{
					printf("\n=== No hay juegos en el sistema ===\n");
				}
				break;

			case 9:
				if (flagSalonAdded > 0 && flagArcadeAdded > 0)
				{
					printf("\nINFORMES\n");

					switch (subMenu())
					{
						case 'A':
							if (info_salonesOverFourArcades(salonList, SALONES_LEN, arcadeList, ARCADES_LEN) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'B':
							if (info_arcadesOverTwoPlayers(salonList, SALONES_LEN, arcadeList, ARCADES_LEN) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'C':
							if (info_dataListOfSalon(salonList, SALONES_LEN, arcadeList, ARCADES_LEN, lastIdSalon) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'D':
							if (info_arcadesOfOneSalon(salonList, SALONES_LEN, arcadeList, ARCADES_LEN, lastIdSalon) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'E':
							if (info_printSalonWithMoreArcades(salonList, SALONES_LEN, arcadeList, ARCADES_LEN) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'F':
							if (info_salonMaxIncome(salonList, SALONES_LEN, arcadeList, ARCADES_LEN, lastIdSalon) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'G':
							if (info_numberOfArcadesWithGame(arcadeList, ARCADES_LEN) != 0)
							{
								printf("\n=== No se hallaron resultados para este informe ===\n");
							}
							break;
						case 'S':
							printf("\n=== Retorno a menu principal ===\n");
							break;
						default:
							printf("Elija una opcion entre A y G, o bien S para salir. Solo se aceptan comandos en mayusculas. Vuelva intentar.\n");
							break;
					}
				}
				else
				{
					printf("\n=== No hay salones o arcades disponibles ===\n");
				}
				break;

			case 10:
				puts("\n=== PROGRAMA FINALIZADO ===");
				flagContinue = 1;
				break;

			default:
				printf("Elija una opcion entre 1 y 10. Vuelva intentar.\n");
				break;
		}
	} while (flagContinue == 0);

	return EXIT_SUCCESS;
}
