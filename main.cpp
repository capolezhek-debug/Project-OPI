#include <iostream>
#include <cstdlib>     
#include <ctime>      
#include <windows.h>    
#include "game.h"     

using namespace std;

//ТОЧКА ВХОДА В ПРОГРАММУ 
int main() {
   
    setupConsole();  


    srand(time(0));  


    setConsoleColor(COLOR_GREEN);
    cout << "============================\n";
    setConsoleColor(COLOR_WHITE);
    cout << "   ";
    setConsoleColor(COLOR_RED);
    cout << "КРЕСТИКИ";
    setConsoleColor(COLOR_WHITE);
    cout << " И ";
    setConsoleColor(COLOR_BLUE);
    cout << "НОЛИКИ";
    setConsoleColor(COLOR_WHITE);
    cout << "   \n";
    setConsoleColor(COLOR_GREEN);
    cout << "============================\n\n";
    setConsoleColor(COLOR_WHITE);


    cout << "Добро пожаловать в игру!\n";
    cout << "Крестики ";
    setConsoleColor(COLOR_RED);
    cout << "красные";
    setConsoleColor(COLOR_WHITE);
    cout << ", Нолики ";
    setConsoleColor(COLOR_BLUE);
    cout << "синие\n";
    setConsoleColor(COLOR_WHITE);
    cout << "Свободные клетки показаны ";
    setConsoleColor(COLOR_GREEN);
    cout << "зеленым\n\n";
    setConsoleColor(COLOR_WHITE);

    //  ВЫБОР СИМВОЛА ИГРОКОМ
    chooseSymbol();  // Игрок выбирает X или O

    // 6. ИНФОРМАЦИЯ О СИМВОЛЕ КОМПЬЮТЕРА
    cout << "\nКомпьютер играет за: ";
    if (botSymbol == 1) {  
        setConsoleColor(COLOR_RED);
        cout << "X (красные)\n";
    }
    else {              
        setConsoleColor(COLOR_BLUE);
        cout << "O (синие)\n";
    }
    setConsoleColor(COLOR_WHITE);

    // ИНИЦИАЛИЗАЦИЯ ИГРОВОГО ПОЛЯ
    for (int i = 0; i < 9; i++) {
        board[i] = 0;  // Заполняем все клетки нулями (пусто)
    }

    //  ЗАПУСК ИГРЫ
    gameActive = true;  
    play();             // Запускаем главный игровой цикл

    //  ПРОЩАЛЬНОЕ СООБЩЕНИЕ
    setConsoleColor(COLOR_GREEN);
    cout << "\nСпасибо за игру!\n";
    setConsoleColor(COLOR_WHITE);


    system("pause");  // Ждет нажатия любой клавиши

    return 0;  
}
