#include "main.h"

void principalMenu()
{
	std::vector<VectorMenu> opciones{{1, "Jugar", Jugar},{2, "SALIR", exit_program}};
	Control objetoMenu{ opciones };
	objetoMenu.controlMenu();

}

void loginRegisterApp()
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
    loginRegisterApp();
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
    loginRegisterApp();
}
void exit_program()
{
	exit(0);
}

void Jugar() {
	system("cls");
	system("pause");
	DamasChinas::jugar();
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
	//std::string str = " UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ";
	//std::thread hilo(marquesina, str, str.size());
	AjustarVentana();
    loginRegisterApp();
	
}

void AjustarVentana()
{
	CONSOLE_FONT_INFOEX consola;
	consola.cbSize = sizeof consola;consola.dwFontSize.Y = 24;
	consola.FontFamily = FF_DONTCARE; consola.nFont = 0; consola.FontWeight = FW_NORMAL;
	wcscpy(consola.FaceName, L"Consolas"); SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &consola);
	HWND console_wnd = GetConsoleWindow(); RECT ConsoleRect;
	GetWindowRect(console_wnd, &ConsoleRect); MoveWindow(console_wnd, ConsoleRect.left, ConsoleRect.top, 900, 600, TRUE);
}

