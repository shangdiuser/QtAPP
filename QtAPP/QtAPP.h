#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAPP.h"

class QtAPP : public QMainWindow
{
    Q_OBJECT

public:
    QtAPP(QWidget *parent = Q_NULLPTR);

    //第一步：头文件中添加槽的声明
private slots:
    int ShowTextXdd(bool checked);//自定义一个槽，说白了就是一个消息（事件）的响应函数。这个名字所随意，但是参数不能改
    int PackJson(bool checked);
    int ParsingJSON(bool checked);
    void sendPostRequest(const QUrl& url, const QJsonObject& jsonObject);


private:
    Ui::QtAPPClass ui;
    
};
