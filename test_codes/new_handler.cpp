#include <iostream>
#include <new>

std::new_handler old_handler = nullptr;

void handler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::cout << "accept nullptr." << std::endl;
    // std::set_new_handler(nullptr);
    std::set_new_handler(old_handler);
}

int main()
{
    std::cout << "accept handler." << std::endl;
    // old_handler = std::set_new_handler(handler);
    old_handler = std::set_new_handler(nullptr);
    std::cout << (old_handler == nullptr) << std::endl;
    try {
        std::cout << "acess circle." << std::endl;
        while (true) {
            new int[1000'000'000ul]();
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "arrive here? " << e.what() << '\n';
    }
}