#include <iostream>

using namespace std;

bool is_subarray(int arr1[], int arr2[], int size1, int size2);
bool is_rotated(int arr1[], int arr2[], int size);

int main() {

    int a[] = { 1, 4, 9, 16, 9, 7, 4, 9, 11};
    int b[] = { 11, 1, 4, 9, 16, 9, 7, 4, 9};

    cout << "Second array is ";
    cout << (is_rotated(a, b, 9) ? "" : "not ");
    cout << "rotation of the first array" << endl;

    return 0;
}

// Method to check if one array is subarray of second
bool is_subarray(int arr1[], int arr2[], int size1, int size2) {
    if (size2 > size1) {
        return false;
    }
    int k = 0;
    for (int i = 0; i < size1; i++) {
        if (arr1[i]  == arr2[k]) {
            k++;
        } else {
            k = 0;
        }

        // found second array in first as sub array
        if (k == size2) {
            return true;
        }
    }

    return (k == size2);
}

// Method to check if second array is rotation of first
bool is_rotated(int arr1[], int arr2[], int size) {
    int *combinedArray;
    combinedArray = (int *)malloc(sizeof(int) * size * 2);

    // create a combined array by appending first array to itself
    for (int i = 0; i < size; i++) {
        combinedArray[i] = arr1[i];
    }
    for (int i = 0; i < size; i++) {
        combinedArray[size+i] = arr1[i];
    }

    // we check if second array is rotation of first via
    // checking that second array present in combined array
    return is_subarray(combinedArray, arr2, size*2, size);
}

