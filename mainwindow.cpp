#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasehelper.h"
#include "login.h"
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Login login;
    login.setModal(true);
    login.exec();

    uname=login.getUsername();
    pword=login.getPassword();

    QSqlQueryModel *model=new QSqlQueryModel;
    DatabaseHelper databaseHelper;
    databaseHelper.createConnection(uname, pword);
    ui->setupUi(this);
    model = databaseHelper.getListView();

    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
