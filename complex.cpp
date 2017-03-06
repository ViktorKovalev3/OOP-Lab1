#include "complex.h"
#include <limits>
#include <cmath>
Complex::Complex(double re, double im){
    this->re = re;
    this->im = im;
}

Complex& Complex::Re(double re){
    this->re = re;
    return *this;
}
Complex& Complex::Im(double im){
    this->im = im;
    return *this;
}

double Complex::Re() const{
    return re;
}

double Complex::Im() const{
    return im;
}

Complex& Complex::operator=(Complex a)
{
    re = a.re; im = a.im;
    return *this;
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

Complex& Complex::operator +(){
    return *this;
}

Complex& Complex::operator -(){
    re = - re; im = - im;
    return *this;
}
//Helpers functions
Complex operator+ (const Complex& a, const Complex& b){
    Complex c = a;
    return  c += b;
}

Complex operator- (const Complex& a, const Complex& b){
    Complex c = a;
    return  c -= b;
}

Complex operator*(const Complex& a, const Complex& b){
    Complex c = a;
    return  c *= b;
}

Complex operator/(const Complex& a, const Complex& b){
    Complex c = a;
    return  c /= b;
}

//#define SIGNUM(Val) ((Val) < 0 ? (-1) : !!(Val))
Complex sqrt(const Complex& a){
    //Look wikipedia: "Square roots of negative and complex numbers"
    double tmp_re, tmp_im;
    tmp_re = std::sqrt( (a.Re()   + std::sqrt(a.Re() * a.Re() + a.Im() * a.Im())) / 2);
    tmp_im = ((a.Re()) < 0 ? (-1) : !!(a.Re())) * std::sqrt( (- a.Re() + std::sqrt(a.Re() * a.Re() + a.Im() * a.Im())) / 2);
    return Complex(tmp_re, tmp_im);
}
