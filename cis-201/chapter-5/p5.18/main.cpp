#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int postalCode;

    cout << "Enter the zip code you want to print into a bar code: " << endl;
    cin >> postalCode;

    if (postalCode > 100000 || postalCode < 10000) {
        cout << "Invalid postal code, only length 5 postal code allowed.";
        return 0;
    }

    int conversionArray[10][5] = {
        {1, 1, 0, 0, 0},    // 0
        {0, 0, 0, 1, 1},    // 1
        {0, 0, 1, 0, 1},    // 2
        {0, 0, 1, 1, 0},    // 3
        {0, 1, 0, 0, 1},    // 4
        {0, 1, 0, 1, 0},    // 5
        {0, 1, 1, 0, 0},    // 6
        {1, 0, 0, 0, 1},    // 7
        {1, 0, 0, 1, 0},    // 8
        {1, 0, 1, 0, 0}     // 9
    };

    int codeArray[5] = {0};
    int tempPostalCode = postalCode;
    int checkDigit = 0;

    //  separate all the digits in an array
    for(int i = 0; i < 5; i++) {
        int last = tempPostalCode % 10;
        tempPostalCode = tempPostalCode / 10;
        codeArray[i] = last;

        checkDigit += last;
    }

    // to make sure that check digit condition
    checkDigit = checkDigit % 10;
    checkDigit = 10 - checkDigit;

    cout<< "|";
    for (int i = 4; i >= 0; i--) {
        int tempDigit = codeArray[i];
        for(int j = 0; j < 5; j++) {
            if (conversionArray[tempDigit][j] == 1) {
                cout << "|";
            } else {
                cout << ":";
            }
        }
    }

    // Print check digit bar code
    for(int j = 0; j < 5; j++) {
        if (conversionArray[checkDigit][j] == 1) {
            cout << "|";
        } else {
            cout << ":";
        }
    }
    cout<< "|" << endl;
}


// This method can be used to write recursive version
void printBarCode(int array[][5], int postalCode, int postalCodeSize) {
    if (postalCodeSize <= 0) {
        return;
    }
    int last = postalCode % 10;
    int abc = postalCode / 10;
    postalCodeSize--;
    printBarCode(array, abc, postalCodeSize);
    for(int i = 0; i < 5; i++) {
        if (array[last][i] == 1) {
            cout << "|";
        } else {
            cout << ":";
        }
    }
}


