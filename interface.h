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
public slots:
    void update_roots_val(double, double);
    void update_polinom_val(double);
signals:
    void set_polinom_coeff(double, double, double);
    void starting_calculate_polinome(double);
private:
    QLabel* p_lbl_root1;
    QLabel* p_lbl_root2;
    QLabel* p_lbl_calculated_value;
    QLineEdit* p_led_a;
    QLineEdit* p_led_b;
    QLineEdit* p_led_c;
    QLineEdit* p_led_x;
private slots:
    void calculate_button_pressed();
};

#endif // INTERFACE_H
