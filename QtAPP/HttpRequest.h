#pragma once

#include <QObject>

class HttpRequest  : public QObject
{
	Q_OBJECT

public:
	HttpRequest(QObject *parent);
	~HttpRequest();
};
