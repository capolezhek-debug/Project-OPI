#ifndef GAME_H        
#define GAME_H          

#include <windows.h>    

// ФУНКЦИИ ИНТЕРФЕЙСА 
void setupConsole();    // Настройка консоли (кодировка, локаль)
void displayBoard();    // Отрисовка игрового поля
void chooseSymbol();    // Выбор символа игроком
void setConsoleColor(int colorCode); // Установка цвета текста в консоли

// ИГРОВАЯ ЛОГИКА 
void play();            // Главный игровой цикл
bool checkWinner(int player); // Проверка победителя
bool isBoardFull();     // Проверка, заполнено ли поле
void playerMove();      // Обработка хода игрока
void botMove();         // Ход компьютера 

// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ 
extern int board[9];    // Игровое поле 
extern bool gameActive; // Флаг активности игры
extern int playerSymbol; // Символ игрока 
extern int botSymbol;   // Символ компьютера 

//  КОНСТАНТЫ ЦВЕТОВ 
#define COLOR_WHITE 7   // Белый цвет 
#define COLOR_RED 12    // Красный 
#define COLOR_BLUE 9    // Синий
#define COLOR_GREEN 10  // Зеленый 
#define COLOR_YELLOW 14 // Желтый 

#endif 
