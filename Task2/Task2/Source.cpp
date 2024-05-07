#include "Array.h"
#include <iostream>
using namespace std;

int main() {
    Array<int> arr { 1, 2, 3, 4, 5 };

    for (int i = 6; i <= 11; i++) {
        arr.Add(i);
    }

    for (int i = 0; i < arr.GetSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}