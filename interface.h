#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>

class interface : public QWidget
{
    Q_OBJECT

public:
    interface(QWidget *parent = 0);
    ~interface();
//public slots:
//    void update_roots(double, double);
//    void update_polinom_value(double);
signals:
    void set_polinom_coeff(double, double, double);
};

#endif // INTERFACE_H
