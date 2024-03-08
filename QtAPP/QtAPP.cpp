#include "QtAPP.h"
#include <QMessageBox>
#include <QVariantList>			// 泛型链表，可以存储任何类型的数据
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
        ui.pushButton,//对象1
        SIGNAL(clicked(bool)),//对象1信号，固定的函数和参数
        this,//对象2
        SLOT(ShowTextXdd(bool))//对象2的槽函数，自定义的函数
    );
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(PackJson(bool)));
    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(ParsingJSON(bool)));



}



// 第二步：定义槽函数.这个函数的声明是在头文件里面做的
int QtAPP::ShowTextXdd(bool checked)
{
    ui.textEdit->setText("Hello world");

    QGraphicsScene* scene = new QGraphicsScene;

    ui.graphicsView->setScene(scene);

    QString picPath = ":/img/11.png";
    QPixmap scalePixmap = QPixmap(picPath);

    // 计算缩放比例
    double scale = 1.0;
    double scaleX = static_cast<double>(ui.graphicsView->width()) / (scalePixmap.width() + 1);// 不+1会有滚动条
    double scaleY = static_cast<double>(ui.graphicsView->height()) / (scalePixmap.height() + 1);// 不+1会有滚动条
    if (scaleX > scaleY)
    {
        scale = scaleY;
    }
    else
    {
        scale = scaleX;
    }

    // 缩放
    scalePixmap = scalePixmap.scaled(scalePixmap.width() * scale, scalePixmap.height() * scale, Qt::KeepAspectRatio);
    scene->addPixmap(scalePixmap);


    /*
    //创建显示容器
    QGraphicsScene* scene = new QGraphicsScene;
    //向容器中添加文件路径为fileName（QString类型）的文件
    scene->addPixmap(QPixmap(":/img/11.png"));
    //借助graphicsView（QGraphicsView类）控件显示容器的内容
    ui.graphicsView->setScene(scene);
    //开始显示
    ui.graphicsView->show();*/


    //addDatabase() 创建一个连接，调用这个函数时，我们可以传递我们要访问哪种类型的数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");     //驱动 

    db.setHostName("localhost");          // 数据库地址，一般都是本地，填localhost就可以(或者填写127.0.0.1) 
    db.setDatabaseName("sm");         // 数据库名，根据你Mysql里面的数据库名称来填写，比如我的Mysql里面有个数据库叫school
    db.setUserName("root");               // 登录用户名，一般是本地用户，填root就可以
    db.setPassword("123456");				  // 登录密码，填写你自己Mysql登陆密码
    db.setPort(3306);                     // 端口，默认是3306

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
    // 创建URL
    QUrl url("http://yourserver.com/api");

    // 创建JSON对象
    QJsonObject jsonObject;
    jsonObject["key1"] = "value1";
    jsonObject["key2"] = "value2";


    // 发送POST请求
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

    // 设置请求头为JSON格式
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // 将JSON对象转换为JSON字符串
    QJsonDocument jsonDoc(jsonObject);
    QByteArray jsonBytes = jsonDoc.toJson();

    // 发送POST请求
    QNetworkReply* reply = manager.post(request, jsonBytes);

    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // 请求成功，处理响应数据
            QByteArray responseData = reply->readAll();
            QJsonParseError parseError;
            QJsonDocument responseDoc = QJsonDocument::fromJson(responseData, &parseError);
            if (parseError.error == QJsonParseError::NoError) {
                // JSON解析成功，可以使用responseDoc进行进一步处理
            }
            else {
                // JSON解析失败
            }
        }
        else {
            // 请求失败，处理错误
        }

        // 清理
        reply->deleteLater();
    });
}


