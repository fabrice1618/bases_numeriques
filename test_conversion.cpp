#include <iostream>
#include <cassert>

#include "Base.h"
#include "Conversion.h"

#define TEST_OK "OK"
#define TEST_FAIL "FAIL"

// Test conversion
int test1() 
{
    Base base2 = Base(2);
    Conversion conv = Conversion(&base2, 255);

    assert(conv.convert(0).compare("0") == 0);
    assert(conv.convert_padding(0) == "00000000");
    assert(conv.convert(1) == "1");
    assert(conv.convert_padding(1) == "00000001");
    assert(conv.convert(255) == "11111111");
    assert(conv.convert_padding(255) == "11111111");

    return true;
}

// Test conversion
int test2() 
{
    Base base16 = Base(16);
    Conversion conv = Conversion(&base16, 255);

    assert(conv.convert(0) == "0");
    assert(conv.convert_padding(0) == "00");
    assert(conv.convert(1) == "1");
    assert(conv.convert_padding(1) == "01");
    assert(conv.convert(255) == "FF");
    assert(conv.convert_padding(255) == "FF");

    return true;
}

// Test conversion décimal
int test3() 
{
    Base base10 = Base(10);
    Conversion conv = Conversion(&base10, 100);

    assert(conv.convert(0) == "0");
    assert(conv.convert_padding(0) == "000");
    assert(conv.convert(1) == "1");
    assert(conv.convert_padding(1) == "001");
    assert(conv.convert(99) == "99");
    assert(conv.convert_padding(99) == "099");

    return true;
}

// Test conversion
int test4() 
{
    Base base = Base();
    base.add_string("O!?E");

    Conversion conv = Conversion(&base, 100);

    std::cout << "conversion: " << conv.convert_padding(0) << std::endl;

    assert(conv.convert(0) == "O");
    assert(conv.convert_padding(0) == "OOOO");
    assert(conv.convert(1) == "!");
    assert(conv.convert_padding(1) == "OOO!");

    return true;
}

// Programme principal
int main() 
{
    bool tests;

    tests = test1() && test2() && test3() && test4();

    std::cout << "test_conversion: " << (tests? TEST_OK: TEST_FAIL) << std::endl;

    return EXIT_SUCCESS;
}
