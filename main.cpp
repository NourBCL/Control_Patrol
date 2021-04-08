#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include<QApplication>
#include<QFile>
#include "connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile styleSheetFile("C:/Users/ASUS/Desktop/Code_source_Atelier_Connexion/Atelier_Connexion/Adaptic.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);

    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
