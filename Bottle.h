#ifndef BOTTLE_H
#define BOTTLE_H

#include <QDomElement>
#include <QDomDocument>
#include <QString>
#include <QDate>
#include <QPoint>

class Bottle
{
public:
    enum Couleur {DryWhite=0, SweetWhite, Red, Rose, Champagne};

    Bottle();
    Bottle(
      const Couleur& couleur,
      const QDate& annee,
      const QDate& dateConso,
      const QDate& dateLimite,
      const QString& region,
      const QString& sousRegion,
      const QString& appelation,
      const QPoint& emlpacement);
    Bottle(const Bottle& a);

    Bottle& operator=(const Bottle& a);

    inline void setCouleur(const Couleur& couleur){_couleur=couleur;}
    inline void setAnnee(const QDate& annee){_annee=annee;}
    inline void setDateConso(const QDate& dateConso){_dateConso=dateConso;}
    inline void setDateLimite(const QDate& dateLimite){_dateLimite=dateLimite;}
    inline void setRegion(const QString& region){_region=region;}
    inline void setSousRegion(const QString& sousRegion){_sousRegion=sousRegion;}
    inline void setAppelation(const QString& appelation){_appelation=appelation;}
    inline void setEmlpacement(const QPoint& emlpacement){_emlpacement=emlpacement;}

    inline const Couleur& couleur()const{return _couleur;}
    inline const QDate& annee()const{return _annee;}
    inline const QDate& dateConso()const{return _dateConso;}
    inline const QDate& dateLimite()const{return _dateLimite;}
    inline const QString& region()const{return _region;}
    inline const QString& sousRegion()const{return _sousRegion;}
    inline const QString& appelation()const{return _appelation;}
    inline const QPoint& emlpacement()const{return _emlpacement;}

    inline Couleur& couleur(){return _couleur;}
    inline QDate& annee(){return _annee;}
    inline QDate& dateConso(){return _dateConso;}
    inline QDate& dateLimite(){return _dateLimite;}
    inline QString& region(){return _region;}
    inline QString& sousRegion(){return _sousRegion;}
    inline QString& appelation(){return _appelation;}
    inline QPoint& emlpacement(){return _emlpacement;}

    QDomElement  toDomElement(QDomDocument& document) const;
    Bottle fromDomElement(const QDomElement &elementRequirement);

private:
    Couleur _couleur;
    QDate _annee;
    QDate _dateConso;
    QDate _dateLimite;
    QString _region;
    QString _sousRegion;
    QString _appelation;
    QPoint _emlpacement;

};

#endif
