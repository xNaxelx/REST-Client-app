#include "BlankUser.h"

BlankUser::BlankUser(QWidget* parent) : QWidget(parent)
{
	

	QSizePolicy sizePolicyThis(QSizePolicy::Preferred, QSizePolicy::Maximum);
	//sizePolicyThis.setHorizontalStretch(255);
	this->setSizePolicy(sizePolicyThis);

	this->setGeometry(QRect(0, 0, 500, 200));
	

	hboxlayout = new QHBoxLayout(this);

	QSizePolicy sizePolicyAvatar(QSizePolicy::Minimum, QSizePolicy::Minimum);
	sizePolicyAvatar.setHorizontalStretch(0);
	sizePolicyAvatar.setVerticalStretch(0);

	avatar = new QLabel();
	avatar->setPixmap(QPixmap(":/Image/Grey.png").scaled(80, 80));
	avatar->setSizePolicy(sizePolicyAvatar);


	vboxlayout = new QVBoxLayout();

	hboxlayout->addWidget(avatar);
	hboxlayout->addLayout(vboxlayout);

	name = new QLabel();
	role = new QLabel();
	email = new QLabel();
	phoneNumber = new QLabel();

	QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy.setHorizontalStretch(255);
	sizePolicy.setVerticalStretch(0);

	name->setSizePolicy(sizePolicy);
	role->setSizePolicy(sizePolicy);
	email->setSizePolicy(sizePolicy);
	phoneNumber->setSizePolicy(sizePolicy);

	horizontalLine = new QLabel(this);

	vboxlayout->addWidget(name);
	vboxlayout->addWidget(role);
	vboxlayout->addWidget(email);
	vboxlayout->addWidget(phoneNumber);

	name->setText("Name");
	QFont font;
	font.setPointSize(16);
	name->setFont(font);
	role->setText("role");
	email->setText("email");
	phoneNumber->setText("phonenumber");

	horizontalLine->setObjectName("line");
	horizontalLine->setGeometry(QRect(0, 102, 5000, 2));
	horizontalLine->setFrameShape(QFrame::HLine);
	horizontalLine->setFrameShadow(QFrame::Sunken);

	//this->(horizontalLine);
}