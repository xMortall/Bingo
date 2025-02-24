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
bool Bingo::isCardGenerated = false;
bool Bingo::isAutomatic;
 
/**
* @brief Prompts the user to select the number of balls (75, 90, 100).
* Allows flexibility in choosing the number of balls for the bingo game.
* @return The number of balls
*/
int Bingo::numberOfBalls() {
    cout << YELLOW << "How many balls do you want? (75, 90, 100)" << RESET << endl;
    cin >> ballsQuantity;  // User input for number of balls
    return ballsQuantity;
}

/**
 * @brief Function to declare if the game should be automatic or manual
 */
int Bingo::gameMode()
{
    /**
    * @brief Ask user for game mode
    */
    cout << "Choose game mode:\n1. Automatic\n2. Manual (Press Enter to pick the next number)\n";
    int choice;
    cin >> choice;
    switch(choice){
    case 1:
    isAutomatic = true;
    break;
    default:
    isAutomatic = false;
    break;
}
    return isAutomatic;
}

/**
 * @param bool Boolean variable to declare if a number has been picked in an array with the full ammount of balls chosen for the game
 */
void Bingo::playBingo(int ballsQuantity, bool isAutomatic) {
    if (isCardGenerated == false) {
        cout << RED << "Sorry but there are no cards generated yet\n" << RESET;
sleep(2);
        return;
    }

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
    srand(time(0));

    /**
    * @param while Game loop 
    */ 
    while (remaining > 0) {
        if (!isAutomatic) {
            cout << "\nPress Enter to draw the next number...";
            cin.ignore();  // Clear buffer
        }
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
        remaining--;

        system("clear || cls");
        cout << "\nGenerating the next number...\n";

        int column = 10;

        /**
        * @brief Print the table
        */
        for (int i = 1; i <= ballsQuantity; i++) {
            if (i == result) {
                cout << BLUE << i << RESET << "\t";
            } else if (i == lastNumber) {
                cout << GREEN << i << RESET << "\t";
            } else if (picked[i]) {
                cout << RED << i << RESET << "\t";
            } else {
                cout << i << "\t";
            }

            if (i % column == 0) {
                cout << endl;
            }
        }
        cout << endl;
        if(isAutomatic){
        for (int blink = 0; blink < 2; blink++) {
            cout << "\rPrevious Number: " << GREEN << lastNumber << RESET
                << " | Current Number: " << BLUE << result << RESET << flush;
            sleep(1);
            cout << "\rPrevious Number: " << GREEN << lastNumber << RESET
                << " | Current Number: " << WHITE << result << flush;
            sleep(1);
        }
    }else{
        cout << "\rPrevious Number: " << GREEN << lastNumber << RESET
                << " | Current Number: " << BLUE << result << RESET << endl;
    }

        /**
        * @param int Update last picked number
        */
        lastNumber = result;
    }

    cout << "\nAll numbers have been picked! Game over.\n";
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
vector<vector<int>> Bingo::generateCard(int ballsQuantity) {
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
    return card; // Return the generated card
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

        vector<vector<int>> card = generateCard(ballsQuantity);  // Generate a bingo card
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
int Bingo::generateCardsFiles(int ballsQuantity) {
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
    system("clear || cls");
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
Press 3 to choose the quantity of balls
Press 4 to exit
)" << RESET;  // Display menu options
}
 
/**
* @brief Handles user input for the menu, calling appropriate functions.
* Responds to user's choice and calls functions accordingly.
*/
 void Bingo::Menu::handleMenu() {
    int option;
    displayMenu();  // Display the menu
    cin >> option;  // User input for menu option
 
    switch (option) {
    case 1:
        gameMode();
        playBingo(ballsQuantity, isAutomatic);  // Start the bingo game
        break;
    case 2:
        generateCardsFiles(ballsQuantity);  // Generate and save bingo cards
        isCardGenerated = true;
        break;
    case 3:
        numberOfBalls();
        break;
    case 4:
        cout << "Exiting...\n";  // Exit the program
        exit(0);
        break;
    default:
        cout << "Invalid option! Please try again.\n";  // Handle invalid input
    }
}
