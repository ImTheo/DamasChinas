#include "DamasChinas.h"
#include "json.hpp"
#include <direct.h>
using namespace nlohmann;
using std::cout;

//estructura para establecer el nombre y el dado



//funciona que genera el tablero
void DamasChinas::generar_mapa(char** Mmapa) {
	char matriz[MAXFILAS][MAXCOL] = {
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ','A',' ','A',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ','A',' ','A',' ','A',' ','A',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{'B',' ','B',' ','B',' ','B',' ','O',' ','O',' ','O',' ','O',' ','O',' ','F',' ','F',' ','F',' ','F'},
									{' ','B',' ','B',' ','B',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','F',' ','F',' ','F',' '},
									{' ',' ','B',' ','B',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','F',' ','F',' ',' '},
									{' ',' ',' ','B',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','F',' ',' ',' '},
									{' ',' ',' ',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ',' ',' ',' '},
									{' ',' ',' ','C',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','E',' ',' ',' '},
									{' ',' ','C',' ','C',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','E',' ','E',' ',' '},
									{' ','C',' ','C',' ','C',' ','O',' ','O',' ','O',' ','O',' ','O',' ','O',' ','E',' ','E',' ','E',' '},
									{'C',' ','C',' ','C',' ','C',' ','O',' ','O',' ','O',' ','O',' ','O',' ','E',' ','E',' ','E',' ','E'},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ','D',' ','D',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ','D',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
									{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
	};

	int fila, columna;
	for (fila = 0; fila < MAXFILAS; fila++) { //inicializa el mapa
		for (columna = 0; columna < MAXCOL; columna++) {
			Mmapa[fila][columna] = matriz[fila][columna];
		}
	}
}

void DamasChinas::dibujar_mapa(char** Mmapa) {
	//PARA LOS COLORES
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbi;

	int fila, columna;
	cout << "\n\n" << endl;
	cout << "\t0123456789012345678901234" << "\n";


	for (fila = 0; fila < MAXFILAS; fila++) { //controla las filas

		if (fila >= 0 && fila < MAXCOL) cout << fila << "\t";
		else cout << fila << "\t";

		for (columna = 0; columna < MAXCOL; columna++) { //controla las columnas

			switch (Mmapa[fila][columna]) { //switch para controlar los colores

			case 'A':
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //color verde
				break;
			case 'B':
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //color azul
				break;
			case 'O':
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //color blanco
				break;
			case 'C':
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY); //color red
				break;
			case 'D':
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //color amarillo
				break;
			case 'E':
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); //color celeste
				break;
			case 'F':
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); //color fucsia
				break;

			}

			cout << Mmapa[fila][columna];
		}

		cout << endl;
	}

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //restablecer color
	cout << "\t0123456789012345678901234" << "\n";
	cout << endl;
}

void DamasChinas::mover_ficha(int coordx, int coordy, int destx, int desty, int direccion, char** Mmapa) {
	char aux;
	switch (direccion) {
	case 1:
		destx = coordx - 1;
		desty = coordy - 1;
		break;
	case 2:
		destx = coordx - 1;
		desty = coordy + 1;
		break;
	case 3:
		destx = coordx;
		desty = coordy + 2;
		break;
	case 4:
		destx = coordx;
		desty = coordy - 2;
		break;
	case 5:
		destx = coordx + 1;
		desty = coordy + 1;
		break;
	case 6:
		destx = coordx + 1;
		desty = coordy - 1;
		break;
	}
	aux = Mmapa[destx][desty];
	Mmapa[destx][desty] = Mmapa[coordx][coordy];
	Mmapa[coordx][coordy] = aux;
}

//funcion para generar el menu
int DamasChinas::menu() {

	int opcion;
	cout << "      .:MENU:." << endl;
	cout << "--------------------" << endl;
	cout << "1) Instrucciones" << endl;
	cout << "2) Empezar juego" << endl << endl;
	cout << "3) Creditos" << endl;
	cout << "5) Salir" << endl;

	do { //bucle para controlar el ingreso de opcione
		cout << ">_Ingrese su opcion: ";
		cin >> opcion;
	} while (opcion < 1 || opcion>5);

	cout << endl;
	return opcion;

}

bool DamasChinas::victoria(char** Mmapa) {
	if (Mmapa[0][12] == Mmapa[1][11] == Mmapa[1][13] == Mmapa[2][10] == Mmapa[2][12] ==
		Mmapa[2][14] == Mmapa[3][9] == Mmapa[3][11] == Mmapa[3][13] == Mmapa[3][15] == 'D') {
		return false;
	}

	else if (Mmapa[13][9] == Mmapa[13][11] == Mmapa[13][13] == Mmapa[13][15] == Mmapa[14][10] ==
		Mmapa[14][12] == Mmapa[14][14] == Mmapa[15][11] == Mmapa[15][13] == Mmapa[16][12] == 'A') {
		return false;
	}
	else return true;
}

void DamasChinas::pedir_datos(t_jugador* Vjugadores) {
	int i;
	cout << "DATOS DE LOS JUGADORES" << endl;
	cout << "-----------------------\n\n";
	for (i = 1; i <= 2; i++) {
		cout << "Jugador " << i << "\n";
		cout << "  Digite su nickname: ";
		cin >> Vjugadores[i].nombre;
	}
	cout << endl;
}

void DamasChinas::generar_cartel(int** Mcartel) {
	int cartel[23][15] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,1,0,1,0,1,1,1,0,1,0,1,0,0},
							{0,0,0,1,0,0,1,0,1,0,1,0,1,0,0},
							{0,0,0,1,0,0,1,0,1,0,1,0,1,0,0},
							{0,0,0,1,0,0,1,1,1,0,1,1,1,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,2,0,0,0,2,0,2,0,2,0,0,0,2,0},
							{0,2,0,0,0,2,0,2,0,2,0,0,0,2,0},
							{0,2,0,0,0,2,0,0,0,2,0,0,0,2,0},
							{0,2,0,0,0,2,0,2,0,2,2,0,0,2,0},
							{0,2,0,0,0,2,0,2,0,2,2,0,0,2,0},
							{0,2,0,2,0,2,0,2,0,2,2,0,0,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,2,0,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,2,0,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,2,0,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,0,2,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,0,2,2,0},
							{0,2,0,2,0,2,0,2,0,2,0,0,2,2,0},
							{0,2,2,2,2,2,0,2,0,2,0,0,0,2,0},
							{0,2,2,2,2,2,0,2,0,2,0,0,0,2,0},
							{0,2,2,2,2,2,0,2,0,2,0,0,0,2,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };


	int fila, columna;
	for (fila = 0; fila < 23; fila++) { //inicializa el cartel
		for (columna = 0; columna < 15; columna++) {
			Mcartel[fila][columna] = cartel[fila][columna];
		}
	}
}

void DamasChinas::dibujar_cartel(int** Mcartel) {
	//PARA LOS COLORES
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int fila, columna;

	for (fila = 0; fila < 23; fila++) { //controla las filas

		for (columna = 0; columna < 15; columna++) { //controla las columnas

			switch (Mcartel[fila][columna]) { //switch para controlar los colores

			case 0:
				cout << "      ";
				break;
			case 1:
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //color verde
				cout << "XXXXXX";
				break;
			case 2:
				SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); //color celeste
				cout << "XXXXXX";
				break;
			}

		}

		cout << endl;
	}

	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); //restablecer color
	cout << endl;
}

void DamasChinas::instrucciones() {
	cout << ".:INSTRUCCIONES:." << endl;
	cout << "------------------" << endl;
	cout << "\nLa finalidad del juego es trasladar todas las fichas desde una punta de la estrella\n";
	cout << "hasta la punta opuesta, antes que los demas jugadores.\n";

	cout << "\nLos jugadores deben colocar sus fichas en triangulos (o puntas de estrella) opuestas\n";
	cout << "y mover susfichas hasta el triangulo donde ha empezado su competidor.\n";

	cout << "\nMOVIMIENTOS BASICOS:\n\tCada jugador puede mover solo una ficha por turno.\n";
	cout << "\tLas fichas pueden moverse a una casilla que se encuentre libre adelante o a un lado de donde se\n";
	cout << "\tencuentran, pero no pueden retroceder. Tambien pueden ?saltar? sobre otra ficha para caer en una\n";
	cout << "\tcasilla vacia junto a esta. Si el movimiento es de este segundo tipo (un salto), y conduce la ficha a\n";
	cout << "\tuna casilla contigua a otra ocupada, puede volver a ?saltar? esta segunda ficha en el mismo turno,\n";
	cout << "\ty asi sucesivamente. De esta manera, en un solo turno, una ficha puede avanzar de una punta del\n";
	cout << "\ttablero a otra si la situaci?n es propicia.\n";
	cout << "\tEl jugador que tenga la habilidad de colocar sus canicas en forma parecida a una escalera podr? ir\n";
	cout << "\tsaltando de una a otra, incluso usando las fichas de sus contrincantes, y ocupar la punta de\n";
	cout << "\testrella opuesta mas rapidamente.\n";

	cout << "\nEl juego termina cuando uno de los jugadores logra colocar sus 6 fichas en el triangulo opuesto al suyo.\n";
}

void DamasChinas::creditos() {
	cout << ".:CREDITOS:." << endl;
	cout << "------------" << endl << endl;
	cout << "Elaborado por:" << endl;
	cout << "- " << endl;
	cout << "- " << endl;
	cout << "- " << endl << endl;
}

void DamasChinas::jugar() {
	system("cls");
	system("pause");
	DamasChinas juego;
	t_jugador* Vjugadores = new t_jugador[2];
	srand(time(NULL));

	//generar mapa
	juego.Mmapa = new char* [MAXFILAS];
	for (juego.i = 0; juego.i < MAXFILAS; juego.i++) {
		juego.Mmapa[juego.i] = new char[MAXCOL];
	}

	//generar cartel
	juego.Mcartel = new int* [23];
	for (juego.i = 0; juego.i < 23; juego.i++) {
		juego.Mcartel[juego.i] = new int[15];
	}

	do {
		juego.opcion = menu();
		switch (juego.opcion) {
		case 1: {
			do {

				system("cls");
				instrucciones();
				cout << endl << ">_Presione 0 para volver al menu: ";
				cin >> juego.volver;
			} while (juego.volver != 0);
			system("cls");
			break;
		}

		case 3: {
			do {
				system("cls");
				creditos();
				cout << endl << ">_Presione 0 para volver al menu: ";
				cin >> juego.volver;
			} while (juego.volver != 0);
			system("cls");
			break;
		}

		case 4: {
			cout << "Agrega el backup kpo" << endl;
			system("pause");

		}

		case 5: {
			return;
		}

		}
	} while (juego.opcion != 2);

	system("cls");


	pedir_datos(Vjugadores);


	do {
		generar_mapa(juego.Mmapa);
		dibujar_mapa(juego.Mmapa);

		cout << ">_Escoja una region (A / B / C / D / E / F): ";
		cin >> juego.j1ficha; juego.j1ficha = toupper(juego.j1ficha);

	} while ((juego.j1ficha != 'A') && (juego.j1ficha != 'B') && (juego.j1ficha != 'C') && (juego.j1ficha != 'D') && (juego.j1ficha != 'E') && (juego.j1ficha != 'F'));

	//setea la region del P1 Y P2
	switch (juego.j1ficha) {
	case 'A':
		juego.j2ficha = 'D';
		break;
	case 'B':
		juego.j2ficha = 'E';
		break;
	case 'C':
		juego.j2ficha = 'F';
		break;
	case 'D':
		juego.j2ficha = 'A';
		break;
	case 'E':
		juego.j2ficha = 'B';
		break;
	case 'F':
		juego.j2ficha = 'C';
		break;
	}

	cout << "\t> " << Vjugadores[1].nombre << " -> " << juego.j1ficha << endl;
	cout << "\t> " << Vjugadores[2].nombre << " -> " << juego.j2ficha << endl << endl;
	cout << ">>>> RESULTADO DE LOS DADOS: \n";

	do {
		//obtiene el valor
		for (juego.i = 1; juego.i <= 2; juego.i++) {
			Vjugadores[juego.i].dado = rand() % 6 + 1;
		}

	} while (Vjugadores[1].dado == Vjugadores[2].dado);


	for (juego.i = 1; juego.i <= 2; juego.i++) {
		cout << "\t> " << Vjugadores[juego.i].nombre << ": " << Vjugadores[juego.i].dado << endl;
	}

	cout << endl;
	
	juego.jugador1 = Vjugadores[1].nombre;
	juego.jugador2= Vjugadores[2].nombre;

	if (Vjugadores[2].dado > Vjugadores[1].dado) {
		juego.primerJugador = false;
		juego.auxficha = juego.j1ficha;
		juego.j1ficha = juego.j2ficha;
		juego.j2ficha = juego.auxficha;
	}
	else {
		juego.primerJugador = true;
	}
	int guardar;

	while (victoria(juego.Mmapa)) {

		for (juego.turno = 1; juego.turno > 0; juego.turno++) {

			if (juego.primerJugador) {
				cout << "> Turno de  " << juego.jugador1 << endl;
				juego.primerJugador = false;
			}
			else {
				cout << "> Turno de " << juego.jugador2 << endl;
				juego.primerJugador = true;
			}

			if ((juego.turno % 2) == 1) {
				do {
					cout << ">_Ingrese la fila de la ficha a mover: "; cin >> juego.coordx;
					cout << ">_Ingrese la columna de la ficha a mover: "; cin >> juego.coordy;

				} while ((juego.Mmapa[juego.coordx][juego.coordy]) != juego.j1ficha);
				do {
					cout << "\n>>> Mover Ficha" << endl;
					cout << "\t\t\t\t" << "   [1]  [2]" << endl;
					cout << "\t\t\t\t" << "[4]        [3]" << endl;
					cout << "\t\t\t\t" << "   [6]  [5]" << endl << endl;
					cout << "(1: up-left, 2: up-right, 3: right, 4: left, 5: down-right, 6: down-left): ";
					cin >> juego.direccion;
				} while ((juego.direccion < 1) || (juego.direccion > 6));
				mover_ficha(juego.coordx, juego.coordy, juego.destx, juego.desty, juego.direccion, juego.Mmapa);


			}
			if ((juego.turno % 2) == 0) {
				do {
					cout << ">_Ingrese la fila de la ficha a mover: "; cin >> juego.coordx;
					cout << ">_Ingrese la columna de la ficha a mover: "; cin >> juego.coordy;

				} while ((juego.Mmapa[juego.coordx][juego.coordy]) != juego.j2ficha);
				do {
					cout << "\n>>> Mover Ficha" << endl;
					cout << "\t\t\t\t" << "   [1]  [2]" << endl;
					cout << "\t\t\t\t" << "[4]        [3]" << endl;
					cout << "\t\t\t\t" << "   [6]  [5]" << endl << endl;
					cout << "(1: up-left, 2: up-right, 3: right, 4: left, 5: down-right, 6: down-left): ";
					cin >> juego.direccion;
				} while ((juego.direccion < 1) || (juego.direccion > 6));
				mover_ficha(juego.coordx, juego.coordy, juego.destx, juego.desty, juego.direccion, juego.Mmapa);


			}
			cout << "Guardar partida 1/si 0/no" << endl;
			cin >> guardar;
			if (guardar == 1) {
				cout << "Guardando partida..." << endl;
				guardarPartida(juego.Mmapa, juego.turno, juego.coordx, juego.coordy, juego.j1ficha, juego.direccion, juego.destx, juego.desty, juego.j2ficha, juego.primerJugador,juego.jugador1,juego.jugador2);

			}
			system("pause");
			dibujar_mapa(juego.Mmapa);
		}
	}

	for (juego.i = 0; juego.i < MAXFILAS; juego.i++) {
		delete[]juego.Mmapa[juego.i];
	}
	delete[]juego.Mmapa;

	system("pause");

}

void DamasChinas::cargarPartida(char** Mmapa, int& turno, int& coordx, int& coordy, char j1ficha, int& direccion, int destx, int desty, char j2ficha,bool primerJugador,string jugador1,string jugador2)
{
	int guardar;
	turno++;
	while (victoria(Mmapa)) {

		for (turno; turno > 0; turno++) {

			if (primerJugador) {
				cout << "> Turno de  " << jugador1 << endl;
				primerJugador = false;
			}
			else {
				cout << "> Turno de " << jugador2 << endl;
				primerJugador = true;
			}
			if ((turno % 2) == 1) {
				do {
					cout << ">_Ingrese la fila de la ficha a mover: "; cin >> coordx;
					cout << ">_Ingrese la columna de la ficha a mover: "; cin >> coordy;

				} while ((Mmapa[coordx][coordy]) != j1ficha);
				do {
					cout << "\n>>> Mover Ficha" << endl;
					cout << "\t\t\t\t" << "   [1]  [2]" << endl;
					cout << "\t\t\t\t" << "[4]        [3]" << endl;
					cout << "\t\t\t\t" << "   [6]  [5]" << endl << endl;
					cout << "(1: up-left, 2: up-right, 3: right, 4: left, 5: down-right, 6: down-left): ";
					cin >> direccion;
				} while ((direccion < 1) || (direccion > 6));
				mover_ficha(coordx, coordy, destx, desty, direccion, Mmapa);


			}
			if ((turno % 2) == 0) {
				do {
					cout << ">_Ingrese la fila de la ficha a mover: "; cin >> coordx;
					cout << ">_Ingrese la columna de la ficha a mover: "; cin >> coordy;

				} while ((Mmapa[coordx][coordy]) != j2ficha);
				do {
					cout << "\n>>> Mover Ficha" << endl;
					cout << "\t\t\t\t" << "   [1]  [2]" << endl;
					cout << "\t\t\t\t" << "[4]        [3]" << endl;
					cout << "\t\t\t\t" << "   [6]  [5]" << endl << endl;
					cout << "(1: up-left, 2: up-right, 3: right, 4: left, 5: down-right, 6: down-left): ";
					cin >> direccion;
				} while ((direccion < 1) || (direccion > 6));
				mover_ficha(coordx, coordy, destx, desty, direccion, Mmapa);


			}
			cout << "Guardar partida 1/si 0/no" << endl;
			cin >> guardar;
			if (guardar == 1) {
				cout << "Guardando partida..." << endl;
				guardarPartida(Mmapa, turno, coordx, coordy, j1ficha, direccion, destx, desty, j2ficha, primerJugador, jugador1, jugador2);

			}
			system("pause");
			dibujar_mapa(Mmapa);
		}
	}
}

void DamasChinas::guardarPartida(char** Mmapa, int& turno, int& coordx, int& coordy, char j1ficha, int& direccion, int destx, int desty, char j2ficha, bool primerJugador, string jugador1, string jugador2){
		
		string filename = "C:\\DamasChinas\\partidas\\";
		string filename2 = "C:\\DamasChinas\\";
		
		auto end = std::chrono::system_clock::now();
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);
		string s = string(std::ctime(&end_time));
		std::replace(s.begin(), s.end(), ':', '-');
		s.pop_back();
		filename += s;
		filename2 += s;
		_mkdir("C:\\DamasChinas\\");
		_mkdir("C:\\DamasChinas\\partidas");
		json damas;

		int ki = 10;
		int kj = 10;

		for (size_t i = 0; i < MAXFILAS; i++,ki++)
		{
			for (size_t j = 0; j < MAXCOL; j++,kj++)
			{
				damas[std::to_string(ki)][std::to_string(kj)] = Mmapa[i][j];
			}
			kj = 10;
		}

		std::ofstream file(filename2+".json");
		file << std::setw(4) << damas << std::endl;
		file.close();

		json datosJugadores = {
			{"turno",turno},
			{"coordx",coordx},
			{"coordy",coordy},
			{"j1ficha",j1ficha},
			{"direccion",direccion},
			{"destx",destx},
			{"desty",desty},
			{"primerJugador",primerJugador},
			{"jugador1",jugador1},
			{"jugador2",jugador2},
			{"j2ficha",j2ficha}
		};

		std::ofstream file2(filename+".json");
		file2 << std::setw(4) << datosJugadores << std::endl;
		file2.close();
}



