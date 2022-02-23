#pragma once
#include <Windows.h>
#include <thread>

#include "Control.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "DamasChinas.h"
#include "Login.h"
#include "json.hpp"
#include <fstream>

void exit_program();
void cargarJuego();
void principalMenu();
void jugar();
void marquesina(std::string text, size_t limit);
void ajustarVentana();
void logearse();
void registrarse();
