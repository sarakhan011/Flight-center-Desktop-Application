#ifndef BOOKING_H
#define BOOKING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class booking;
}
QT_END_NAMESPACE

class booking : public QWidget
{
    Q_OBJECT

public:
    explicit booking(QWidget *parent = nullptr);
    ~booking();

private slots:
    void on_confirmButton_clicked();
    void on_backButton_clicked();

private:
    Ui::booking *ui;
};

#endif // BOOKING_H