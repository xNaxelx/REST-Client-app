#include "MyMainQtGUI.h"

MyMainQtGUI::MyMainQtGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QRegularExpression rx("[a-zA-Z0-9_.%]+\@[a-zA-Z0-9]+\\.[a-zA-Z0-9]{1,100}", QRegularExpression::CaseInsensitiveOption);
    ui.lineEdit_2->setValidator(new QRegularExpressionValidator(rx, this));

    BlankUser* blank = new BlankUser(nullptr);

    ui.verticalLayout->setAlignment(Qt::AlignTop);

    ui.verticalLayout->addWidget(blank);
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));

    QObject::connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &MyMainQtGUI::CheckIsValidEmail);
    QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, &MyMainQtGUI::BrowseFile);
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

void MyMainQtGUI::CheckIsValidEmail()
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