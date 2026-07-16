#ifndef SEARCHFLIGHT_H
#define SEARCHFLIGHT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class searchflight;
}
QT_END_NAMESPACE

class searchflight : public QWidget
{
    Q_OBJECT

public:
    explicit searchflight(QWidget *parent = nullptr);
    ~searchflight();

private slots:
    void on_searchpush_clicked();
    void on_backpush_clicked();

private:
    Ui::searchflight *ui;
};

#endif // SEARCHFLIGHT_H