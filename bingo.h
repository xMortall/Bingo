/**
 * @authors Emanuel Borges and José Gomes
 * @brief Header file for a Bingo game
 * @date 18-02-2025
 * @file bingo.h
 */

#ifndef BINGO_H
#define BINGO_H
#include "configs.h"

class Bingo {
    private:
        static int option;          // Stores the menu option chosen by the user
        static int cardsQuantity;   // Stores how many bingo cards will be generated
        static int ballsQuantity;   // Stores the number of balls in the game (default: 75)
        static const int cardsRows = 5;  // Number of rows in the bingo card
        static const int cardsCols = 5;  // Number of columns in the bingo card
        static const int numbersPerColumn = 15;  // Numbers per column

    public:
        struct Menu {
            void displayMenu();  // Function to display the menu options
            void handleMenu();   // Function to handle user input for the menu
        };

        static int numberOfBalls();  // Function to change the number of balls (75, 90, 100)

        static void playBingo();                // Function to start the bingo game
        static int generateCardsFiles();        // Function to ask the user how many cards to generate

        static vector<vector<int>> generateCard();  // Function to generate a single bingo card
        static void saveCardsToFiles(int quantity); // Function to save multiple cards in text files
        static int randomNumber(int min, int max);  // Function to generate a random number
};

#endif