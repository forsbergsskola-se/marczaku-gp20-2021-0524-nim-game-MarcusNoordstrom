//
// Created by Bulten on 2021-05-27.
//

#ifndef TIC_TAC_TOE_GAMEFIELD_H
#define TIC_TAC_TOE_GAMEFIELD_H

#include <string>

class GameField {
public:
    std::string Place(int pos);

private:
    std::string CheckState();
};

#endif //TIC_TAC_TOE_GAMEFIELD_H