#include <iostream>
using namespace std;

template<class T>
T minimum(T par) {
    return par;
}

template<class T, class... Types>
T minimum(T first, Types... args) {
    T rest = minimum(args...);
    return (first < rest) ? first : rest;
}

int main() {
    cout << "Minimum: " << minimum(5, 3, 9, 2, 7) << endl;
    cout << "Minimum: " << minimum(2.2, 2.1, 2.4, 2.5, 2.8) << endl;
    cout << "Minimum: " << minimum('a', 'z', 'c', 'f', 'd') << endl;
    return 0;
}