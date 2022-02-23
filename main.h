#pragma once
#include <Windows.h>
#include <thread>
#include "Control.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "DamasChinas.h"
#include "UserCredenciales.h"
#include "json.hpp"
#include <fstream>

/**
 * @brief 
 * 
 */
void exit_program();
/**
 * @brief 
 * 
 */
void cargarJuego();
/**
 * @brief 
 * 
 */
void principalMenu();
/**
 * @brief 
 * 
 */
void jugar();
/**
 * @brief 
 * 
 * @param text 
 * @param limit 
 */
void marquesina(std::string text, size_t limit);
/**
 * @brief 
 * 
 */
void ajustarVentana();
/**
 * @brief 
 * 
 */
void logearse();
/**
 * @brief 
 * 
 */
void registrarse();
