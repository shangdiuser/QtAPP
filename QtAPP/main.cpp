#include "QtAPP.h"
#include <QtWidgets/QApplication>
#include <QtCore>
/*
#include <QHttpServer>
#include <QHttpServerRequest>
#include <QHttpServerResponse>
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtAPP w;
    w.show();
    /*
    // 创建HTTP服务器
    QHttpServer httpServer;
    httpServer.listen(QHostAddress::Any, 8080); // 监听所有地址的8080端口

    // 处理HTTP请求
    QObject::connect(&httpServer, &QHttpServer::newRequest, [&](QHttpServerRequest const& request, QHttpServerResponse& response) {
        qDebug() << "Received HTTP request:" << request.url().toString();

        // 根据请求的路径决定返回的数据
        QString path = request.url().path();
        if (path == "/") {
            // 根路径返回一个简单的HTML页面
            response.setHeader("Content-Type", "text/html");
            QByteArray responseData = "<html><body><h1>Welcome to my server!</h1></body></html>";
            response.write(responseData);
            response.end();
        }
        else if (path == "/hello") {
            // "/hello"路径返回一个简单的字符串
            response.setHeader("Content-Type", "text/plain");
            QByteArray responseData = "Hello, World!";
            response.write(responseData);
            response.end();
        }
        else {
            // 未知路径返回404错误
            response.setStatusCode(404);
            response.end();
        }
    });

    if (httpServer.isListening()) {
        qDebug() << "Server started on port 8080";
    }
    else {
        qDebug() << "Failed to start server!";
        return 1;
    }
    */

    return a.exec();
}
