#pragma once

#include <chrono>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include "t_jugador.h"
#include <fstream>
#define MAXFILAS 17
#define MAXCOL 25
using std::cout;
using std::string;
using std::endl;
using std::cin;

class DamasChinas
{
public:
	char** Mmapa, matriz;
	int** Mcartel;
	int opcion, volver;
	char j1ficha, j2ficha, auxficha, aux;
	int i, j, dado1, dado2, turno, coordx, coordy, destx = 0, desty = 0, direccion;
	bool primerJugador;
	string jugador1, jugador2;

/**
 * @brief 
 * 
 * @param Mmapa 
 */
	static void generar_mapa(char** Mmapa);
/**
 * @brief 
 * 
 * @param Mmapa 
 */
	static void dibujar_mapa(char** Mmapa);
/**
 * @brief 
 * 
 * @param coordx 
 * @param coordy 
 * @param destx 
 * @param desty 
 * @param direccion 
 * @param Mmapa 
 */
	static void mover_ficha(int coordx, int coordy, int destx, int desty, int direccion, char** Mmapa);
/**
 * @brief 
 * 
 * @return int 
 */
	static int menu();
/**
 * @brief 
 * 
 * @param Mmapa 
 * @return true 
 * @return false 
 */
	static bool victoria(char** Mmapa);
/**
 * @brief 

 * 
 * @param Vjugadores 
 */
	static void pedir_datos(t_jugador* Vjugadores);
/**
 * @brief 
 * 
 */
	static void bienvenida();
/**
 * @brief 
 * 
 * @param Mcartel 
 */
	static void generar_cartel(int** Mcartel);
/**
 * @brief 
 * 
 * @param Mcartel 
 */
	static void dibujar_cartel(int** Mcartel);
/**
 * @brief 
 * 
 */
	static void instrucciones();
/**
 * @brief 
 * 
 */
	static void creditos();
/**
 * @brief 
 * 
 */
	static void jugar();
/**
 * @brief 
 * 
 * @param Mmapa 
 * @param turno 
 * @param coordx 
 * @param coordy 
 * @param j1ficha 
 * @param direccion 
 * @param destx 
 * @param desty 
 * @param j2ficha 
 * @param primerJugador 
 * @param jugador1 
 * @param jugador2 
 */
	static void cargarPartida(char** Mmapa, int& turno, int& coordx, int& coordy, char j1ficha, int& direccion, int destx, int desty, char j2ficha, bool primerJugador, string jugador1, string jugador2);
/**
 * @brief 
 * 
 * @param Mmapa 
 * @param turno 
 * @param coordx 
 * @param coordy 
 * @param j1ficha 
 * @param direccion 
 * @param destx 
 * @param desty 
 * @param j2ficha 
 * @param primerJugador 
 * @param jugador1 
 * @param jugador2 
 */
	static void guardarPartida(char** Mmapa, int& turno, int& coordx, int& coordy, char j1ficha, int& direccion, int destx, int desty, char j2ficha, bool primerJugador, string jugador1, string jugador2);



};

