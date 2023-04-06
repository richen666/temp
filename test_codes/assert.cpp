#include <cstring>
using namespace std;

#define assert_static(e) \
    do { \
        enum { assert_static__ = 1/(e) }; \
    } while (0)

// template <typename T, typename U>
// void bit_copy(T &a, U &b)
// {
//     assert_static(sizeof(b) == sizeof(a));
//     memcpy(&a, &b, sizeof(b));
// };

template <typename t, typename u> void bit_copy(t& a, u& b) {
    static_assert(sizeof(b) == sizeof(a),
    "the parameters of bit_copy must have same width.");
};

int main()
{
    int a = 0x2468;
    // int b = 0x1234;
    double b;
    bit_copy(a, b);
}