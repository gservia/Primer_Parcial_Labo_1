/*
 * Juego.h
 * Author: Gabriel Servia
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Arcade.h"

// Valores isEmpty:
#define LOAD 0
#define EMPTY 1

typedef struct {
	char gameName[63];
	int isEmpty; // 0: Load | 1: Empty
}Juego;

int juego_initList(Juego* list, int len);

int juego_loadList(Juego* juegoList, int juegoLen, Arcade* arcadeList, int arcadeLen);

int juego_printList(Juego* list, int len);

int juego_gameRepeated(Juego* list, int len, Arcade pArcade);

#endif /* JUEGO_H_ */
