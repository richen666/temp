#include <iostream>
using namespace std;
struct A
{
    // ~A() noexcept(false) { throw 1; }
    ~A() noexcept { throw 1; }
};
struct B
{
    ~B() noexcept(false) { throw 2; }
};
struct C
{
    B b;
};
int funA() { A a; return 0; }
int funB() { B b; return 0; }
int funC() { C c; return 0; }
int main()
{
    try
    {
        funB();
    }
    catch (...)
    {
        cout << "caught funB." << endl; // caught funB.
    }
    try
    {
        funC();
    }
    catch (...)
    {
        cout << "caught funC." << endl; // caught funC.
    }
    try
    {
        funA(); // terminate called after throwing an instance of 'int'
    }
    catch (...)
    {
        cout << "caught funA." << endl;
    }
}