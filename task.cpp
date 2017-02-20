#include "task.h"

task::task(QObject *parent) :
    QObject(parent), polinom(0,0,0)
{
    //Connecting interface signals
    connect(
            &interface_w, SIGNAL(set_polinom_coeff(double,double,double)),
            SLOT(set_polinom_coeff(double,double,double))
            );
    connect(
            &interface_w, SIGNAL(starting_calculate_polinome(double)),
            SLOT(calculate_polinom_and_roots(double))
            );
    //Connecting task signals
    connect(
            this, SIGNAL(polinom_value_calculated(double)),
            &interface_w, SLOT(update_calculated_value(double))
            );
    connect(
            this, SIGNAL(roots_calculated(double,double)),
            &interface_w, SLOT(update_roots_val(double,double))
            );

    interface_w.show();
}

void task::set_polinom_coeff(double a, double b, double c)
{
    polinom.set(a, b, c);
}

bool task::calculate_polinom_and_roots(double x)
{
    emit polinom_value_calculated(polinom.value(x));
    double root1 = 0.0, root2 = 0.0;
    if (polinom.roots(&root1, &root2)){
        emit roots_calculated(root1, root2);
        return 1;
    } else
        return 0;
}
