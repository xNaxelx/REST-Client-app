#include "MyMainQtGUI.h"

MyMainQtGUI::MyMainQtGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QPushButton *wwwidget = new QPushButton();
    BlankUser* blank = new BlankUser(nullptr);

    ui.verticalLayout->setAlignment(Qt::AlignTop);

    ui.verticalLayout->addWidget(blank);
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));
    ui.verticalLayout->addWidget(new BlankUser(nullptr));

    QObject::connect(ui.pushButton_2, &QPushButton::clicked, this, qOverload<>(&MyMainQtGUI::BrowseFile));
}

MyMainQtGUI::~MyMainQtGUI()
{}

void MyMainQtGUI::BrowseFile()
{
    QString directory = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.jpg *.jpeg)"));
    ui.lineEdit_4->setText(directory);
}