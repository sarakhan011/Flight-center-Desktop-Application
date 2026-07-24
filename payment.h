#ifndef PAYMENT_H
#define PAYMENT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class payment;
}
QT_END_NAMESPACE

class payment : public QWidget
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = nullptr);
    ~payment();

private slots:
    void on_payButton_clicked();
    void on_backButton_clicked();

private:
    Ui::payment *ui;
};

#endif // PAYMENT_H