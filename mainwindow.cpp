#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "dashboard.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginbutton_clicked()
{
    std::string username =
        ui->useredit->text().toStdString();

    std::string password =
        ui->passwordedit->text().toStdString();

    if (authenticateUser(username, password))
    {
        QMessageBox::information(this,
                                 "Login",
                                 "Login Successful!");

        dashboard *d = new dashboard();
        d->show();

        this->hide();
    }
    else
    {
        QMessageBox::warning(this,
                             "Login",
                             "Invalid Username or Password!");
    }
}

void MainWindow::on_registerbutton_clicked()
{
    UserInfo user;

    user.username =
        ui->useredit->text().toStdString();

    user.password =
        ui->passwordedit->text().toStdString();

    registerUser(user);

    QMessageBox::information(this,
                             "Register",
                             "Registration Successful!");
}