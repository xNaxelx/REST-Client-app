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
#include <memory>

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
    unique_ptr<RESTClient> restClient;
    unique_ptr<vector<string>> positions;
    vector<BlankUser*> users;

    int currentPage = 1;
    int usersCountOnPage = 6;
    bool isCorrectEmail = false;
    bool isCorrectPhoto = false;


    void BrowseFile();
    void UploadUsersPage(unsigned int page, unsigned int countOnPage);
    bool UploadUsersList(unsigned int page, unsigned int countOnPage);
    void ShowMore(bool checked = false);
};
