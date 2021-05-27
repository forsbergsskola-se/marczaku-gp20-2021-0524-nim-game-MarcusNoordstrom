using namespace std;
#include <iostream>

int main() {
    cout << "Enter a number" << endl;
    int number;
    cin >> number;

    int binary[8]{0, 0, 0, 0, 0, 0, 0, 0};
    int i = 0;
    bool negative = number < 0;

    while(number > 0){
        int rem = number % 2;
        number /= 2;

        if(rem == 1){
            binary[i] = 1;
        }
        else binary[i] = 0;
        i += 1;
    }

    if(!negative){
        for(int x = 0; x < 8; x++){
            cout << binary[x];
        }
    }
    /*else{
        for (int x = 0; x < 8; x++) {
            if(binary[x] == 0){
                binary[x] = 1;
            }
            else if(binary[x] == 1){
                binary[x] = 0;
            }
        }

        for(int x = 0; x < 8; x++){
            if(binary[x] == 1){
                binary[x] = 0;
            }
            else if(binary[x] == 0){
                binary[x] = 1;
                break;
            }
        }
    }*/

    return 0;
}

