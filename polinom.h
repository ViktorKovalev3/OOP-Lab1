#ifndef POLINOM_H
#define POLINOM_H


class Polinom
{
private:
    double a, b, c;
public:
    Polinom(double, double, double);
    void set(double, double, double);
    //0 - isn't ok (discriminant < 0), 1 - ok
    bool roots(double*, double*);
    double value(double);
};

#endif // POLINOM_H
