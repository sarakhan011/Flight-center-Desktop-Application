#include "dashboard.h"
#include "ui_dashboard.h"
#include "searchflight.h"
#include <QMessageBox>

dashboard::dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dashboard)
{
    ui->setupUi(this);
}

dashboard::~dashboard()
{
    delete ui;
}

void dashboard::on_okButton_clicked()
{
    if (!ui->listWidget->currentItem())
    {
        QMessageBox::warning(this,
                             "Selection",
                             "Please select an option.");
        return;
    }

    QString choice = ui->listWidget->currentItem()->text();

    if (choice == "Search Flights")
    {
        searchflight *search = new searchflight();
        search->show();
        this->hide();
    }
    else if (choice == "Book Flight")
    {
        QMessageBox::information(this,
                                 "Book Flight",
                                 "Booking page will open.");
    }
    else if (choice == "View Booking")
    {
        QMessageBox::information(this,
                                 "View Booking",
                                 "View Booking page will open.");
    }
    else if (choice == "Cancel Booking")
    {
        QMessageBox::information(this,
                                 "Cancel Booking",
                                 "Cancel Booking page will open.");
    }
    else if (choice == "Logout")
    {
        close();
    }
}