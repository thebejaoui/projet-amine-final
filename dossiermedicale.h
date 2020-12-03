#ifndef DOSSIERMEDICALE_H
#define DOSSIERMEDICALE_H
#include<QSqlQueryModel>
#include<QString>
class dossiermedicale
{
public:
    dossiermedicale();
    dossiermedicale(int,QString,QString);
    int getnum();
    QString getdatec();
    QString getid_p();
   void setnum(int );
   void setdatec(QString);
   void setid_p(QString);
   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier(int,QString ,QString);
   QSqlQueryModel * rechercher(QString );
   QSqlQueryModel * tridesc();
   QSqlQueryModel * consulter(QString id_p);
   QString  apercu_pdf();
   bool verifierId(QString id_p);
   bool verifiernum(int num);

private:
    int num;
    QString datec;
    QString id_p;
};

#endif // DOSSIERMEDICALE_H
