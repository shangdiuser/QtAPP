#include "QtAPP.h"
#include <QMessageBox>
#include <QVariantList>			// �����������Դ洢�κ����͵�����
#include <QDebug>
#include <QSqlQuery>

#include <QSql>
#include <QSqlError>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QJsonParseError>



QtAPP::QtAPP(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect
    (
        ui.pushButton,//����1
        SIGNAL(clicked(bool)),//����1�źţ��̶��ĺ����Ͳ���
        this,//����2
        SLOT(ShowTextXdd(bool))//����2�Ĳۺ������Զ���ĺ���
    );
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(PackJson(bool)));
    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(ParsingJSON(bool)));



}



// �ڶ���������ۺ���.�����������������ͷ�ļ���������
int QtAPP::ShowTextXdd(bool checked)
{
    ui.textEdit->setText("Hello world");

    QGraphicsScene* scene = new QGraphicsScene;

    ui.graphicsView->setScene(scene);

    QString picPath = ":/img/11.png";
    QPixmap scalePixmap = QPixmap(picPath);

    // �������ű���
    double scale = 1.0;
    double scaleX = static_cast<double>(ui.graphicsView->width()) / (scalePixmap.width() + 1);// ��+1���й�����
    double scaleY = static_cast<double>(ui.graphicsView->height()) / (scalePixmap.height() + 1);// ��+1���й�����
    if (scaleX > scaleY)
    {
        scale = scaleY;
    }
    else
    {
        scale = scaleX;
    }

    // ����
    scalePixmap = scalePixmap.scaled(scalePixmap.width() * scale, scalePixmap.height() * scale, Qt::KeepAspectRatio);
    scene->addPixmap(scalePixmap);


    /*
    //������ʾ����
    QGraphicsScene* scene = new QGraphicsScene;
    //������������ļ�·��ΪfileName��QString���ͣ����ļ�
    scene->addPixmap(QPixmap(":/img/11.png"));
    //����graphicsView��QGraphicsView�ࣩ�ؼ���ʾ����������
    ui.graphicsView->setScene(scene);
    //��ʼ��ʾ
    ui.graphicsView->show();*/


    //addDatabase() ����һ�����ӣ������������ʱ�����ǿ��Դ�������Ҫ�����������͵����ݿ�
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");     //���� 

    db.setHostName("localhost");          // ���ݿ��ַ��һ�㶼�Ǳ��أ���localhost�Ϳ���(������д127.0.0.1) 
    db.setDatabaseName("sm");         // ���ݿ�����������Mysql��������ݿ���������д�������ҵ�Mysql�����и����ݿ��school
    db.setUserName("root");               // ��¼�û�����һ���Ǳ����û�����root�Ϳ���
    db.setPassword("123456");				  // ��¼���룬��д���Լ�Mysql��½����
    db.setPort(3306);                     // �˿ڣ�Ĭ����3306

    db.open();
    QSqlQuery result = db.exec("select * from department");

    for (int i = 0; i < 1; i++) {
        result.next();
        qDebug() << result.value("id").toString() << '\t' << result.value("name").toString() << '\t'
            << result.value("address").toString() << endl;
    }

    result.clear();
 
 

    return 0;

}

int QtAPP::PackJson(bool checked)
{
    qDebug() << "PackJson" << endl;
    // ����URL
    QUrl url("http://yourserver.com/api");

    // ����JSON����
    QJsonObject jsonObject;
    jsonObject["key1"] = "value1";
    jsonObject["key2"] = "value2";


    // ����POST����
    sendPostRequest(url, jsonObject);
    qDebug() << url << jsonObject<<endl;
    return 0;
}

int QtAPP::ParsingJSON(bool checked)
{
    qDebug() << "ParsingJSON" << endl;
    return 0;
}

void  QtAPP::sendPostRequest(const QUrl& url, const QJsonObject& jsonObject) {
    QNetworkAccessManager manager;
    QNetworkRequest request(url);

    // ��������ͷΪJSON��ʽ
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // ��JSON����ת��ΪJSON�ַ���
    QJsonDocument jsonDoc(jsonObject);
    QByteArray jsonBytes = jsonDoc.toJson();

    // ����POST����
    QNetworkReply* reply = manager.post(request, jsonBytes);

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // ����ɹ���������Ӧ����
            QByteArray responseData = reply->readAll();
            QJsonParseError parseError;
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                // JSON�����ɹ�������ʹ��responseDoc���н�һ������
            }
            else {
                // JSON����ʧ��
            }
        }
        else {
            // ����ʧ�ܣ��������
        }

        // ����
        reply->deleteLater();
    });
}


