/**
 * @authors Emanuel Borges and José Gomes
 * @brief Header file for a Bingo game
 * @date 18-02-2025
 * @file bingo.cpp
 */

 #include "bingo.h"

 // Initial values for the static variables
 int Bingo::cardsQuantity = 0;
 int Bingo::ballsQuantity = 75;  // Default number of balls is set to 75
 
 /**
  * @brief Prompts the user to select the number of balls (75, 90, 100).
  * Allows flexibility in choosing the number of balls for the bingo game.
  */
 int Bingo::numberOfBalls() {
     cout << YELLOW << "How many balls do you want? (75, 90, 100)" << RESET << endl;
     cin >> ballsQuantity;  // User input for number of balls
     return 0;
 }
 
 /**
  * @brief Starts the Bingo game.
  * In this case, just a placeholder for the game start.
  */
 void Bingo::playBingo() {
     cout << "Starting Bingo...\n";
 }
 
 /**
  * @brief Generates a random number within a specified range using Linear Congruential Generator (LCG).
  * The algorithm ensures a pseudo-random number generation.
  */
 int Bingo::randomNumber(int min, int max) {
     static int seed = 12345;
     seed = (seed * 1103515245 + 12345) & 0x7FFFFFFF;
     return min + (seed % (max - min + 1));  // Generates a number within the given range
 }
 
 /**
  * @brief Generates a single bingo card based on the selected number of balls.
  * The card is a 5x5 matrix where each column has a range of numbers.
  * The center space is free.
  * @return A 5x5 bingo card (vector of vectors of integers)
  */
 vector<vector<int>> Bingo::generateCard() {
     vector<vector<int>> card(cardsRows, vector<int>(cardsCols, 0));  // Initialize the bingo card
 
     for (int column = 0; column < cardsCols; ++column) {
         vector<bool> used(numbersPerColumn + 1, false);  // Track numbers already used in this column
 
         // Adjust the number range for the selected number of balls
         int min = column * ballsQuantity / 5 + 1;
         int max = (column + 1) * ballsQuantity / 5;
 
         for (int row = 0; row < cardsRows; ++row) {
             if (row == 2 && column == 2) continue;  // Skip the center space (free space)
 
             int num;
             do {
                 num = randomNumber(min, max);  // Generate a random number within the column's range
             } while (used[num - min]);  // Ensure the number has not already been used in this column
 
             used[num - min] = true;  // Mark the number as used
             card[row][column] = num;  // Place the number in the card
         }
     }
     return card;  // Return the generated card
 }
 
 /**
  * @brief Saves multiple bingo cards to separate text files.
  * Each card is written to a file with a name like "card_1.txt", "card_2.txt", etc.
  * @param quantity Number of cards to generate and save
  */
 void Bingo::saveCardsToFiles(int quantity) {
     for (int i = 1; i <= quantity; ++i) {
         string fileName = "card_" + to_string(i) + ".txt";  // Generate a unique file name
         ofstream file(fileName);
 
         if (!file) {
             cout << "Error creating file " << fileName << "!\n";  // Error handling for file creation
             continue;
         }
 
         vector<vector<int>> card = generateCard();  // Generate a bingo card
         file << "Card " << i << ":\n";
         file << " B   I   N   G   O\n";  // Print the header with column names
         for (int row = 0; row < cardsRows; ++row) {
             for (int column = 0; column < cardsCols; ++column) {
                 if (row == 2 && column == 2)
                     file << " -  ";  // Free space in the center of the card
                 else
                     file << (card[row][column] < 10 ? " " : "") << card[row][column] << "  ";  // Format the numbers
             }
             file << "\n";  // End of row
         }
         file.close();
         cout << GREEN << "Card " << i << " saved in '" << fileName << "'!\n" << RESET;
     }
 }
 
 /**
  * @brief Prompts the user for how many bingo cards to generate.
  * Calls the function to save the cards to files.
  * @return The number of cards generated
  */
 int Bingo::generateCardsFiles() {
     cout << "How many cards do you want to generate? ";
     cin >> cardsQuantity;  // User input for number of cards
     saveCardsToFiles(cardsQuantity);  // Call the function to save the cards
     return cardsQuantity;
 }
 
 /**
  * @brief Displays the menu options for the user.
  * Shows available choices like starting the game, generating cards, etc.
  */
 void Bingo::Menu::displayMenu() {
     cout << "_____________________________" << GREEN << R"(
  _ __ ___   ___ _ __  _   _ 
 | '_ ` _ \ / _ \ '_ \| | | |
 | | | | | |  __/ | | | |_| |
 |_| |_| |_|\___|_| |_|\__,_| 
 )" << RESET
          << "_____________________________" << endl;
     cout << YELLOW << R"( 
 Press 1 to start the game
 Press 2 to create the cards
 Press 3 to set the number of balls
 Press 4 to exit
 )" << RESET;  // Display menu options
 }
 
 /**
  * @brief Handles user input for the menu, calling appropriate functions.
  * Responds to user's choice and calls functions accordingly.
  */
 void Bingo::Menu::handleMenu() {
     displayMenu();  // Display the menu
     cin >> Bingo::option;  // User input for menu option
 
     switch (option) {
     case 1:
         playBingo();  // Start the bingo game
         break;
     case 2:
         generateCardsFiles();  // Generate and save bingo cards
         break;
     case 3:
         numberOfBalls();  // Set the number of balls
         break;
     case 4:
         cout << "Exiting...\n";  // Exit the program
         exit(0);
     default:
         cout << "Invalid option! Please try again.\n";  // Handle invalid input
         return;
     }
 }