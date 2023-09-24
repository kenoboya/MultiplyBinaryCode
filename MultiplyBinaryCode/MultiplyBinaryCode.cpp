#include <iostream>
#include <bitset>
#include <windows.h>
using namespace std;

int main() {

    int A;
    int B;
    cout << "Enter first number: "; cin >> A;
    cout << "Enter second number: "; cin >> B;
    bool pm = false;
    int b1 = 0, b2 = 0;
    if (A < 0)
        b1 = 1;
    if (B < 0)
        b2 = 1;

    cout << "\nDecimal number system = binary number system" << endl;
    cout << "A = " << A << " = " << b1 << "." << bitset<4>(A) << "" << endl;
    cout << "B = " << B << " = " << b2 << "." << bitset<4>(B) << "" << endl;

    if (A < 0)
    {
        A *= -1;
        pm = !pm;
    }
    if (B < 0)
    {
        B *= -1;
        pm = !pm;
    }


    int CM = 0;
    int RV = 0;
    int Q = B;
    int N = 4;



    for (int i = 0; i < N; i++) {
        cout << "\nStep " << i + 1 << ":" << endl;
        cout << "CM = " << bitset<4>(CM) << " RB = " << bitset<4>(RV) << endl;

        if (Q & 1) {
            CM += A;
        }

        Q >>= 1;
        RV >>= 1;

        RV += (CM & 0x0F);

        CM >>= 1;

        cout << "\nAfter shift:" << endl;
        cout << "CM = " << bitset<4>(CM) << " RB = " << bitset<4>(RV) << endl;
    }

    cout << "\nFinal result:" << endl;
    cout << "CM = " << bitset<4>(CM) << " RB = " << bitset<4>(RV) << endl;
    if (pm)
        cout << "\nC = 1." << bitset<4>(CM) << bitset<4>(RV) << endl;
    else
        cout << "\nC = 0." << bitset<4>(CM) << bitset<4>(RV) << endl;
    return 0;
}