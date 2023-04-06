#include <iostream>
using namespace std;

enum {_ALIGN = 8};

// typedef unsigned int size_t;

static inline size_t _S_round_up(size_t __bytes)
{ return (((__bytes) + (size_t)_ALIGN-1) & ~((size_t)_ALIGN - 1)); }

int main() {
    size_t result = _S_round_up(12);
    cout << result << endl;
}