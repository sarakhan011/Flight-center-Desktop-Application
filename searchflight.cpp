#include "searchflight.h"
#include "ui_searchflight.h"

#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>

searchflight::searchflight(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchflight)
{
    ui->setupUi(this);

    // Table setup
    ui->tableWidget->setColumnCount(5);

    QStringList headers;
    headers << "Flight No"
            << "Airline"
            << "Time"
            << "Price"
            << "Seats";

    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setRowCount(0);
}

searchflight::~searchflight()
{
    delete ui;
}

void searchflight::on_searchpush_clicked()
{
    ui->tableWidget->setRowCount(3);

    ui->tableWidget->setItem(0,0,new QTableWidgetItem("TG101"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("ABC Airline"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("09:00"));
    ui->tableWidget->setItem(0,3,new QTableWidgetItem("$250"));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1,0,new QTableWidgetItem("PL205"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("ABC Airline"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("14:30"));
    ui->tableWidget->setItem(1,3,new QTableWidgetItem("$300"));
    ui->tableWidget->setItem(1,4,new QTableWidgetItem("15"));

    ui->tableWidget->setItem(2,0,new QTableWidgetItem("SD310"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("ABC Airline"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("19:15"));
    ui->tableWidget->setItem(2,3,new QTableWidgetItem("$350"));
    ui->tableWidget->setItem(2,4,new QTableWidgetItem("8"));
}

void searchflight::on_backpush_clicked()
{
    close();
}