#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include "complex.h"

class interface : public QWidget
{
    Q_OBJECT

public:
    interface(QWidget *parent = 0);
public slots:
    void update_roots_val(Complex, Complex);
    void update_calculated_value(Complex);
signals:
    void set_polinom_coeff(QString, QString, QString);
    void starting_calculate_polinome(QString);
private:
    QLabel *p_lbl_root1, *p_lbl_root2,
           *p_lbl_calculated_value, *p_lbl_polinome;
    QLineEdit *p_led_a, *p_led_b, *p_led_c, *p_led_x;
private slots:
    void calculate_button_pressed();
    void update_polinom();
};

#endif // INTERFACE_H
