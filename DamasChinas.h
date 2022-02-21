#pragma once

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include "t_jugador.h"

#define MAXFILAS 17
#define MAXCOL 25
using namespace std;

class DamasChinas
{
public:

	static void generar_mapa(char** Mmapa);

	static void dibujar_mapa(char** Mmapa);

	static void mover_ficha(int coordx, int coordy, int destx, int desty, int direccion, char** Mmapa);

	static int menu();

	static bool victoria(char** Mmapa);

	static void pedir_datos(t_jugador* Vjugadores);

	static void bienvenida();

	static void generar_cartel(int** Mcartel);

	static void dibujar_cartel(int** Mcartel);

	static void instrucciones();

	static void creditos();

	static void jugar();



};

