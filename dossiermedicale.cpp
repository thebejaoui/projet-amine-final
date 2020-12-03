#include "dossiermedicale.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QSqlQueryModel>
#include<QLineEdit>
#include<QString>
#include "ui_mainwindow.h"
#include<QComboBox>
dossiermedicale::dossiermedicale()
{
num=0;
id_p="";
}

dossiermedicale::dossiermedicale(int num,QString datec ,QString id_p)
{
   this->num=num;
    this->datec=datec;
    this->id_p=id_p;

}
int dossiermedicale:: getnum()
{
    return num;
}
QString dossiermedicale:: getdatec()
{
    return datec;
}
QString dossiermedicale::getid_p()
{
    return id_p;
}
void dossiermedicale:: setnum(int num )
{
    this->num=num;
}
void dossiermedicale::setdatec(QString datec )
{
   this->datec=datec;
}
void dossiermedicale::setid_p(QString id_p)
{
    this->id_p=id_p;
}
bool dossiermedicale::ajouter()
{

    QString num_string=QString::number(num);

    QSqlQuery query;
          query.prepare("INSERT INTO docmedicale (num_dossier, date_creation, id_patient) "
                        "VALUES (:id, :forename, :surname)");

          query.bindValue(":id", num_string);
          query.bindValue(":forename", datec);
          query.bindValue(":surname", id_p);
           return query.exec();


}

QSqlQueryModel * dossiermedicale:: afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
          model->setQuery("SELECT * FROM docmedicale left join patient on docmedicale.id_patient=patient.id_patient");
    return model;

}

bool dossiermedicale:: supprimer(int numm)
{

    QString num_string=QString::number(numm);

    QSqlQuery query;
          query.prepare("delete from docmedicale where num_dossier= :num");
          query.bindValue(":num", num_string);

           return query.exec();

}



bool dossiermedicale::modifier(int num,QString datec,QString id_p){
    QSqlQuery query;

    QString num_string= QString::number(num);

    query.prepare("UPDATE DOCMEDICALE SET  DATE_CREATION = :datec, ID_PATIENT= :id_p  WHERE NUM_DOSSIER = :num ");
    query.bindValue(":num", num_string);
    query.bindValue(":datec", datec);
    query.bindValue(":id_p", id_p);

    return  query.exec();
}



QSqlQueryModel * dossiermedicale::rechercher(QString id_p)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model-> setQuery("SELECT * FROM patient left join docmedicale on patient.id_patient=docmedicale.id_patient where patient.id_patient = "+id_p);


    return model;
}


QSqlQueryModel * dossiermedicale::tridesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from DOCMEDICALE left join patient on docmedicale.id_patient=patient.id_patient order by NUM_DOSSIER  ");

    return model;
}

QSqlQueryModel * dossiermedicale::consulter(QString id_p)
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Patient where patient.id_patient = "+id_p);

    return model;
}

QString dossiermedicale:: apercu_pdf()
 {
     QString text="             ** Les dossiers medicaux  **       \n \n " ;
     QSqlQuery query ;
     QString i,x,z,m,n,b;
     

      query.exec("select * from DOCMEDICALE left join patient on docmedicale.id_patient=patient.id_patient ");
      while (query.next())
      {
         i=query.value(0).toString();
          x=query.value(1).toString();
          z=query.value(2).toString();
        m=query.value(3).toString();
        n=query.value(4).toString();
        b=query.value(5).toString();



     }

             return text ;
 }

bool dossiermedicale::verifierId(QString id_p)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT ID_PATIENT from PATIENT ");
            while (query.next())
            {
                n=query.value("id_p").toString();
                if (n==id_p)
                {
                    return true;
                }
            }
    return false;

      }
bool dossiermedicale::verifiernum(int num)
{

    QSqlQuery query;
    QString n;

            query.exec("SELECT NUM_DOSSIER from DOCMEDICALE ");
            if (query.value(num)==0)
            {
                n=query.value("NUM_DOSSIER").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }



