#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    m_leds = LEDS;

    m_timer = new QTimer(this);
    m_gpio = new Gpio(this);

    m_uiLEDs = {led0, led1, led2, led3};
    connect(m_timer, &QTimer::timeout, this, &Gui::loop);
    m_dir = true;
}

void Gui::loop()
{
    if(m_dir)
    {
        m_gpio->set(m_leds.first(), true);
        m_gpio->set(m_leds.last(), false);

        m_uiLEDs.first()->setChecked(true);
        m_uiLEDs.last()->setChecked(false);

        m_uiLEDs.move(0,m_uiLEDs.count()-1);
        m_leds.move(0,m_leds.count()-1);
    }
    else
    {
        m_gpio->set(m_leds.last(), true);
        m_gpio->set(m_leds.first(), false);

        m_uiLEDs.last()->setChecked(true);
        m_uiLEDs.first()->setChecked(false);

        m_uiLEDs.move(m_uiLEDs.count()-1, 0);
        m_leds.move(m_leds.count()-1, 0);
    }
}

void Gui::on_startButton_clicked()
{
    m_timer->start(1000/speed->value());
}

void Gui::on_stopButton_clicked()
{
    m_timer->stop();
}

void Gui::on_speed_valueChanged(int value)
{
    m_timer->setInterval(1000/value);
}

void Gui::on_dirButton_clicked()
{
    m_dir = !m_dir;
}
