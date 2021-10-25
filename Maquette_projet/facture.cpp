#include "facture.h"
#include<QSqlQuery>
#include<QDebug>

Facture::Facture()
{
id_facture=0;
id_client=0;
nom="";
prenom="";
cin=0;
date="";
des="";
prix_uni=0;
quantite=0;
montant=0;
mail="";
type=0;
}
Facture::Facture(int id_facture,int id_client,QString nom,QString prenom,int cin,QString date,QString des,float prix_uni,int quantite,float montant,QString mail,int type)
{
    this->id_facture=id_facture;
    this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->date=date;
    this->des=des;
    this->prix_uni=prix_uni;
    this->quantite=quantite;
    this->montant=montant;
    this->mail=mail;
    this->type=type;

}
int Facture::getid_facture(){return id_facture;}
int Facture::getid_client(){return id_client;}
QString Facture::getnom(){return nom;}
QString Facture::getprenom(){return prenom;}
int Facture::getcin(){return cin;}
QString Facture::getdate(){return date;}
QString Facture::getdes(){return des;}
float Facture::getprix_uni(){return prix_uni;}
int Facture::getquantite(){return quantite;}
float Facture::getmontant(){return montant;}
QString Facture::getmail(){return mail;}
void Facture::setid_facture(int id_facture){this->id_facture=id_facture;}
void Facture::setid_client(int id_client){this->id_client=id_client;}
void Facture::setnom(QString nom){this->nom=nom;}
void Facture::setprenom(QString prenom){this->prenom=prenom;}
void Facture::setcin(int cin){this->cin=cin;}
void Facture::setdate(QString date){this->date=date;}
void Facture::setdes(QString des){this->des=des;}
void Facture::setprix_uni(float prix_uni){this->prix_uni=prix_uni;}
void Facture::setquantite(int quantite){this->quantite=quantite;}
void Facture::setmontant(float montant){this->montant=montant;}
void Facture::setmail(QString mail){this->mail=mail;}
void Facture::settype(int type){this->type=type;}
bool Facture::ajouter(){

    bool test=false;
    QSqlQuery query;
    QString id_facture_string=QString::number(id_facture);
    QString id_client_string=QString::number(id_client);
    query.prepare("INSERT INTO Facture (id_facture,id_client,nom,prenom) "
                        "VALUES (:id, :forename, :surname)");
          query.bindValue(":id_facture", id_facture_string);
          query.bindValue(":id_client", id_client_string)
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.exec();




    return test;
}

