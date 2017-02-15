#ifndef TASK_H
#define TASK_H
#include <QObject>

#include "polinom.h"
#include "interface.h"

class task : public QObject
{
    Q_OBJECT
public:
    task(QObject *parent = 0);
public slots:
    void set_polinom_coeff(double, double, double);
    //0 - isn't ok (discriminant < 0), 1 - ok
    bool calculate_polinom_and_roots(double x);
signals:
    void roots_calculated(double, double);
    void polinom_value_calculated(double);
private:
    interface interface_w;
    Polinom polinom;
};

#endif // TASK_H
