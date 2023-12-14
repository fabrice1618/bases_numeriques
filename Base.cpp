#include <iostream>
#include <cstring>
#include <climits>
#include <cassert>

#include "Base.h"

Base::Base()
{
    raz();
}

Base::Base(int base)
{
    assert(base > 1 && base <= 10 + 26 + 26);

    raz();

    // Création des symboles pour la base avec l'ordre des symboles:
    // 0123456789ABCD...XYZabcd...xyz
    int n_symboles = base;
    int fin;
    // Création des chiffres
    fin = std::min(10, n_symboles);
    n_symboles -= add_range('0', '0' + fin - 1);

    // Création des majuscules
    if (n_symboles > 0) {
        fin = std::min(26, n_symboles);
        n_symboles -= add_range('A', 'A' + fin - 1);
    }

    // Création des minuscules
    if (n_symboles > 0) {
        fin = std::min(26, n_symboles);
        n_symboles -= add_range('a', 'a' + fin - 1);
    }

    assert(n_symboles == 0);
}

/*
Base::~Base()
{
}
*/

void Base::raz()
{
    memset(this->dec_base, 0, UCHAR_MAX * sizeof(char));
    memset(this->base_dec, -1, UCHAR_MAX * sizeof(int));
    this->add_pointer = 0;
}

int Base::get_base()
{
    return this->add_pointer;
}

int Base::add(char car)
{
    int index = (int)car;

    if (base_dec[index] != -1) {
        std::cerr << "Symbole " << car << " déjà présent" << std::endl;
        exit(1);
    }

    dec_base[add_pointer] = car;
    base_dec[index] = add_pointer;
    add_pointer++;

    return 1;
}

int Base::add_string(std::string symboles_in)
{
    int count = 0;

    for(unsigned int i = 0; i < symboles_in.length(); ++i)
    {
        count += add(symboles_in[i]);
    }

    return count;
}

int Base::add_range(char start, char end)
{
    int count = 0;

    assert(end >= start);

    for (char car = start; car <= end; car++) {
        count += add(car);
    }

    return count;
}

int Base::to_dec(char car)
{
    /*
    int index = (int)car;
    return base_dec[index]; */
    return base_dec[(int)car];
}

char Base::to_base(int num)
{
    return dec_base[num];
}

void Base::debug()
{
    std::cout << "Base :" << std::endl;
    std::cout << "> add_pointer:" << this->add_pointer << std::endl;
    std::cout << "> dec_base:" << std::endl;
    for (int i = 0; i < UCHAR_MAX; i++) {
        if (i % 10 == 0 && i != 0) {
            std::cout << std::endl;
        }
        std::cout << (int)dec_base[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "> base_dec:" << std::endl;
    for (int i = 0; i < UCHAR_MAX; i++) {
        if (i % 10 == 0 && i != 0) {
            std::cout << std::endl;
        }
        std::cout << base_dec[i] << " ";
    }
    std::cout << std::endl;
}