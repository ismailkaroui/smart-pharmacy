#include "patient.h"
#include <QString>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>


Patient::Patient()
{
    nom = "";
    prenom = "";
    age = 0;
    sexe = "";
    cnss = "";
    tel = 0;
}

Patient::Patient(QString nom, QString prenom, int age, QString sexe, QString cnss, int tel)
{
    this->nom = nom;
    this->prenom = prenom;
    this->age = age;
    this->sexe = sexe;
    this->cnss = cnss;
    this->tel = tel;
}

int Patient::getId() { return id_p; }
void Patient::setNom(QString val) { nom = val; }
QString Patient::getNom() { return nom; }
void Patient::setPrenom(QString val) { prenom = val; }
QString Patient::getPrenom() { return prenom; }
void Patient::setAge(int val) { age = val; }
int Patient::getAge() { return age; }
void Patient::setSexe(QString val) { sexe = val; }
QString Patient::getSexe() { return sexe; }
void Patient::setCnss(QString val) { cnss = val; }
QString Patient::getCnss() { return cnss; }
void Patient::setTel(int val) { tel = val; }
int Patient::getTel() { return tel; }

bool Patient::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Patients (NOM, PRENOM, AGE, SEXE, CNSS, TEL) "
                  "VALUES (:nom, :prenom, :age, :sexe, :cnss, :tel)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":sexe", sexe);
    query.bindValue(":cnss", cnss);
    query.bindValue(":tel", tel);
    return query.exec();
}

QSqlQueryModel* Patient::display()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Patients");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CNSS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Téléphone"));
    return model;
}

bool Patient::remove(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Patients WHERE ID_P = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Patient::update(int id, QString nom, QString prenom, int age, QString sexe, QString cnss, int tel)
{
    QSqlQuery query;
    query.prepare("UPDATE Patients SET NOM = ?, PRENOM = ?, AGE = ?, SEXE = ?, CNSS = ?, TEL = ? WHERE ID_P = ?");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(age);
    query.addBindValue(sexe);
    query.addBindValue(cnss);
    query.addBindValue(tel);
    query.addBindValue(id);
    return query.exec();
}
