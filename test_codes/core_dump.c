#include <stdio.h>
#include <assert.h>

int main() {
    printf("Before assertion!\n");
    assert(0);
    printf("After assertion!\n");
}