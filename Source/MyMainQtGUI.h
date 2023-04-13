#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyMainQtGUI.h"
#include "BlankUser.h"

#include <QFileDialog>
#include <qimagereader.h>
#include <qvalidator.h> 
#include <vector>
#include "RESTClient.h"
#include <qradiobutton.h>

using namespace std;

class MyMainQtGUI : public QMainWindow
{
    Q_OBJECT

public:
    MyMainQtGUI(RESTClient *restClient, QWidget *parent = nullptr);
    ~MyMainQtGUI();

public slots:
    void CheckIsValidInput();

private:
    Ui::MyMainQtGUIClass ui;
    RESTClient *restClient;

    bool isCorrectEmail = false;
    bool isCorrectPhoto = false;

    vector<string> *positions;
    

    void BrowseFile();
};
