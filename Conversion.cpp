#include <iostream>
#include <math.h>
#include <cassert>
#include <string>
#include <algorithm>

#include "Conversion.h"

Conversion::Conversion(Base *base, int val_max)
{
    //std::cout << "création Conversion" << std::endl;
    this->base = base;
    this->val_max = val_max;
    this->size = repr_size(val_max, this->base->get_base());
    this->buffer = "";
}

Conversion::~Conversion()
{
    //std::cout << "destruction Conversion" << std::endl;
}


void Conversion::real_convert(int val) 
{
    int reste;
    int base = this->base->get_base();

    this->buffer = "";
    
    if (val == 0) {
        this->buffer.push_back(this->base->to_base(0));
    } else {
        while (val > 0) {
            reste = val % base;
            val /= base;
            this->buffer.push_back( this->base->to_base(reste) );
        }
    }
}


std::string Conversion::convert(int val) 
{
    assert(val >= 0 && val <= this->val_max);

    real_convert(val);
    std::string rev(this->buffer.rbegin(), this->buffer.rend());

    return rev;
}

std::string Conversion::convert_padding(int val) 
{
    assert(val >= 0 && val <= this->val_max);

    real_convert(val);

    std::string result;
    int padding_len = (int)(this->size - this->buffer.size());
    for (int i = 0; i < padding_len; i++) {
        result.push_back( this->base->to_base(0) );
    }
    std::string rev(this->buffer.rbegin(), this->buffer.rend());
    result.append(rev);

    return result;
}

int Conversion::repr_size(int num_max, int base)
{
    return (int)(log(num_max) / log(base)) + 1;
}
