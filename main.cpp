#include "main.h"
using namespace nlohmann;
using std::vector;
void cargarJuego() {

    system("cls");
    system("pause");

    _mkdir("C:\\DamasChinas\\");
    _mkdir("C:\\DamasChinas\\partidas\\");

    string dir = "C:\\DamasChinas\\partidas";
    string dir2 = "C:\\DamasChinas\\";

    cout << "\n\n";

    vector <string> files;
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    dir += "\\*";

    hFind = FindFirstFile(dir.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        std::cout << "Ruta incorrecta";
    else
    {
        //std::cout << findFileData.cFileName << '\n'; //El primer fichero
        files.push_back(findFileData.cFileName);
        // Listamos todos los ficheros restantes
        while (FindNextFile(hFind, &findFileData) != 0)
            //std::cout << findFileData.cFileName << '\n';
            files.push_back(findFileData.cFileName);
    }
    std::reverse(files.begin(), files.end());
    files.pop_back();
    files.pop_back();

    int a = 1;

    for (auto f : files) {
        std::cout << a << ")" << f << std::endl;
        a++;
    }

    cout << "Selecciona un numero: ";
    cin >> a;
    
    

    string filename = files[a - 1];
    filename.resize(filename.size() - 5);

    std::ifstream i2("C:\\DamasChinas\\" +filename+".json");
    json j2;
    i2 >> j2;
    DamasChinas partida;
    int ki = 10;
    int kj = 10;

    partida.Mmapa = new char* [MAXFILAS];
    for (partida.i = 0; partida.i < MAXFILAS; partida.i++) {
        partida.Mmapa[partida.i] = new char[MAXCOL];
    }

    for (size_t i = 0; i < MAXFILAS; i++, ki++)
    {
        for (size_t j = 0; j < MAXCOL; j++, kj++)
        {
            partida.Mmapa[i][j] = j2[std::to_string(ki)][std::to_string(kj)].get<int>();
        }
        kj = 10;
    }

    std::ifstream i("C:\\DamasChinas\\partidas\\" + filename + ".json");
    json j;
    i >> j;

    partida.coordx=j["coordx"].get<int>();
    partida.coordy=j["coordy"].get<int>();
    partida.destx=j["destx"].get<int>();
    partida.desty=j["desty"].get<int>();
    partida.direccion=j["direccion"].get<int>();
    partida.j1ficha= j["j1ficha"].get<int>();
    partida.j2ficha= j["j2ficha"].get<int>();
    partida.jugador1= j["jugador1"].get<string>();
    partida.jugador2= j["jugador2"].get<string>();
    partida.primerJugador= j["primerJugador"].get<bool>();
    partida.turno= j["turno"].get<int>();
   i2.close();

   partida.dibujar_mapa(partida.Mmapa);
    partida.cargarPartida(partida.Mmapa,partida.turno,partida.coordx,partida.coordy,partida.j1ficha,partida.direccion,partida.destx,partida.desty,partida.j2ficha,partida.primerJugador,partida.jugador1,partida.jugador2);

    system("pause");
}


void opcionJuego()
{
    std::vector<VectorMenu> menu_item
    {
        {1, "Nueva Partida", DamasChinas::jugar},
        {2, "Recargar Partida", cargarJuego},
        {3, "SALIR", exit_program}
    };

    Control menu{ menu_item };
    menu.controlMenu();
}

void principalMenu()
{
	std::vector<VectorMenu> opciones{{1, "Jugar", jugar},{2, "SALIR", exit_program}};
	Control objetoMenu{ opciones };
	objetoMenu.controlMenu();

}

void pedirDatos()
{
    std::vector<VectorMenu> menu_item
    {
        {1, "Login", logearse},
        {2, "Register", registrarse},
        {3, "SALIR", exit_program}
    };

    Control menu{ menu_item };
    menu.controlMenu();
}

void logearse()
{
    system("pause");
    system("cls");
    Login log;
    if (log.login() == 1) {
        principalMenu();
    }
    else {
        cout << "Usuario Incorrecto" << endl;
        Sleep(600);
    }
    pedirDatos();
}

void registrarse()
{
    system("pause");
    system("cls");
    Login log;
    if (log.sigin() == 1) {
    }
    else {
        cout << "Usuario Incorrecto" << endl;
        Sleep(600);
    }
    pedirDatos();
}

void exit_program()
{
	exit(0);
}

void jugar() {
    system("cls");
    system("pause");
    opcionJuego();
    principalMenu();
}

void marquesina(std::string text, size_t limit) {
	while (true)
	{
		std::string temp = text;
		text.erase(0, 1);text += temp[0];
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		SetConsoleTitleA(text.substr(0, limit).c_str());

	}
}

int main()
{
    ////std::string str = " UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
    ////std::thread hilo(marquesina, str, str.size());
    ajustarVentana();
    //pedirDatos();
    principalMenu();

}

void ajustarVentana()
{
	CONSOLE_FONT_INFOEX consola;
	consola.cbSize = sizeof consola;consola.dwFontSize.Y = 24;
	consola.FontFamily = FF_DONTCARE; consola.nFont = 0; consola.FontWeight = FW_NORMAL;
	wcscpy(consola.FaceName, L"Consolas"); SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &consola);
	HWND console_wnd = GetConsoleWindow(); RECT ConsoleRect;
	GetWindowRect(console_wnd, &ConsoleRect); MoveWindow(console_wnd, ConsoleRect.left, ConsoleRect.top, 900, 600, TRUE);
}

