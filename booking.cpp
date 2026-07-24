#include "booking.h"
#include "ui_booking.h"

#include <QMessageBox>

booking::booking(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::booking)
{
    ui->setupUi(this);
}

booking::~booking()
{
    delete ui;
}

void booking::on_confirmButton_clicked()
{
    QMessageBox::information(this,
                             "Booking",
                             "Your flight has been booked successfully!");
}

void booking::on_backButton_clicked()
{
    close();
}