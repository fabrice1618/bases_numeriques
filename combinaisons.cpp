#include <iostream>

#include "Base.h"
#include "Conversion.h"

#define MAX_ITER 1000000

int main(void)
{
    Base base = Base();
    base.add_range('0', '9');
    base.add_range('a', 'z');
    base.add_range('A', 'Z');
    base.add_string("+-*/\%");

    Conversion conv = Conversion(&base, MAX_ITER);

    for (int i = 0; i < MAX_ITER; i++) {
        std::cout << "\t" << conv.convert(i);
    }

}
