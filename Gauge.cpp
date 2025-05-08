#include "Gauge.h"
#include <QPainter>

Gauge::Gauge(QWidget* parent)
    : QWidget(parent)
{
    qDebug() << "width : " << parent->width();
    size_ = QSize(parent->width(), parent->height());
    setFixedSize(size_);
}

void Gauge::setValue(const int value)
{
    if (m_value != value) {
        m_value = qBound(0, value, 100);
        update();
    }
}

void Gauge::setResize(const QSize& size)
{
    size_ = size;
    setFixedSize(size);
    update();
}

void Gauge::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    auto size = qMin(width(), height()) - 80;
    QRectF rect(20, 20, size, size);

    QPen pen(QColor(0xeaeaea), 20, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);
    painter.drawEllipse(rect);

    pen.setColor(QColor(0x4a62ad));
    painter.setPen(pen);
    painter.drawArc(rect, 90 * 16, -m_value * 16 * 3.6);

    painter.setPen(QColor(0x333333));
    QFont font = painter.font();
    font.setBold(true);
    font.setPointSize(size / 5);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, QString::number(m_value) + "%");
}
