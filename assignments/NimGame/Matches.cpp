//
// Created by Bulten on 2021-05-24.
//

#include "Matches.h"

void Matches::Remove(int amount) {
    if(amount > 0 && amount < 4){
        matchCount -= amount;
    }
}

int Matches::GetCount() const {
    return matchCount;
}

std::string Matches::GetVisual() {
    std::string matchVisual = "";
    for (int m = 0; m < matchCount; ++m) {
        matchVisual += '|';
    }
    return matchVisual;
}

