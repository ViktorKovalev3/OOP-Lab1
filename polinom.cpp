#include "polinom.h"

Polinom::Polinom(Complex new_a = 0.0, Complex new_b = 0.0, Complex new_c = 0.0)
{
    a = new_a; b = new_b; c = new_c;
}

void Polinom::set(Complex new_a, Complex new_b, Complex new_c)
{
    a = new_a; b = new_b; c = new_c;
}

bool Polinom::roots(Complex *root1, Complex *root2)
{
    Complex discriminant = b * b - 4 * a * c;
    try{
        *root1 = (- b - sqrt(discriminant)) / (2 * a);
        *root2 = (- b + sqrt(discriminant)) / (2 * a);
    }catch(Zero_Divide){
        return 1;
    }
    return 0;
}

Complex Polinom::value(Complex x)
{
    return a * x * x + b * x + c;
}

