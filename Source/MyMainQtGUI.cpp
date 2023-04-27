#include "MyMainQtGUI.h"

MyMainQtGUI::MyMainQtGUI(RESTClient* restClient, QWidget *parent)
    : QMainWindow(parent)
{
    this->restClient = make_unique<RESTClient>(*restClient);

    ui.setupUi(this);

    QRegularExpression rx("[a-zA-Z0-9_.%]+\@[a-zA-Z0-9]+\\.[a-zA-Z0-9]{1,100}", QRegularExpression::CaseInsensitiveOption);
    ui.lineEdit_2->setValidator(new QRegularExpressionValidator(rx, this));

    positions = make_unique<vector<string>>(*restClient->GETPositions());
    for (auto it = positions->begin(); it != positions->end(); it += 2)
    {
        auto button = new QRadioButton(ui.groupBox);
        button->setGeometry(QRect(10, 30 * ui.groupBox->children().count(), 201, 20));
        button->setText((++it)->c_str());
        --it;
        button->setProperty("id", QVariant((int)(it->c_str())));
    }

    UploadUsersPage(1, 6);

    ui.verticalLayout->setAlignment(Qt::AlignTop);

    QObject::connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &MyMainQtGUI::CheckIsValidInput);
    QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &MyMainQtGUI::BrowseFile);
    QObject::connect(ui.pushButton, &QPushButton::clicked, this, &MyMainQtGUI::ShowMore);
}

MyMainQtGUI::~MyMainQtGUI()
{}

void MyMainQtGUI::BrowseFile()
{
    isCorrectPhoto = false;
    QFileInfo photoInfo(QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.jpg *.jpeg)")));
    QImageReader photo(photoInfo.absoluteFilePath());

    if (photoInfo.size() >= 5242880)
    {
        ui.lineEdit_4->setText("Photo must not exceed 5 MB");
    }
    else if (photoInfo.size() <= 0)
    {
        ui.lineEdit_4->setText("Upload a photo");
    }
    else if (photo.size().width() <= 70 || photo.size().height() <= 70 || photo.size().width() > 4096 || photo.size().height() > 4096)
    {
        ui.lineEdit_4->setText("Upload a photo from 70x70 up to 4096x4096");
    }
    else if (photo.format() != "jpg" && photo.format() != "jpeg")
    {
        ui.lineEdit_4->setText("Upload a photo format jpg or jpeg");
    }
    else 
    {
        ui.lineEdit_4->setText(photoInfo.absoluteFilePath());
        isCorrectPhoto = true;
    }
}

void MyMainQtGUI::CheckIsValidInput()
{
    if (ui.lineEdit_2->hasAcceptableInput())
    {
        ui.lineEdit_2->setStyleSheet("QLineEdit { color: black;}");
    }
    else if (ui.lineEdit_2->text() == "") 
    {
        ui.lineEdit_2->setStyleSheet("QLineEdit { color: black;}");
    }
    else
    {
        ui.lineEdit_2->setStyleSheet("QLineEdit { color: red;}");
    }
}

bool MyMainQtGUI::UploadUsersList(unsigned int page, unsigned int countOnPage)
{
    for (int i = countOnPage; i != 0; i--)
    {
        ui.verticalLayout->addWidget(new BlankUser(nullptr));
    }

    return true;
}

void MyMainQtGUI::UploadUsersPage(unsigned int page, unsigned int countOnPage)
{
    vector<QString>* userList = restClient->GETUsers(currentPage, countOnPage);

    if(currentPage == 1)
    {   
        for (int i = 0; i < usersCountOnPage; i++)
        {
            users.push_back(new BlankUser((*userList)[i * 6 + 0], (*userList)[i * 6 + 1], (*userList)[i * 6 + 2], (*userList)[i * 6 + 3], (*userList)[i * 6 + 4]));
            ui.verticalLayout->addWidget(users[i]);
        }
    }
    else if(userList->size() / 6 % countOnPage == 0 && userList->size() != 0)
    {
        for (int i = 0; i < countOnPage; i++)
        {
            users[i]->ChangeContent((*userList)[i * 6 + 0], (*userList)[i * 6 + 1], (*userList)[i * 6 + 2], (*userList)[i * 6 + 3], (*userList)[i * 6 + 4]);
        }
    }
    else if (userList->size() / 6 % countOnPage != 0)
    {
        int awf = userList->size();
        for (int i = 0; i < userList->size() / 6; i++)
        {
            users[i]->ChangeContent((*userList)[i * 6 + 0], (*userList)[i * 6 + 1], (*userList)[i * 6 + 2], (*userList)[i * 6 + 3], (*userList)[i * 6 + 4]);
        }
        for (int i = 0; userList->size() / 6 + i < countOnPage; i++)
        {
            int awf = userList->size() / 6 + i;
            int hseg = users.size();
            users[userList->size() / 6 + i]->hide();
        }
    }

    delete userList;
}

void MyMainQtGUI::ShowMore(bool checked)
{
    currentPage++;

    UploadUsersPage(currentPage, usersCountOnPage);
}