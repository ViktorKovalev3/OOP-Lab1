#include "complex.h"
#include <limits>
Complex::Complex(double re, double im){
    this->re = re;
    this->im = im;
}

Complex& Complex::Re(double re){
    this->re = re;
}
Complex& Complex::Im(double im){
    this->im = im;
}

double Complex::Re() const{
    return re;
}

double Complex::Im() const{
    return im;
}

Complex& Complex::operator+=(const Complex &a){
    re += a.re; im += a.im;
    return *this;
}

Complex& Complex::operator-=(const Complex &a){
    re -= a.re; im -= a.im;
    return *this;
}
//(a+bi)(c+di)=(ac-bd)+(bc+ad)i
Complex& Complex::operator*=(const Complex& a){
    //It's tmp, because we need "re" for next "im"
    double tmp_re = re * a.re - im * a.im;
    im = im * a.re + re * a.im;
    re = tmp_re;
    return *this;
}
//(a+bi)/(c+di)=(ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i
Complex& Complex::operator/=(const Complex& a){
    double tmp_denominator = a.re * a.re + a.im * a.im;
    if (tmp_denominator + 1.0 > std::numeric_limits<double>::epsilon() + 1.0){
        //It's tmp, because we need "re" for next "im"
        double tmp_re = (re * a.re + im * a.im)/tmp_denominator;
        im = (im * a.re - re * a.im)/tmp_denominator;
        re = tmp_re;
    } else
        throw Zero_Divide();
    return *this;
}

Complex& Complex::operator +(const Complex &a){
    return *this;
}

Complex& Complex::operator -(const Complex &a){
    re = - re; im = - im;
    return *this;
}
