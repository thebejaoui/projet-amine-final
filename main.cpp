#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QMediaPlayer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

QMediaPlayer * player=new QMediaPlayer();
player->setMedia(QUrl("qrc:/2017-04-14_-_Happy_Dreams_-_David_Fesliyan.mp3"));
player->setVolume(50);
player->play();
w.show();
    return a.exec();
}
