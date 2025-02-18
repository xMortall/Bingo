/**
 * @authors Emanuel Borges and José Gomes
 * @brief Header file for a Bingo game
 * @date 18-02-2025
 * @file bingo.h
 */

#ifndef BINGO_H
#define BINGO_H
#include "configs.h"

class Bingo{
    private:
        static int option; //Store option of menu
        static int cardsQuantity; //Store quantity of cards
        static int ballsQuantity; //Store quantity of balls
    public:
    struct Menu{
        void menuCout();
        void menu();
    };
    static void playBingo();
    static int generateFiles(int card[ballsQuantity], int cardsQuantity);

    
};
#endif