#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
};

#endif // GUI_H
