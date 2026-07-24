#include "payment.h"
#include "ui_payment.h"

#include <QMessageBox>

payment::payment(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::payment)
{
    ui->setupUi(this);
}

payment::~payment()
{
    delete ui;
}

void payment::on_payButton_clicked()
{
    QString cardName = ui->nameEdit->text();
    QString cardNumber = ui->cardEdit->text();
    QString expiry = ui->expiryEdit->text();
    QString cvv = ui->cvvEdit->text();

    if(cardName.isEmpty() ||
        cardNumber.isEmpty() ||
        expiry.isEmpty() ||
        cvv.isEmpty())
    {
        QMessageBox::warning(this,
                             "Payment",
                             "Please fill in all payment details.");
        return;
    }

    QMessageBox::information(this,
                             "Payment",
                             "Payment Successful!");
}

void payment::on_backButton_clicked()
{
    close();
}