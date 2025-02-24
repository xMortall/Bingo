> [!NOTE]  
> Work is a bingo based on the recommendations of our teacher Paulo Leite.   

> [!WARNING]  
> Don't use to make money!  

# Bingo Game Documentation  

# Introduction  
This project is a Bingo game implemented with several functionalities, including generating bingo cards with random numbers and simulating the game.  

The menu consists of three options:  

1. **Start Game**  
   - The first option starts the Bingo game. The user will be prompted to choose how many balls they want to play with (75, 90, or 100). The functionality for managing different numbers of balls is included.  
   
2. **Generate Cards with Random Numbers**  
   - The second option generates Bingo cards with random numbers. The cards are created with a 5x5 grid, where each column has a set of numbers depending on the number of balls chosen. The center space on the card is free.  

3. **Exit the Program**  
   - The third option terminates the program.  

---  

## Project Overview  
This project is a console-based Bingo game implemented in C++. It allows users to generate Bingo cards, select the number of balls (75, 90, or 100), and play a full Bingo game with random number generation and card management. The game includes colorful text outputs for better visualization.  

## Authors  
- Emanuel Borges  
- José Gomes  

## Files Description  
- **configs.h**: Configuration file containing color constants for text styling.  
- **bingo.h**: Header file defining the `Bingo` class and its methods.  
- **bingo.cpp**: Implementation of the Bingo game logic, including card generation, number drawing, and saving cards to text files.  
- **main.cpp**: Main entry point of the program that initializes the menu and handles user input.  

## Code Breakdown  

### Menu Options  
1. **`Start Game`**:  
   - Once the user selects the start game option, the system will initiate the Bingo game.  
   
2. **`Generate Bingo Cards`**:  
   - The user can generate a specified number of Bingo cards. The cards will be saved as text files, where each file contains one randomly generated Bingo card. The columns will have numbers within specific ranges based on the chosen number of balls (75, 90, or 100).  

3. **`Exit`**:  
   - The program exits when this option is selected.  

---  

### Key Functions  
- **`randomNumber(min, max)`**:  
   Generates a random number between `min` and `max` using a linear congruential generator (LCG) algorithm. This function ensures the generation of pseudo-random numbers for the Bingo cards.  

- **`generateCard()`**:  
   Generates a single Bingo card. The card is created as a 5x5 grid with numbers randomly chosen for each column. The center space is marked as free. The numbers per column are based on the selected number of balls.  

- **`saveCardsToFiles(quantity)`**:  
   Saves the generated Bingo cards to text files. Each card is written to a separate file with a unique name, e.g., `card_1.txt`.  

- **`numberOfBalls()`**:  
   Allows the user to choose the number of balls to play with (75, 90, or 100). The number of balls will affect the number ranges for each column in the Bingo cards.  

---  

## Features  
- Colorful text output for better user experience.  
- Flexible number of balls (75, 90, or 100).  
- Dynamic card generation and saving to text files.  
- Real-time number drawing with blinking effect for the current number.  
- Menu-driven interface for easy navigation.  

## Compilation and Execution  
To compile the game, use the following commands in a terminal:  
```bash
 g++ main.cpp bingo.cpp -o bingoGame
```
To run the game, execute:
```
 ./bingoGame
```

## Dependencies

- C++ Compiler (e.g., g++)
- Standard libraries: **`<iostream>`, `<fstream>`, `<vector>`, `<unistd.h>`**

# Conclusion

This project provides a simple implementation of Bingo with multiple options for the user, including generating cards and starting the game. It was created in a pair work between Emanuel Borges and José Gomes and follows the guidelines provided by our teacher Paulo Leite.
Contact Information

For any questions or contributions, please contact:

- Emanuel Borges
- José Gomes
