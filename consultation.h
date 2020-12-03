#ifndef CONSULTATION_H
#define CONSULTATION_H
#include<QSqlQueryModel>
#include<QString>

class consultation
{
public:
    consultation();
    consultation(int,int,QString,QString,int,int,int,int,QString);
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
      QSqlQueryModel * rechercher(int );
       QSqlQueryModel * tridesc();
         bool modifier(int,int,QString,QString,int,int,int,int,QString);
           QString  apercu_pdf();


private:
int num;
int num_interv;
QString date_inter;
QString probl;
int tension;
int glycemie;
int poids;
int taille;
QString ordonnance;



};

#endif // CONSULTATION_H
