#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>

class Zero_Divide{
};

class Complex
{
public:
    Complex(double re = 0.0, double im = 0.0);
    //accesses the real part of the complex number
    Complex& Re(double);
    double Re() const;
    //accesses the imaginary part of the complex number
    Complex& Im(double);
    double Im() const;

    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
    Complex& operator +(const Complex&);
    Complex& operator -(const Complex&);
private:
    double re, im;
};

#endif // COMPLEX_H
