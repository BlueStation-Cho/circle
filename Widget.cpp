#include "Widget.h"
#include "./ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "widget width : " << ui->gaugeWidget->width();
    gauge = new Gauge(ui->gaugeWidget);

    connect(ui->horizontalSlider, &QSlider::sliderMoved, gauge, &Gauge::setValue);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent* event)
{
    gauge->setResize(event->size());
}
