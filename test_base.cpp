#include <iostream>
#include <cassert>

#include "Base.h"

#define TEST_OK "OK"
#define TEST_FAIL "FAIL"

// Test création de structure symboles
int test1() 
{
    Base base = Base();

    base.debug();

    assert(base.get_base() == 0);

    return true;
}

// Test création de structure symboles
int test2() 
{
    Base base = Base();

    base.add('0');
    base.add('1');
    base.add('2');

    assert(base.get_base() == 3);
    assert(base.to_base(0) == '0');
    assert(base.to_base(1) == '1');
    assert(base.to_base(2) == '2');
    assert(base.to_dec('0') == 0);
    assert(base.to_dec('1') == 1);
    assert(base.to_dec('2') == 2);

    return true;
}

// Test création de binaire avec constructeur
int test3() 
{
    Base base = Base(2);

    assert(base.get_base() == 2);
    assert(base.to_base(0) == '0');
    assert(base.to_base(1) == '1');
    assert(base.to_dec('0') == 0);
    assert(base.to_dec('1') == 1);

    return true;
}

// Test création de base décimale
int test4() 
{
    Base base = Base();

    base.add_range('0', '9');

    assert(base.get_base() == 10);
    assert(base.to_base(0) == '0');
    assert(base.to_base(1) == '1');
    assert(base.to_base(9) == '9');
    assert(base.to_dec('0') == 0);
    assert(base.to_dec('1') == 1);
    assert(base.to_dec('9') == 9);

    return true;
}

// Test création avec chaine de caractères
int test5() 
{
    Base base = Base();

    base.add_string("+-*/");

    assert(base.get_base() == 4);
    assert(base.to_base(0) == '+');
    assert(base.to_base(1) == '-');
    assert(base.to_base(2) == '*');
    assert(base.to_base(3) == '/');
    assert(base.to_dec('+') == 0);
    assert(base.to_dec('-') == 1);
    assert(base.to_dec('*') == 2);
    assert(base.to_dec('/') == 3);

    return true;
}

// Test création hexadécimal avec constructeur
int test6() 
{
    Base base = Base(16);

    assert(base.get_base() == 16);
    assert(base.to_base(0) == '0');
    assert(base.to_base(1) == '1');
    assert(base.to_base(9) == '9');
    assert(base.to_base(10) == 'A');
    assert(base.to_base(15) == 'F');
    assert(base.to_dec('0') == 0);
    assert(base.to_dec('1') == 1);
    assert(base.to_dec('9') == 9);
    assert(base.to_dec('A') == 10);
    assert(base.to_dec('F') == 15);

    return true;
}

// Programme principal
int main() 
{
    bool tests;

    tests = test1() && test2() && test3() && test4() && test5() && test6();

    std::cout << "test_base: " << (tests? TEST_OK: TEST_FAIL) << std::endl;

    return EXIT_SUCCESS;
}
