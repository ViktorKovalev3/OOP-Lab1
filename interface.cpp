#include "interface.h"
#include <QRegExpValidator>

interface::interface(QWidget *parent)
    : QWidget(parent)
{
    QValidator *double_filter = new QRegExpValidator(QRegExp("[+-]?\\d*\\.?\\d+"),0);

    QLabel* p_lbl_polinome = new QLabel("a*x^2+b*x+c");
    QPushButton* p_calculate_button = new QPushButton("Calculate");
    QLabel* p_lbl_a = new QLabel("a "); p_led_a = new  QLineEdit("0.0"); p_led_a->setValidator(double_filter);
    QLabel* p_lbl_b = new QLabel("b "); p_led_b = new  QLineEdit("0.0"); p_led_b->setValidator(double_filter);
    QLabel* p_lbl_c = new QLabel("c "); p_led_c = new  QLineEdit("0.0"); p_led_c->setValidator(double_filter);
    QLabel* p_lbl_x = new QLabel("x "); p_led_x = new  QLineEdit("0.0"); p_led_x->setValidator(double_filter);
    QLabel* p_lbl_px = new QLabel("p(x) = "); p_lbl_calculated_value = new QLabel("");
    QLabel* p_lbl_x1 = new QLabel("x1 = ");   p_lbl_root1 = new QLabel("");
    QLabel* p_lbl_x2 = new QLabel("x2 = ");   p_lbl_root2 = new QLabel("");

    QVBoxLayout* p_vbx_main_layout = new QVBoxLayout;
    QHBoxLayout* p_hbx_layout1     = new QHBoxLayout;
    QHBoxLayout* p_hbx_layout2     = new QHBoxLayout;
    QHBoxLayout* p_hbx_layout3     = new QHBoxLayout;
    QHBoxLayout* p_hbx_layout4     = new QHBoxLayout;
    QHBoxLayout* p_hbx_layout5     = new QHBoxLayout;
    QHBoxLayout* p_hbx_layout6     = new QHBoxLayout;

    p_vbx_main_layout->addWidget(p_lbl_polinome);
    p_hbx_layout1->addWidget(p_lbl_a) ; p_hbx_layout1->addWidget(p_led_a); p_hbx_layout1->addWidget(p_calculate_button);
    p_hbx_layout2->addWidget(p_lbl_b) ; p_hbx_layout2->addWidget(p_led_b); p_hbx_layout2->addStretch(1);
    p_hbx_layout3->addWidget(p_lbl_c) ; p_hbx_layout3->addWidget(p_led_c); p_hbx_layout3->addStretch(1);
    p_hbx_layout4->addWidget(p_lbl_x) ; p_hbx_layout4->addWidget(p_led_x); p_hbx_layout4->addStretch(1);
    p_hbx_layout5->addWidget(p_lbl_px); p_hbx_layout5->addWidget(p_lbl_calculated_value); p_hbx_layout5->addStretch(1);
    p_hbx_layout6->addWidget(p_lbl_x1); p_hbx_layout6->addWidget(p_lbl_root1);
    p_hbx_layout6->addWidget(p_lbl_x2); p_hbx_layout6->addWidget(p_lbl_root2);

    p_vbx_main_layout->addLayout(p_hbx_layout1);
    p_vbx_main_layout->addLayout(p_hbx_layout2);
    p_vbx_main_layout->addLayout(p_hbx_layout3);
    p_vbx_main_layout->addLayout(p_hbx_layout4);
    p_vbx_main_layout->addLayout(p_hbx_layout5);
    p_vbx_main_layout->addLayout(p_hbx_layout6);

    this->setLayout(p_vbx_main_layout);

    connect(p_calculate_button, SIGNAL(clicked()),
            this, SLOT(calculate_button_pressed()));
}

void interface::update_roots_val(double root1, double root2)
{
    p_lbl_root1->setText(QString::number(root1));
    p_lbl_root2->setText(QString::number(root2));
}

void interface::update_polinom_val(double polinom_value)
{
    p_lbl_calculated_value->setText(QString::number(polinom_value));
}

void interface::calculate_button_pressed()
{
    emit starting_calculate_polinome(p_led_x->text().toDouble());
    emit set_polinom_coeff(
                p_led_a->text().toDouble(),
                p_led_b->text().toDouble(),
                p_led_c->text().toDouble()
                );
}

interface::~interface(){}
