/**
 * @author Emanuel Borges
 * @brief Menu for a Bingo game
 * @date 18-02-2025
 * @file menu.cpp
 */

#include "menu.h"

    /**
    * @brief Just couts for menu
    */
    void menuCout()
    {
        cout << "_____________________________"<< GREEN << R"(
 _ __ ___   ___ _ __  _   _ 
| '_ ` _ \ / _ \ '_ \| | | |
| | | | | |  __/ | | | |_| |
|_| |_| |_|\___|_| |_|\__,_|
)" << RESET << "_____________________________" << endl; //Ascii of menu
        cout << YELLOW << R"( 
Press 1 to start the game
Press 2 to create the cards
Press 3 to exit
)" << RESET;
    }

int main(){
    menuCout();
}