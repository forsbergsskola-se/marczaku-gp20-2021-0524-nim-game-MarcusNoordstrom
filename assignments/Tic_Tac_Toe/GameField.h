//
// Created by Bulten on 2021-05-27.
//

#ifndef TIC_TAC_TOE_GAMEFIELD_H
#define TIC_TAC_TOE_GAMEFIELD_H

#include <string>

class GameField {
public:
    void PrintField();

private:
    char Field[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool playerOne = false, playerTwo = true;
    void CheckState();
    void CheckAvailability(int);
    void CheckWin();
    void WinFunc(char);
};

#endif //TIC_TAC_TOE_GAMEFIELD_H