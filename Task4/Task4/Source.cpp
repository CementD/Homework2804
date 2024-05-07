#include <iostream>
#include <initializer_list>
using namespace std;

double average(std::initializer_list<double> nums) {
    double sum = 0.0;
    for (double value : nums) {
        sum += value;
    }
    return sum / nums.size();
}

int main() {
    cout << "Average: " << average({1, 2, 3, 4, 5}) << endl;
    return 0;
}