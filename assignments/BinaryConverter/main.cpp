using namespace std;
#include <iostream>

class Binary{
public:
    void DecimalToBinaryExtra() {
        cout << "BITWISE: Enter a number" << endl;
        int number;
        cin >> number;

        bool zero = false;
        cout << "0b";
        for (int i = 7; i >= 0; --i) {
            int x = number >> i;
            if (x & 1) {
                cout << "1";
                zero = true;
            }else if(zero)
                cout << "0";
        }
    }

    void DecimalToBinary(){
        cout << "Enter a number" << endl;
        int number;
        cin >> number;

        int binary[8]{0, 0, 0, 0, 0, 0, 0, 0};
        int i = 0;

        while(number > 0){
            int rem = number % 2;
            number /= 2;

            if(rem == 1){
                binary[i] = 1;
            }
            else binary[i] = 0;
            i += 1;
        }
        cout << "0b";

        for(int x = 0; x < 8; x++){
            cout << binary[x];
        }
    }
};

int main() {
    Binary b;
    b.DecimalToBinary();
    cout << endl;
    b.DecimalToBinaryExtra();

    return 0;
}




