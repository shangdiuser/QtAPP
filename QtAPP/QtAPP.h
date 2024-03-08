#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtAPP.h"

class QtAPP : public QMainWindow
{
    Q_OBJECT

public:
    QtAPP(QWidget *parent = Q_NULLPTR);

    //��һ����ͷ�ļ�����Ӳ۵�����
private slots:
    int ShowTextXdd(bool checked);//�Զ���һ���ۣ�˵���˾���һ����Ϣ���¼�������Ӧ������������������⣬���ǲ������ܸ�
    int PackJson(bool checked);
    int ParsingJSON(bool checked);
    void sendPostRequest(const QUrl& url, const QJsonObject& jsonObject);


private:
    Ui::QtAPPClass ui;
    
};
