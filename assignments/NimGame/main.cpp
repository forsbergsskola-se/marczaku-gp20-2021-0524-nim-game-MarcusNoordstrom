#include <iostream>
#include "Matches.h"
#include <stdlib.h>
using namespace std;

bool gameOver = false;
bool multiplayer = false;

void GameOver(bool playerWon){
    gameOver = true;
    if(!multiplayer){
        if(playerWon){
            cout << "GZ YOU WON!";
        }
        else{
            cout << "You loose....";
        }
    }
    else{
        if(playerWon){
            cout << "Player 1 won!";
        }
        else{
            cout << "Player 2 won!";
        }
    }

}

int main() {
    Matches matches;
    bool playerOneTurn = true;

    cout << "--NimGame-- \nChoose you're mode\n1. 2Players | 2. AgainstAI" << endl;

    int mode;
    cin >> mode;

    if(mode == 1){
        multiplayer = true;
    }
    else{
        multiplayer = false;
    }

    cout << "--NimGame-- \nRemove 1-3 from the matches by typing a number between 1-3 and press ENTER\nIF you want to quit, type 9 and press ENTER\n" << endl;


    while(!gameOver){
        int action;



        while(playerOneTurn){
            cout << "Player 1 turn: ";
            cout << matches.GetVisual() << endl;

            cin >> action;

            if(action == 9){
                gameOver = true;
                playerOneTurn = !playerOneTurn;
                break;
            }

            if(action > 0 && action < 4){
                matches.Remove(action);

                if(matches.GetCount() <= 0){
                    GameOver(false);
                    break;
                }

                playerOneTurn = !playerOneTurn;
                break;
            }

            if(action < 0 || action > 3 && action != 9){
                cout << "Invalid input. Try again." << endl;
                break;
            }
        }

        while (multiplayer && !playerOneTurn){
            cout << "Player 2 turn: ";
            cout << matches.GetVisual() << endl;

            cin >> action;

            if(action == 9){
                gameOver = true;
                playerOneTurn = !playerOneTurn;
                break;
            }

            if(action > 0 && action < 4){
                matches.Remove(action);

                if(matches.GetCount() <= 0){
                    GameOver(false);
                    break;
                }

                playerOneTurn = !playerOneTurn;
                break;
            }

            if(action < 0 || action > 3 && action != 9){
                cout << "Invalid input. Try again." << endl;
                break;
            }
        }

        while(!playerOneTurn && !gameOver && !multiplayer){
            int random = rand() % 3 + 1;
            matches.Remove(random);
            cout << "AI turn: ";
            cout << "removed: " + to_string(random) + " Matches" << endl;

            if(matches.GetCount() <= 0){
                GameOver(true);
                break;
            }

            playerOneTurn = true;
            break;
        }
    }
    return 0;
}
