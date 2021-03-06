#include "interface.h"
#include <QRegExpValidator>

interface::interface(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle(tr("Polinom calculator"));
    this->setMinimumSize(300, 300);

    p_lbl_polinome = new QLabel("a*x<sup>2</sup>+b*x+c", this);
    QString tmp_Rexp = "^([-+]?(\\d+\\.?\\d*|\\d*\\.?\\d+)([Ee][-+]?[0-2]?\\d{1,2})?[r]?|[-+]?((\\d+\\.?\\d*|\\d*\\.?\\d+)([Ee][-+]?[0-2]?\\d{1,2})?)?[i]|[-+]?(\\d+\\.?\\d*|\\d*\\.?\\d+)"
                       "([Ee][-+]?[0-2]?\\d{1,2})?[r]?[-+]((\\d+\\.?\\d*|\\d*\\.?\\d+)([Ee][-+]?[0-2]?\\d{1,2})?)?[i])$";
    QValidator *complex_filter = new QRegExpValidator(QRegExp(tmp_Rexp), this);
    QPushButton* p_calculate_button = new QPushButton("Calculate");

    QLabel* p_lbl_a = new QLabel("a ", this); p_led_a = new  QLineEdit("0.0");
    p_led_a->setValidator(complex_filter);
    QLabel* p_lbl_b = new QLabel("b "); p_led_b = new  QLineEdit("0.0");
    p_led_b->setValidator(complex_filter);
    QLabel* p_lbl_c = new QLabel("c "); p_led_c = new  QLineEdit("0.0");
    p_led_c->setValidator(complex_filter);
    QLabel* p_lbl_x = new QLabel("x "); p_led_x = new  QLineEdit("0.0");
    p_led_x->setValidator(complex_filter);

    p_lbl_calculated_value = new QLabel("p(x) = ");
    p_lbl_root1 = new QLabel("x<sub>1</sub> = nan");
    p_lbl_root2 = new QLabel("x<sub>2</sub> = nan");

    QGridLayout* p_glayout = new QGridLayout;
    p_glayout->addWidget(p_lbl_polinome, 0, 0, 1, 3);
    p_glayout->addWidget(p_lbl_a, 1, 0); p_glayout->addWidget(p_led_a, 1, 1); p_glayout->addWidget(p_calculate_button, 1, 2);
    p_glayout->addWidget(p_lbl_b, 2, 0); p_glayout->addWidget(p_led_b, 2, 1);
    p_glayout->addWidget(p_lbl_c, 3, 0); p_glayout->addWidget(p_led_c, 3, 1);
    p_glayout->addWidget(p_lbl_x, 4, 0); p_glayout->addWidget(p_led_x, 4, 1);
    p_glayout->addWidget(p_lbl_calculated_value, 5, 1);
    p_glayout->addWidget(p_lbl_root1, 6, 1); p_glayout->addWidget(p_lbl_root2, 6, 2);

    this->setLayout(p_glayout);

    connect(p_calculate_button, SIGNAL(clicked()),
            this, SLOT(calculate_button_pressed()));
    connect(p_led_a, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_b, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
    connect(p_led_c, SIGNAL(textEdited(QString)), this, SLOT(update_polinom()));
}

void interface::update_roots_val(Complex root1, Complex root2)
{
    p_lbl_root1->setText("x<sub>1</sub> = " + QString::number(root1.Re(),'g',10)
                         + " + " + QString::number(root1.Im(),'g',10)+"i");
    p_lbl_root2->setText("x<sub>2</sub> = " + QString::number(root2.Re(),'g',10)
                         + " + " + QString::number(root2.Im(),'g',10)+"i");
}

void interface::update_calculated_value(Complex polinom_value)
{
    p_lbl_calculated_value->setText(tr("p(%0) = ").arg(p_led_x->text()) +
                                    QString::number(polinom_value.Re()) + " + " +
                                    QString::number(polinom_value.Im()) + "i");
}

void interface::calculate_button_pressed()
{
    emit set_polinom_coeff(
                p_led_a->text(),
                p_led_b->text(),
                p_led_c->text()
                );
    emit starting_calculate_polinome(p_led_x->text());
}

void interface::update_polinom()
{
    p_lbl_polinome->setText(tr("(%1)*x<sup>2</sup>+(%2)*x+(%3)").arg(
                                p_led_a->text(),
                                p_led_b->text(),
                                p_led_c->text()));
}
