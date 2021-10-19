/*
 * informes.h
 * Author: Gabriel Servia
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Salon.h"
#include "Arcade.h"

int info_salonesOverFourArcades(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade);

int info_arcadesOverTwoPlayers(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade);

int info_dataListOfSalon(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon);

int info_arcadesOfOneSalon(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon);

int info_printSalonWithMoreArcades(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade);

int info_salonMaxIncome(Salon* salonList, int lenSalon, Arcade* arcadeList, int lenArcade, int lastIdSalon);

int info_numberOfArcadesWithGame(Arcade* arcadeList, int lenArcade);

#endif /* INFORMES_H_ */
