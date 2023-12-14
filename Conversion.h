#pragma once
#include <string>

#include "Base.h"

class Conversion {
private:
    std::string buffer;
    //char *buffer;
    //char *pointer;
    int size;
    int val_max;
    Base *base;
public:    
    Conversion(Base *base, int val_max);    
    ~Conversion();    
    std::string convert(int val);
    std::string convert_padding(int val);

private:
    int repr_size(int num_max, int base);
    void real_convert(int val);
};

/*
#ifndef REPRESENTATION_H
#define REPRESENTATION_H

#include "symboles.h"

typedef struct repr_t {
    char *buffer;
    char *pointer;
    int size;
    int val_max;
    Symboles *symboles;
} Representation;

Representation *repr_init(Symboles *symboles, int val_max);
void repr_close(Representation *repr);
void repr_clear(Representation *repr);
void repr_push(Representation *repr, char car);
void repr_convert(Representation *repr, int val);
int repr_size(int num_max, int base);
char *repr_read(Representation *repr);
char *repr_read_padding(Representation *repr);

#endif
*/