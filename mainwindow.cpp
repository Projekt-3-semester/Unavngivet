#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connectBtn_clicked()
{

    setDB("127.0.0.1", "peters.db", "", "eksamen");

    db.open();

    if (db.isOpen())
    {
        QMessageBox::information(this, "connection", "Welcome!!!");
    }
    else
    {
        QMessageBox::information(this, "connection", "Username or Password was incorrect \n Connection was not established \n Please try again");
    }

}


void MainWindow::on_disConnectBtn_clicked()
{

    if (db.isOpen())
    {
        db.close();

        ui->Namelable->setText("Disconnected");
        ui->Namelable->show();

        QMessageBox::information(this, "Disconnection", "Database Disconnected succesfully");
    }
    else
    {
        QMessageBox::information(this, "Disconnection", "Nothing to Disconnect");
    }

}

void MainWindow::on_showBtn_clicked()
{
    qDebug() << "Så er jeg i show";
    if (db.isOpen())
    {
       qDebug() << "DB er åben";
       model->setQuery("SELECT * FROM kunde");
       qDebug() << "Query sendt - Tabel oprettes";
       model->setHeaderData(0, Qt::Horizontal, tr("Navn"));
       model->setHeaderData(1, Qt::Horizontal, tr("Adresse"));
       model->setHeaderData(2, Qt::Horizontal, tr("E-post"));
       model->setHeaderData(3, Qt::Horizontal, tr("Telefon"));

        qDebug() << "View oprettes";

       // ui->tableView->setModel(model);
       // ui->tableView->hideColumn(0);

       ui->tableView->setModel(model);
       ui->tableView->resizeColumnsToContents();
       ui->tableView->resizeRowsToContents();
       ui->tableView->hideColumn(0);
       ui->tableView->show();
    }
    else
    {
        QMessageBox::information(this, "Show Something", "There is nothing to SHOW!!!!!!!");
    }
}

void MainWindow::on_insertBtn_clicked()
{  
    if (db.isOpen())
    {
        model->setQuery("INSERT INTO kunde(kunde_id, navn, adresse, mail, tlf) VALUES(5, 'Henrik Ejer Mortensen', 'Himmelvej 85, 25666 Drømmekøbing', 'hem@robotsjov.dk', 64745219)");
    }
    else
    {
        QMessageBox::information(this, "insert", "That is not possible!!");
    }
}

void MainWindow::setDB(QString host, QString user, QString password, QString dbName)
{
    db.setHostName(host);
    db.setUserName(user);
    db.setPassword(password);
    db.setDatabaseName(dbName);

}

