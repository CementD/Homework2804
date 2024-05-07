#include <iostream>
using namespace std;

double sum(double param) {
    return param;
}

template <class... Types>
double sum(double first, Types... args) {
    double result = first;
    result += sum(args...);
    return result;
}

template <class... Types>
double average(double first, Types... args) {
    double suma = first;
    suma += sum(args...);
    double avg = suma / (sizeof...(args) + 1);
    return avg;
}

int main() {
    cout << "Average: " << average(1, 2, 3, 4, 5) << endl;
    return 0;
}