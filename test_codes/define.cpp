
#include <iostream>
#include <cstring>

using namespace std;

// #define TRACE_STRINGIFY(item) "" #item
// #define TRACE(macro, message)                                \
//     do {
//         int ret = strcmp("" #macro, TRACE_STRINGIFY(macro));  \
//         std::cout << ret << std::endl;                                 \
//         if (ret)                                             \
//             std::cout << message << "\n";                    \
//     } while (0)
#define TESTa 2

// #define TRACE_STRINGIFY(item) "" #item
// #define TRACE(macro, message)                          \
//     do {                                               \
//         if (strcmp("" #macro, TRACE_STRINGIFY(macro))) \
//             std::cout << TRACE_STRINGIFY(macro) << " " << strcmp("" #macro, TRACE_STRINGIFY(macro)) << " " << message << "\n";              \
//     } while (0)

#define TRACE_STRINGIFY(item) "" #item
#define TRACE(macro, message)                          \
    do {                                               \
        cout << "" #macro << " ";                      \
        if (strcmp("" #macro, TRACE_STRINGIFY(macro))) \
            std::cout << "" #macro << " " << message << "\n";              \
    } while (0)

#define TEST1 TEST1

#define TEST3
#define TEST4 0
#define TEST5 1
#define TEST6 "string"
#define TEST7 ""
#define TEST8 NULL
#define TEST9 TEST3
#define TEST10 TEST2
#define TEST11(x)

#define TEST13(x,y,z) (x, y, z)

int main(void)
{
    cout << TRACE_STRINGIFY(TESTa) << endl;
    cout << endl;

    TRACE(TEST1, "TEST1 is defined");
    TRACE(TEST2, "TEST2 is defined");
    TRACE(TEST3, "TEST3 is defined");
    TRACE(TEST4, "TEST4 is defined");
    TRACE(TEST5, "TEST5 is defined");
    TRACE(TEST6, "TEST6 is defined");
    TRACE(TEST7, "TEST7 is defined");
    TRACE(TEST8, "TEST8 is defined");
    TRACE(TEST9, "TEST9 is defined");
    TRACE(TEST10, "TEST10 is defined");
    TRACE(TEST11, "TEST11 is defined");
    TRACE(TEST12, "TEST12 is defined");
    TRACE(TEST13, "TEST13 is defined");
    TRACE(TEST14, "TEST14 is defined");

    TRACE(TEST1(), "TEST1() is defined");
    TRACE(TEST2(), "TEST2() is defined");
    TRACE(TEST3(), "TEST3() is defined");
    TRACE(TEST4(), "TEST4() is defined");
    TRACE(TEST5(), "TEST5() is defined");
    TRACE(TEST6(), "TEST6() is defined");
    TRACE(TEST7(), "TEST7() is defined");
    TRACE(TEST8(), "TEST8() is defined");
    TRACE(TEST9(), "TEST9() is defined");
    TRACE(TEST10(), "TEST10() is defined");
    TRACE(TEST11(), "TEST11() is defined");
    TRACE(TEST12(), "TEST12() is defined");
    TRACE(TEST13(,,), "TEST13(,,) is defined");
    TRACE(TEST14(,,), "TEST14(,,) is defined");

    return 0;
}