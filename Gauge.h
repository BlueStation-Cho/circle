#ifndef GAUGE_H
#define GAUGE_H
#include <QWidget>

class Gauge : public QWidget
{
    Q_OBJECT
public:
    explicit Gauge(QWidget* parent = nullptr);

    void setResize(const QSize& size);

public slots:
    void setValue(const int value);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int m_value{ 0 };
    QSize size_;
};

#endif // GAUGE_H
