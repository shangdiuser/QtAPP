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
    // ����HTTP������
    QHttpServer httpServer;
    httpServer.listen(QHostAddress::Any, 8080); // �������е�ַ��8080�˿�

    // ����HTTP����
    QObject::connect(&httpServer, &QHttpServer::newRequest, [&](QHttpServerRequest const& request, QHttpServerResponse& response) {
        qDebug() << "Received HTTP request:" << request.url().toString();

        // ���������·���������ص�����
        QString path = request.url().path();
        if (path == "/") {
            // ��·������һ���򵥵�HTMLҳ��
            response.setHeader("Content-Type", "text/html");
            QByteArray responseData = "<html><body><h1>Welcome to my server!</h1></body></html>";
            response.write(responseData);
            response.end();
        }
        else if (path == "/hello") {
            // "/hello"·������һ���򵥵��ַ���
            response.setHeader("Content-Type", "text/plain");
            QByteArray responseData = "Hello, World!";
            response.write(responseData);
            response.end();
        }
        else {
            // δ֪·������404����
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
