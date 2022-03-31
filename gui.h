#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"

#include <QTimer>
#include <QList>

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_speed_valueChanged(int value);
    void on_dirButton_clicked();


private:
    void loop();

    bool m_dir;
    bool m_state;

    QList<QRadioButton*> m_uiLEDs;
    QTimer *m_timer;
};

#endif // GUI_H
