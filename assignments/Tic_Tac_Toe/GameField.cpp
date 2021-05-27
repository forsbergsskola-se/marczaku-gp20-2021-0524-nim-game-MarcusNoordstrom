//
// Created by Bulten on 2021-05-27.
//

#include <iostream>
#include "GameField.h"




void GameField::CheckState() {
    std::cout << std::endl;
    std:: cout << "Choose between 1 - 9 , where you wanna place you're X/O" << std::endl;

    playerOne = !playerOne;
    playerTwo = !playerTwo;

    int chosen;
    std::cin >> chosen;

    if(playerOne){
        CheckAvailability(chosen - 1);
        Field[chosen - 1] = 'X';
        PrintField();
    }
    else if(playerTwo){
        CheckAvailability(chosen - 1);
        Field[chosen - 1] = 'O';
        PrintField();
    }
}

void GameField::PrintField() {
    for (int i = 0; i < 9; ++i) {
        std::cout << "|";

        if(i == 2 || i == 5 || i == 8){
            std::cout << Field[i];
            std::cout << "|" << std::endl;
        }
        else{
            std::cout << Field[i];
        }
    }

    CheckWin();
    CheckState();
}

void GameField::CheckAvailability(int slot) {
    if(Field[slot] == 'X' || Field[slot] == 'O'){
        if(playerOne){
            playerOne = true;
            playerTwo = false;
            PrintField();
        }
        else if(playerTwo){
            playerOne = false;
            playerTwo = true;
            PrintField();
        }
    }
}

void GameField::CheckWin() {
    WinFunc('X');
    WinFunc('O');
}

void GameField::WinFunc(char s) {
    std::string player;

    if(s == 'X') player = "Player one ";
    else player = "Player two ";

    if(Field[0] == s && Field[1] == s && Field[2] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[3] == s && Field[4] == s && Field[5] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[6] == s && Field[7] == s && Field[8] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[0] == s && Field[3] == s && Field[6] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[1] == s && Field[4] == s && Field[7] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[2] == s && Field[5] == s && Field[8] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[0] == s && Field[4] == s && Field[8] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
    else if(Field[2] == s && Field[4] == s && Field[6] == s){
        std::cout << player;
        std::cout << "Won!" << std::endl;
        exit(3);
    }
}
