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

    Complex& operator=(Complex);
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
    Complex& operator +();
    Complex& operator -();
private:
    double re, im;
};

//Helper functions
Complex operator+ (const Complex& a, const Complex& b);
Complex operator- (const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);
Complex sqrt(const Complex& a);

#endif // COMPLEX_H
