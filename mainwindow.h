#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtCore>
#include <QLabel>
#include <iostream>
#include <qdebug.h>
#include <QVector>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlQuery>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_connectBtn_clicked();

    void on_disConnectBtn_clicked();

    void on_showBtn_clicked();

    void on_insertBtn_clicked();
private:


    // Functions regarding SQL Database:
    void setDB(QString host, QString user, QString password, QString dbName);


    Ui::MainWindow *ui;


    QTableView *view = new QTableView;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQueryModel *model = new QSqlQueryModel;
   };

#endif // MAINWINDOW_H
