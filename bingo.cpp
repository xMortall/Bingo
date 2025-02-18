/**
 * @authors Emanuel Borges and José Gomes
 * @brief Header file for a Bingo game
 * @date 18-02-2025
 * @file bingo.cpp
 */

#include "bingo.h"

/**
 * @brief StartGame
 */

void Bingo::playBingo() {
};

/**
 * @brief Generate Card
 */
int Bingo::generateFiles(){
    // cout << YELLOW << "How many cards do you want? \n";
    // cin >> cardNumber;
    // cardNumber = BIn
    // cout << "How many balls do you want? \n" << RESET;
    // cin >> Bingo::ballsQuantity;
    // card[Bingo::ballsQuantity];
    
    // ofstream outFile("card" + to_string(cardNumber) + ".txt");
    // if (outFile.is_open()) {
    //     for (int i = 0; i < 25; i++) {
    //         if (i == 12) {
    //             outFile << "- ";
    //         } else {
    //             outFile << (card[i] == 0 ? "0" : to_string(card[i])) << " ";
    //         }
    //         if ((i + 1) % 5 == 0) {
    //             outFile << endl;
    //         }
    //     }
    //     outFile.close();
    //     cout << GREEN << "Cartão " << cardNumber << " salvo com sucesso." << RESET << endl;
    // } else {
    //     cout << RED << "Erro ao abrir o arquivo para escrita." << RESET << endl;
    // }
    // return cardNumber, Bingo::ballsQuantity;
}

/**
 * @brief Just couts for menu
 */
void Bingo::Menu::menuCout()
{
    cout << "_____________________________" << GREEN << R"(
 _ __ ___   ___ _ __  _   _ 
| '_ ` _ \ / _ \ '_ \| | | |
| | | | | |  __/ | | | |_| |
|_| |_| |_|\___|_| |_|\__,_|
)" << RESET
         << "_____________________________" << endl; // Ascii of menu
    cout << YELLOW << R"( 
Press 1 to start the game
Press 2 to create the cards
Press 3 to exit
)" << RESET; // Options for the menu
    }

    void Bingo::Menu::menu(){

        Menu::menuCout();
        Bingo::option;
        cin >> option;


        switch (option){
        case 1:
            Bingo::playBingo();
            break;
        case 2:
            Bingo::generateFiles();
            break;
        case 3:
            /**/
            break;
        case 4:
            /*Close*/
            exit;
            break;

        default: cout << RED << "That's not an option" << RESET << endl;
                return;
            break;
        }
    }
