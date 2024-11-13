#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QDebug>

class Patient
{
public:
    Patient();
    Patient(QString nom, QString prenom, int age, QString sexe, QString cnss, int tel);

    int getId();
    void setNom(QString val);
    QString getNom();
    void setPrenom(QString val);
    QString getPrenom();
    void setAge(int val);
    int getAge();
    void setSexe(QString val);
    QString getSexe();
    void setCnss(QString val);
    QString getCnss();
    void setTel(int val);
    int getTel();

    // CRUD Operations
    bool add();
    bool update(int id, QString nom, QString prenom, int age, QString sexe, QString cnss, int tel);
    bool remove(int id);
    QSqlQueryModel* display();

private:
    int id_p;
    QString nom;
    QString prenom;
    int age;
    QString sexe;
    QString cnss;
    int tel;
};

#endif // PATIENT_H
