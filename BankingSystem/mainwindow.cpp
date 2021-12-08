#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, User *user)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox::warning(this, user->GetUsername(), "The title is your username");
}

MainWindow::~MainWindow()
{
    delete ui;
}

