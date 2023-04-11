#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyMainQtGUI.h"
#include "BlankUser.h"

#include <QFileDialog>
#include <qimagereader.h>
#include <qvalidator.h>

class MyMainQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    MyMainQtGUI(QWidget *parent = nullptr);
    ~MyMainQtGUI();

public slots:
    void CheckIsValidEmail();

private:
    Ui::MyMainQtGUIClass ui;

    bool isCorrectEmail = false, isCorrectPhoto = false;
    

    void BrowseFile();
};
