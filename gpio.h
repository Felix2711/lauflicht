#ifndef GPIO_H
#define GPIO_H

#include <QObject>

const int CHIP = 0;
const int FLAGS = 0;
const QList<int> LEDS = {18, 23, 24, 25};

class Gpio : public QObject
{
    Q_OBJECT
public:
    explicit Gpio(QObject *parent = nullptr);
    void set(int pin, bool state);

private:
    int m_handle;

};

#endif // GPIO_H
