#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include <QMessageBox>
#include <QDebug>
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegularExpression>
#include "connection.h"
#include <QFileDialog>
#include <QRegularExpressionValidator>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->tableView->setModel(tmppatient.display());
    // cs //
    ui->age->setValidator(new QIntValidator(0,999999,this));
    ui->tel->setValidator(new QIntValidator(0,999999,this));

    QRegularExpression rx("[a-zA-Z]+");  // Adjust regex as needed
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->name->setValidator(validator);
    ui->prenom->setValidator(validator);

}

MainWindow::~MainWindow() {
    delete ui;
}

//ajouter
void MainWindow::on_pushButton_clicked()
{
    QString nom =ui->name->text();
    QString prenom =ui->prenom->text();
    QString sexe =ui->comboBox->currentText();
    QString cnss =ui->cnss->text();
    int age =ui->age->text().toInt();
    int num =ui->tel->text().toInt();
    Patient tmppatient(nom,prenom,age,sexe,cnss,num);
    bool test=tmppatient.add();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("ajoute \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->name->clear();
        ui->prenom->clear();
        ui->cnss->clear();
        ui->age->clear();
        ui->tel->clear();
        ui->tableView->setModel(tmppatient.display());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);
}

//modifier
void MainWindow::on_pushButton_7_clicked()
{
    int id =ui->ID->text().toUInt();
    QString nom =ui->name->text();
    QString prenom =ui->prenom->text();
    QString sexe =ui->comboBox->currentText();
    QString cnss =ui->cnss->text();
    int age =ui->age->text().toInt();
    int num =ui->tel->text().toInt();
    bool test=tmppatient.update(id ,nom,prenom,age,sexe,cnss,num);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->name->clear();
        ui->prenom->clear();
        ui->cnss->clear();
        ui->age->clear();
        ui->tel->clear();
        ui->tableView->setModel(tmppatient.display());
    }
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("modification non effectué"),QMessageBox::Cancel);
}
//supprimer
void MainWindow::on_pushButton_10_clicked()
{
    int id =ui->ID->text().toUInt();
    bool test=tmppatient.remove(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
        ui->ID->clear();
        ui->tableView->setModel(tmppatient.display());
    }
    else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("suppression non effectué"),QMessageBox::Cancel);
}
// remplissage auto
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from Patients  where ID_P='"+val+"' or nom='"+val+"' or prenom='"+val+"' or tel='"+val+"' or cnss='"+val+"'");
    if (qry.exec())
    { while (qry.next())
        {
            //update
            //id
            ui->ID->setText(qry.value(0).toString());
            ui->name->setText(qry.value(1).toString());
            ui->prenom->setText(qry.value(2).toString());
            ui->age->setText(qry.value(3).toString());
            ui->cnss->setText(qry.value(5).toString());
            ui->tel->setText(qry.value(6).toString());
            //delete
            //id
            ui->ID->setText(qry.value(0).toString());
        }
    }
}

// actualiser
void MainWindow::on_pushButton_12_clicked()
{
    ui->tableView->setModel(tmppatient.display());
}
