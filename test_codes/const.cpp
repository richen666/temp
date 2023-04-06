#include <iostream>

using namespace std;

const int getConst() {
    return 2;
}

int c = 10;
constexpr int square(int x) {
    return x * x;
}

int main() {
    int const cnt = 5;
    int arr[cnt];
    int brr[getConst()]; // compile-time
    int crr[square(3)] = {1};
    int crr_two[square(c)] = {0};
    return 0;
}