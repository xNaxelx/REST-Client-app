#pragma once

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qframe.h>
#include <QHBoxLayout>
#include <QVBoxLayout>

class BlankUser : public QWidget
{
public:
	BlankUser(QWidget* parent);

private:
	QHBoxLayout *hboxlayout;
	QVBoxLayout *vboxlayout;

	QLabel *avatar;
	QLabel *name;
	QLabel *role;
	QLabel *email;
	QLabel *phoneNumber;

	QFrame *horizontalLine;
};

