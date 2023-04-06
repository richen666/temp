#include <iostream>

using namespace std;

class HasPtrMem {
public:
    HasPtrMem(): d(new int(0)) {
        cout << "Construct: " << ++n_cstr << endl;
    }

    // const HasPtrMem& operator =(const HasPtrMem &) = delete;

    HasPtrMem(const HasPtrMem & h): d(new int(*h.d)) {
        cout << "Copy construct: " << ++n_cptr << endl;
    }
    ~HasPtrMem() {
        cout << "Destruct: " << ++n_dstr << endl;
    }
    int * d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTemp() {
    return HasPtrMem();
}

int main() {
    HasPtrMem a = GetTemp();
}
// 应加上-std=c++11选项，否则执行结果错误
// 编译选项:g++ -std=c++11 copy_construct.cpp -fno-elide-constructors