#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetCPP"); //ProjetCPP   patient ProjetCPP
db.setUserName("PROJETCPP");//inserer nom de l'utilisateur PROJETCPP projetCPP2A39 PROJETCPP
db.setPassword("esprit24");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
void Connection::closeConnection()
{
    db.close();
}
