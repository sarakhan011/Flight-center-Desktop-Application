#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class dashboard;
}
QT_END_NAMESPACE

class dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private slots:
    void on_okButton_clicked();

private:
    Ui::dashboard *ui;
};

#endif