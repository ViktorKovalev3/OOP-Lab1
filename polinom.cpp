#include "polinom.h"
#include <QtCore/qmath.h>

Polinom::Polinom(double new_a = 0.0, double new_b = 0.0, double new_c = 0.0)
{
    a = new_a; b = new_b; c = new_c;
}

void Polinom::set(double new_a, double new_b, double new_c)
{
    a = new_a; b = new_b; c = new_c;
}

bool Polinom::roots(double* root1, double* root2)
{
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return 0;
    else{
        *root1 = (- b - qSqrt(discriminant)) / (2 * a);
        *root2 = (- b + qSqrt(discriminant)) / (2 * a);
    }
    return 1;
}

double Polinom::value(double x)
{
    return a * x * x + b * x + c;
}

