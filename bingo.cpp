/**
 * @authors Emanuel Borges and José Gomes
 * @brief Header file for a Bingo game
 * @date 18-02-2025
 * @file bingo.cpp
 */

#include "bingo.h"

/**
 * @brief The game of Bingo
 */
void Bingo::playBingo(int ballsQuantity) {

    /**
     * @param bool Boolean variable to declare if a number has been picked in an array with the full ammount of balls chosen for the game
     */
    bool picked[ballsQuantity + 1] = {false};

    /**
     * @param int Variable for the ammount of balls remaining unpicked
     * @param int As default, this variable is set to the remaining balls as the full quantity
     */
    int remaining = ballsQuantity;

    /**
     * @param int Variable to store the previously used number
     * @param int As default, sets the previous number as zero, as zero cannot be on the table
     */
    int lastNumber = 0;

    /**
     * @param srand Seed random number generator
     */
    srand(time(0));

    /**
     * @param while Game loop 
     */
    while (remaining > 0) {
        /**
         * @param int Variable to store the result of the current round
         */
        int result;
        
        /**
         * @brief Function to pick a new unique number every round
         */
        do {
            result = (rand() % ballsQuantity) + 1;
        } while (picked[result]);

        /**
         * @param bool Marks the number as picked
         */
        picked[result] = true;

        /**
         * @param int Decreses the remaining ammount of balls
         */
        remaining--;

        cout << "\nGenerating the next number...\n";

        /**
         * @param int Size of columns used for the table
         */
        int column = 10;

        /**
         * @brief Print the table
         */
        for (int i = 1; i <= ballsQuantity; i++) {
            if (i == result) {
                cout << BLUE << i << RESET << "\t";  // Highlight current number
            } else if (i == lastNumber) {
                cout << GREEN << i << RESET << "\t";  // Highlight previous number
            } else {
                cout << i << "\t";
            }

            /**
             * @brief If i is a multiple of column, so we insert an endl
             */
            if (i % column == 0) {
                cout << endl;
            }
        }
        cout << endl;

        /**
         * @brief Simmulated blinking effect
         */
        for (int blink = 0; blink < 3; blink++) {
            cout << "\rPrevious Number: " << GREEN << lastNumber << RESET
                 << " | Current Number: " << BLUE << result << RESET << flush;
            sleep(1);
            cout << "\rPrevious Number: " << GREEN << lastNumber << RESET
                 << " | Current Number: " << WHITE << result << flush;
            sleep(1);
        }
        
        /**
         * @param int Update last picked number
         */
        lastNumber = result;
    }
    cout << "\nAll numbers have been picked! Game over.\n";
}

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
