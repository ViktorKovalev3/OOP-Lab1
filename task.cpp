#include "task.h"
#include <cmath>

task::task(QObject *parent) :
    QObject(parent), polinom(0,0,0)
{
    //Connecting interface signals
    connect(
            &interface_w, SIGNAL(set_polinom_coeff(QString, QString, QString)),
            SLOT(set_polinom_coeff(QString,QString,QString))
            );
    connect(
            &interface_w, SIGNAL(starting_calculate_polinome(QString)),
            SLOT(calculate_polinom_and_roots(QString))
            );
    //Connecting task signals
    connect(
            this, SIGNAL(polinom_value_calculated(Complex)),
            &interface_w, SLOT(update_calculated_value(Complex))
            );
    connect(
            this, SIGNAL(roots_calculated(Complex, Complex)),
            &interface_w, SLOT(update_roots_val(Complex,Complex))
            );

    interface_w.show();
}

Complex parse_qstring_to_complex(QString a){
    return 12;
}


void task::set_polinom_coeff(QString a, QString b, QString c)
{
    polinom.set(parse_qstring_to_complex(a),
                parse_qstring_to_complex(b),
                parse_qstring_to_complex(b));
}

void task::calculate_polinom_and_roots(QString x)
{
    emit polinom_value_calculated(polinom.value(parse_qstring_to_complex(x)));
    Complex root1, root2;
    if (polinom.roots(&root1, &root2)){
        emit roots_calculated(root1, root2);
    }
}
