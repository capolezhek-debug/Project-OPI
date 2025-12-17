#include <iostream>
#include <cstdlib>      
#include <ctime>        
#include <windows.h>
#include "game.h"

using namespace std;

// Объявляем внешние глобальные переменные 
extern int board[9];
extern bool gameActive;
extern int playerSymbol;
extern int botSymbol;

// ПРОВЕРКА ПОБЕДИТЕЛЯ 
bool checkWinner(int player) {
    // Проверка 3 горизонтальных линий
    if (board[0] == player && board[1] == player && board[2] == player) return true;
    if (board[3] == player && board[4] == player && board[5] == player) return true;
    if (board[6] == player && board[7] == player && board[8] == player) return true;

    // Проверка 3 вертикальных линий
    if (board[0] == player && board[3] == player && board[6] == player) return true;
    if (board[1] == player && board[4] == player && board[7] == player) return true;
    if (board[2] == player && board[5] == player && board[8] == player) return true;

    // Проверка 2 диагоналей
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;

    return false; // Если ни одна линия не заполнена
}

//  ПРОВЕРКА НИЧЬЕЙ 
bool isBoardFull() {
    for (int i = 0; i < 9; i++) {   // Проходим по всем клеткам
        if (board[i] == 0) {        // Нашли пустую клетку
            return false;           // Поле не заполнено
        }
    }
    return true; // Все клетки заняты
}

// ХОД ИГРОКА 
void playerMove() {
    int position;               // Позиция, выбранная игроком
    bool validMove = false;     // Флаг корректного хода

    // Цикл продолжается, пока игрок не сделает правильный ход
    while (!validMove) {
        cout << "Введите позицию (0-8): ";
        cin >> position;       

        // Проверка 0-8
        if (position < 0 || position > 8) {
            setConsoleColor(COLOR_YELLOW);  
            cout << "Ошибка! Введите число от 0 - 8\n";
            setConsoleColor(COLOR_WHITE);
        }
        // Проверка 2
        else if (board[position] != 0) {
            setConsoleColor(COLOR_YELLOW);
            cout << "Эта клетка занята\n";
            setConsoleColor(COLOR_WHITE);
        }
        else {
            board[position] = playerSymbol; // Ставим символ игрока
            validMove = true;             
        }
    }
}

//  ХОД КОМПЬЮТЕРА 
void botMove() {
    int index;  // Для хранения выбранной позиции

    // 1-ПОПЫТАТЬСЯ ВЫИГРАТЬ
    // Проходим по всем клеткам
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {            // Если клетка свободна
            board[i] = botSymbol;       // Пробуем поставить свой символ
            if (checkWinner(botSymbol)) { // Проверяем, выиграли ли
                return;                 // Если да - ход завершен
            }
            board[i] = 0;               // Если нет - отменяем пробный ход
        }
    }

    // 2-БЛОКИРОВАТЬ ИГРОКА
    // Проходим по всем клеткам
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) {               // Если клетка свободна
            board[i] = playerSymbol;       // Пробуем поставить символ игрока
            if (checkWinner(playerSymbol)) { // Проверяем, выиграет ли игрок
                board[i] = botSymbol;      // Если да - блокируем эту клетку
                return;                    // Ход завершен
            }
            board[i] = 0;                  // Если нет - отменяем пробный ход
        }
    }

    // ПРИОРИТЕТ 3: ЗАНЯТЬ ЦЕНТР (если свободен)
    if (board[4] == 0) {          // Центральная клетка имеет индекс 4
        board[4] = botSymbol;     // Ставим свой символ
        return;                   
    }

    // 4-СЛУЧАЙНЫЙ ХОД
    // Генерируем случайные позиции, пока не найдем свободную
    do {
        index = rand() % 9;       // Генерация числа от 0 до 8
    } while (board[index] != 0);  // Повторяем, пока клетка занята

    board[index] = botSymbol;     // Ставим символ в найденную клетку
}

//  ГЛАВНЫЙ ИГРОВОЙ ЦИКЛ 
void play() {
    displayBoard();  // Показываем начальное поле

    // Главный цикл игры
    while (gameActive) {
        //ХОД ИГРОКА
        // Показываем, чей ход 
        cout << ">>> Ваш ход (";
        if (playerSymbol == 1) {
            setConsoleColor(COLOR_RED);  // Если игрок X - красный
            cout << "X";
        }
        else {
            setConsoleColor(COLOR_BLUE); // Если игрок O - синий
            cout << "O";
        }
        setConsoleColor(COLOR_WHITE);
        cout << "):\n";

        playerMove();      // Обрабатываем ход игрока
        displayBoard();    // Показываем обновленное поле

        // Проверка 1
        if (checkWinner(playerSymbol)) {
            setConsoleColor(COLOR_GREEN);  
            cout << "============================\n";
            cout << "    ВЫ ВЫИГРАЛИ!    \n";
            cout << "============================\n";
            setConsoleColor(COLOR_WHITE);
            gameActive = false;  
            return;              
        }

        // Проверка 2
        if (isBoardFull()) {
            setConsoleColor(COLOR_YELLOW);
            cout << "============================\n";
            cout << "        НИЧЬЯ!        \n";
            cout << "============================\n";
            setConsoleColor(COLOR_WHITE);
            gameActive = false;  
            return;            
        }

        // ХОД КОМПЬЮТЕРА 
        cout << ">>> Ход компьютера...\n";
        botMove();        // Компьютер делает ход
        displayBoard();   // Показываем обновленное поле

        // Проверка 3
        if (checkWinner(botSymbol)) {
            setConsoleColor(COLOR_RED);  
            cout << "============================\n";
            cout << "   КОМПЬЮТЕР ВЫИГРАЛ!   \n";
            cout << "============================\n";
            setConsoleColor(COLOR_WHITE);
            gameActive = false;  
            return;             
        }

        // Проверка 4
        if (isBoardFull()) {
            setConsoleColor(COLOR_YELLOW);
            cout << "============================\n";
            cout << "        НИЧЬЯ!        \n";
            cout << "============================\n";
            setConsoleColor(COLOR_WHITE);
            gameActive = false;  
            return;              
        }

        
    }
}
