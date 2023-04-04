#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyMainQtGUI.h"

class MyMainQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    MyMainQtGUI(QWidget *parent = nullptr);
    ~MyMainQtGUI();

private:
    Ui::MyMainQtGUIClass ui;
};
