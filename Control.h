#pragma once
#include <string>
#include <Windows.h>
#include <vector>
#include "VectorOpc.h"
#include <conio.h>
#include <iostream>

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_ENTER = 13;
constexpr auto KEY_ESCAPE = 27;
const int SUP_DER = 216;
const int GROSOR = 23;
class Control
{
public:


/**
 * @brief Construct a new Control object
    
 * 
 */
    Control() = default; Control(std::vector<VectorMenu>);
    /**
     * @brief 
     * 
     */
    void controlMenu();
    /**
     * @brief 
     * 
     * @param i 
     * @param retflag 
     */
    void comprobarUpDown(size_t& i, bool& retflag);
    /**
     * @brief 
     * 
     */
    void mostrar(size_t);
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool comprobarMouse(size_t*);
    /**
     * @brief 
     * 
     * @param vkey 
     * @return true 
     * @return false 
     */
    bool comprobarTecla(int vkey);

private:

    std::vector<VectorMenu> opciones_Menu_;

    HANDLE console_; HWND console_wnd = GetConsoleWindow();POINT cursor_pos;
    std::vector<int> listaPosiciones;
};

void Control::controlMenu()
{
    if (opciones_Menu_.empty())
        return;

    for (size_t i = 0, j; i < opciones_Menu_.size(); i++, j++)
    {
        if (i == 0) {
            listaPosiciones.push_back(SUP_DER); listaPosiciones.push_back(SUP_DER + GROSOR);
            j = 1;
        }
        else {
            listaPosiciones.push_back(listaPosiciones.at(j - 1) + 1); listaPosiciones.push_back(listaPosiciones.at(j) + GROSOR);
            j++;
        }
    }
    mostrar(1);
    size_t i{ 1 };

    bool retflag;
    comprobarUpDown(i, retflag);
    if (retflag) return;
}

bool Control::comprobarMouse(size_t* i) {
    if (GetCursorPos(&cursor_pos))
    {
        if (console_wnd && ScreenToClient(console_wnd, &cursor_pos))
        {
            for (size_t i = 0; i < listaPosiciones.size(); i += 2)
            {
                if (cursor_pos.y >= listaPosiciones.at(i) && cursor_pos.y <= listaPosiciones.at(i + 1)) {
                    Sleep(500);mostrar((i / 2) + 1);
                    if (GetAsyncKeyState(VK_RBUTTON)) {
                        opciones_Menu_.at(((i / 2) + 1) - 1).get_fuction()(); return true;
                    }
                }
            }
            return false;
        }
    }

}

void Control::mostrar(size_t option)
{

    system("cls");
    unsigned int i = 0;
    SetConsoleCursorPosition(console_, { 0,0 });
    std::cout << "Damas Chinas" << std::endl;
    while (i < opciones_Menu_.size())
    {

        if (option == (i + 1))
        {
            SetConsoleCursorPosition(console_, { 22,short(i + 9) });
            std::cout << "-->" << opciones_Menu_[i].get_title_() << std::endl;
            SetConsoleTextAttribute(console_, 15);
        }
        else
        {
            SetConsoleCursorPosition(console_, { 22,short(i + 9) });
            std::cout << opciones_Menu_[i].get_title_() << std::endl;
        }
        i++;
    }
}

bool Control::comprobarTecla(int vkey) {
    return GetKeyState(vkey) < 0;
}

Control::Control(std::vector<VectorMenu> options) : opciones_Menu_(options)
{
    console_ = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Control::comprobarUpDown(size_t& i, bool& retflag)
{
    retflag = true;
    while (true)
    {
        if (GetAsyncKeyState(VK_END)) { break; }if (comprobarMouse(&i)) return;
        if (_kbhit())
        {
            if (comprobarTecla(VK_DOWN)) {
                i = (i < opciones_Menu_.size()) ? i += 1 : i = opciones_Menu_.size();
                mostrar(i);
            }
            else if (comprobarTecla(VK_UP))
            {
                i = (i > 1) ? i -= 1 : i = 1; mostrar(i);
            }
            else if (comprobarTecla(VK_RETURN)) {
                system("cls"); opciones_Menu_.at(i - 1).get_fuction()();
                break;
            }
            else if (comprobarTecla(VK_END))
                exit(0);
        }
    }
    retflag = false;
}




