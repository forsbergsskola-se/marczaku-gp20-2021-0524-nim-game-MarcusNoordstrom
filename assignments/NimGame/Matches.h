//
// Created by Bulten on 2021-05-24.
//

#include <string>

#ifndef NIMGAME_MATCHES_H
#define NIMGAME_MATCHES_H

class Matches {
public:
    void Remove(int amount);
    int GetCount() const;
    std::string GetVisual();

private:
    int matchCount = 24;
};

#endif //NIMGAME_MATCHES_H