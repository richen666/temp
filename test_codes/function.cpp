#include <iostream>
#include <vector>
#include <functional>

using namespace std;
void print(int i) {
    cout << i << " ";
}

int main() {
    int ia[10] = {1, 2, 3, 4, 5, 10};
    vector<int> dec{ ia, ia +6 };
    vector<int> vec{ 1, 3, 3, 5, 10, 23 };
    for_each(dec.begin(), dec.end(), print);
    for_each(vec.begin(), vec.end(), print);
    for_each(vec.begin(), vec.end(), ptr_fun(print));
    return 0;
}