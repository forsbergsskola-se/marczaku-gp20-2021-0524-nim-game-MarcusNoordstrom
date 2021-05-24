#include <iostream>
#include "Matches.h"
#include <stdlib.h>
using namespace std;

bool gameOver = false;

void GameOver(bool playerWon){
    gameOver = true;
    if(playerWon){
        cout << "GZ YOU WON!";
    }
    else{
        cout << "You loose....";
    }
}

int main() {
    Matches matches;
    bool playerTurn = true;

    cout << "--NimGame-- \nRemove 1-3 from the matches by typing a number between 1-3 and press ENTER\nIF you want to quit, type 9 and press ENTER\n" << endl;



    while(!gameOver){
        int action;



        while(playerTurn){
            //Print matches
            cout << matches.GetVisual() << endl;

            cin >> action;

            if(action == 9){
                gameOver = true;
                playerTurn = !playerTurn;
                break;
            }

            if(action > 0 && action < 4){
                matches.Remove(action);

                if(matches.GetCount() <= 0){
                    GameOver(false);
                    break;
                }

                playerTurn = !playerTurn;
                break;
            }

            if(action < 0 || action > 3 && action != 9){
                cout << "Invalid input. Try again." << endl;
                break;
            }


        }

        while(!playerTurn && !gameOver){
            int random = rand() % 3 + 1;
            matches.Remove(random);
            cout << "Enemy removed: " + to_string(random) + " Matches" << endl;

            if(matches.GetCount() <= 0){
                GameOver(true);
                break;
            }

            playerTurn = true;
            break;
        }
    }
    return 0;
}
