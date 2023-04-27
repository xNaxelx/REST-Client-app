#pragma once

#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qframe.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtNetwork/qnetworkaccessmanager.h>
#include <QtNetwork/qnetworkreply.h>
#include <memory>

class BlankUser : public QWidget
{
public:
	BlankUser(QWidget* parent);
	BlankUser(QString avatar, QString name, QString role, QString email, QString phoneNumber, QWidget* parent = nullptr);

	void ChangeContent(QString avatar, QString name, QString role, QString email, QString phoneNumber);

private:
	void ConvertByteToImage(QNetworkReply* reply);

	QHBoxLayout *hboxlayout;
	QVBoxLayout *vboxlayout;

	QLabel *avatar;
	QLabel *name;
	QLabel *role;
	QLabel *email;
	QLabel *phoneNumber;

	QFrame *horizontalLine;

	std::unique_ptr<QNetworkAccessManager> networkAM;
};

