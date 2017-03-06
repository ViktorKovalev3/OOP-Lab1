#ifndef POLINOM_H
#define POLINOM_H
#include "complex.h"

class Polinom
{
private:
    Complex a, b, c;
public:
    Polinom(Complex, Complex, Complex);
    void set(Complex, Complex, Complex);
    bool roots(Complex*, Complex*);
    Complex value(Complex);
};

#endif // POLINOM_H
