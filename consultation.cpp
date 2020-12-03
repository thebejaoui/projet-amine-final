#include "consultation.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include "ui_mainwindow.h"
#include<QComboBox>

consultation::consultation()
{
     num=0;
     num_interv=0;
     date_inter="";
     probl="";
     tension=0;
     glycemie=0;
     poids=0;
     taille=0;
     ordonnance="";
}

consultation::consultation(int num,int num_interv,QString date_inter,QString probl,int tension,int glycemie,int poids,int taille,QString ordonnance)
{
    this->num=num;
    this->num_interv=num_interv;
    this->date_inter=date_inter;
    this->probl=probl;
    this->tension=tension;
    this->glycemie=glycemie;
    this->poids=poids;
    this->taille=taille;
    this->ordonnance=ordonnance;

}
  bool consultation::ajouter()
  {



      QSqlQuery query;
            query.prepare("INSERT INTO consultation (num_dossier, num_interv, date_inter,probl,tension,glycemie,poids,taille,ordonnance) "
                          "VALUES (:num_dossier, :num_interv, :date_inter,:probl,:tension,:glycemie,:poids,:taille,:ordonnance)");

            query.bindValue(":num_dossier", num);
            query.bindValue(":num_interv", num_interv);
            query.bindValue(":date_inter", date_inter);
            query.bindValue(":probl", probl);
            query.bindValue(":tension", tension);
            query.bindValue(":glycemie", glycemie);
            query.bindValue(":poids", poids);
            query.bindValue(":taille", taille);
            query.bindValue(":ordonnance", ordonnance);
             return query.exec();

  }

  QSqlQueryModel*  consultation::afficher()
  {


      QSqlQueryModel *model = new QSqlQueryModel;
            model->setQuery("SELECT * FROM consultation");
      return model;

  }
  bool consultation ::supprimer(int numm)
  {

             QString num_string=QString::number(numm);

             QSqlQuery query;
                   query.prepare("delete from consultation where NUM_INTERV= :num");
                   query.bindValue(":num", num_string);

                    return query.exec();

  }

   QSqlQueryModel * consultation::  rechercher(int num_interv )
   {
       QString num_string=QString::number(num_interv);
       QSqlQueryModel * model= new QSqlQueryModel();
       model-> setQuery("SELECT * FROM consultation  where NUM_INTERV = "+num_string);


       return model;

   }

    QSqlQueryModel * consultation::  tridesc()
    {

        QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from consultation  order by NUM_INTERV  ");

        return model;

    }
     bool  consultation::modifier(int num,int num_interv,QString date_inter,QString probl,int tension,int glycemie,int poids,int taille,QString ordonnance)
     {
         QSqlQuery query;
         QString num_string= QString::number(num);
          QString interv_string= QString::number(num_interv);
           QString tension_string= QString::number(tension);
            QString glycemie_string= QString::number(glycemie);
            QString poids_string= QString::number(poids);
            QString taille_string= QString::number(taille);


         query.prepare("UPDATE consultation SET   DATE_INTER= :date_inter ,PROBL= :probl,TENSION= :tension,GLYCEMIE= :glycemie,POIDS= :poids,TAILLE= :taille,ordonnance= :ordonnance,NUM_DOSSIER= :num  WHERE NUM_INTERV = :numinterv ");
         query.bindValue(":num_interv", interv_string);
         query.bindValue(":date_inter", date_inter);
         query.bindValue(":probl", probl);
         query.bindValue(":tension", tension_string);

         query.bindValue(":glycemie", glycemie_string);

         query.bindValue(":poids", poids_string);
         query.bindValue(":taille", taille_string);
         query.bindValue(":ordonnance", ordonnance);
         query.bindValue(":num", num_string);


         return  query.exec();

     }
      QString consultation:: apercu_pdf()
      {
          QString text="             ** Les consultation  **       \n \n " ;
          QSqlQuery query ;
          QString i,x,z,m,n,b,a,c,d;


           query.exec("select * from consultation  ");
           while (query.next())
           {
              i=query.value(0).toString();
               x=query.value(1).toString();
               z=query.value(2).toString();
             m=query.value(3).toString();
             n=query.value(4).toString();
             b=query.value(5).toString();
             a=query.value(6).toString();
             c=query.value(7).toString();
             d=query.value(8).toString();

     text += "\n num_interv: "+z+"\n\n - date_inter : "+ x+"\n  - - problemme : "+ i+"\n--  tension:"+m+"\n__ glycemie :"+n+"\n--- poids : "+b+"\n____taille:"+a+"___ordonnance="+c+"______________\n";

          }
                  return text ;




      }
