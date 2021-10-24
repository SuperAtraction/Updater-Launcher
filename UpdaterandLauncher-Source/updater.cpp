#include "updater.h"
#include <QDesktopServices>
#include "ui_updater.h"
#include <QFile>
#include <QMessageBox>

int update() {

    return 0;
}

Updater::Updater(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Updater)
{
    ui->setupUi(this);
    ui->name->setText(QCoreApplication::arguments().at(1));
    ui->Pregress_Download->setValue(0);
}

Updater::~Updater()
{
    delete ui;
}

void Updater::on_Launch_clicked()
{
    system(QCoreApplication::arguments().at(2).toStdString().c_str());
}

void Updater::on_Cancel_clicked()
{
    exit(0);
}

void Updater::on_Update_clicked()
{
    QFile zip(QCoreApplication::arguments().at(3));
    ui->Statut->setText("Statut : Check zip on "+QCoreApplication::arguments().at(3));
    if (zip.open(QIODevice::ReadOnly | QIODevice::Text));
    QString zipstr;
        QTextStream in(&zip);
        while (!in.atEnd()) {
            zipstr = in.readLine();
            ui->Statut->setText("Statut : Downloading "+zipstr);
            // Création d'un objet QFile
            QFile file("Download.txt");
            // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                exit(1);
            }

            // Création d'un objet QTextStream à partir de notre objet QFile
            QTextStream flux(&file);
            flux << zipstr;
            file.close();
            system("Download.vbs");
    }
        ui->Statut->setText("...");
        ui->Pregress_Download->setValue(0);
}

