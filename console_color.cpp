#include <iostream>     
#include <windows.h>    
#include "game.h"      

using namespace std;  

// Функция установки цвета консоли
void setConsoleColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
    SetConsoleTextAttribute(hConsole, colorCode);      // Устанавливаем цвет текста
}

// Функция для печати цветного текста 
void printColored(char symbol, int color) {
    setConsoleColor(color);  // Устанавливаем нужный цвет
    cout << symbol;          // Печатаем символ
    setConsoleColor(COLOR_WHITE); // Возвращаем белый цвет
}

// Функция для печати цветного текста (строки)
void printColoredString(const string& text, int color) {
    setConsoleColor(color);  // Устанавливаем нужный цвет
    cout << text;            // Печатаем строку
    setConsoleColor(COLOR_WHITE); // Возвращаем белый цвет
}  
