#include <iostream>

#define SQUARE_SIZE 4

using namespace std;

bool check_all_number_preset(int square [][SQUARE_SIZE]);
bool magic_square(int square [][SQUARE_SIZE]);

int main() {

    int square[SQUARE_SIZE][SQUARE_SIZE];
    int num;

    cout << "Enter all the numbers for the square: " << endl;

    for(int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            cin >> num;
            square[i][j] = num;
        }
    }

    cout << "All numbers 1, 2..16 are ";
    cout << (check_all_number_preset(square) ? "": "not ");
    cout << "present in matrix." << endl;

    cout << "This is ";
    cout << (magic_square(square) ? "": "not ");
    cout << "a Magic squares." << endl;
    return 0;
}

// Check if all numbers are present in the matrix
bool check_all_number_preset(int square [][SQUARE_SIZE]) {
    int total = 0;
    for(int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            total += square[i][j];
        }
    }
    int n = SQUARE_SIZE * SQUARE_SIZE;

    int nTotal = n*(n + 1) / 2;

    // If sum of all numbers equal to n(n+1)/2, it means all numbers are present.
    if (total == nTotal) {
        return true;
    }

    return false;
}

// Method to determine if given matrix is a Magic matrix
bool magic_square(int square [][SQUARE_SIZE]) {
    int row_sum[SQUARE_SIZE] = {0};
    int column_sum[SQUARE_SIZE] = {0};
    int diaognal_sum[2] = {0};

    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = 0; j < SQUARE_SIZE; j++) {
            // sum each rows
            row_sum[i] += square[i][j];
            // sum each columns
            column_sum[j] += square[i][j];

            // calculate diaognal sum (0,0:1,1:2,2:3,3)
            if (i == j) {
                diaognal_sum[0] += square[i][j];
            } else if (i+j == SQUARE_SIZE-1) {  //calculate other diaognal (0,3:1,2:2,1:3,0)
                diaognal_sum[1] += square[i][j];
            }
        }
    }
    int sum = row_sum[0];
    // check if rows and column have same total
    for (int i = 0; i < SQUARE_SIZE; i++) {
        if (row_sum[i] != sum || column_sum[i] != sum) {
            return false;
        }
    }
    // check if diaognal have same total
    if (diaognal_sum[0] != sum || diaognal_sum[1] != sum) {
        return false;
    }

    return true;
}
