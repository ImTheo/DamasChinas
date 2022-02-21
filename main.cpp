#include "main.h"

void primerMenu()
{
	std::vector<VectorMenu> opciones{{1, "Jugar", placeholder},{2, "SALIR", exit_program}};
	Control objetoMenu{ opciones };
	objetoMenu.controlMenu();

}

void exit_program()
{
	exit(0);
}

void placeholder() {
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
	primerMenu();
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

