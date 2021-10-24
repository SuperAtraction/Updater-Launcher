#ifndef UPDATER_H
#define UPDATER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Updater; }
QT_END_NAMESPACE

class Updater : public QMainWindow
{
    Q_OBJECT

public:
    Updater(QWidget *parent = nullptr);
    ~Updater();

private slots:
    void on_Launch_clicked();

    void on_Cancel_clicked();

    void on_Update_clicked();

private:
    Ui::Updater *ui;
};
#endif // UPDATER_H
