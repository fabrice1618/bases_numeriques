#pragma once
#include <climits>

class Base {
private:
    char dec_base[UCHAR_MAX];
    int base_dec[UCHAR_MAX];
    int add_pointer;

public:
    Base();
    Base(int base);
//    ~Base() {};
    void debug();
    int get_base();
    int add(char car);
    int add_string(std::string symboles_in);
    int add_range(char start, char end);
    int to_dec(char car);
    char to_base(int num);

private:
    void raz();
};
