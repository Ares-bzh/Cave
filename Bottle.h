#ifndef BOTTLE_H
#define BOTTLE_H

#include <QDomElement>
#include <QDomDocument>
#include <QString>
#include <QDate>
#include <QPoint>
#include <QColor>

class Bottle
{
public:
  enum Couleur {White=0, Red, Rose, ColorNb};
  static const QList<QColor> cstColorList;
  static const QStringList cstColorName;

  Bottle();
  Bottle(
      const Couleur& couleur,
      const bool& mousseux,
      const int& annee,
      const int& dateConso,
      const int& dateLimite,
      const QString& region,
      const QString& sousRegion,
      const QString& domaine,
      const QString& cuvee,
      const QPoint& emlpacement);
  Bottle(const Bottle& a);

  Bottle& operator=(const Bottle& a);
  bool operator==(const Bottle& a);

  inline void setCouleur(const Couleur& couleur){_couleur=couleur;}
  inline void setMousseux(const bool mousseux){_mousseux=mousseux;}
  inline void setAnnee(const int& annee){_annee=annee;}
  inline void setDateConso(const int& dateConso){_dateConso=dateConso;}
  inline void setDateLimite(const int& dateLimite){_dateLimite=dateLimite;}
  inline void setRegion(const QString& region){_region=region;}
  inline void setSousRegion(const QString& sousRegion){_sousRegion=sousRegion;}
  inline void setDomaine(const QString& domaine){_domaine=domaine;}
  inline void setCuvee(const QString& cuvee){_cuvee=cuvee;}
  inline void setEmlpacement(const QPoint& emlpacement){_emlpacement=emlpacement;}

  inline const Couleur& couleur()const{return _couleur;}
  inline const bool& mousseux()const{return _mousseux;}
  inline const int& annee()const{return _annee;}
  inline const int& dateConso()const{return _dateConso;}
  inline const int& dateLimite()const{return _dateLimite;}
  inline const QString& region()const{return _region;}
  inline const QString& sousRegion()const{return _sousRegion;}
  inline const QString& domaine()const{return _domaine;}
  inline const QString& cuvee()const{return _cuvee;}
  inline const QPoint& emlpacement()const{return _emlpacement;}

  inline Couleur& couleur(){return _couleur;}
  inline int& annee(){return _annee;}
  inline int& dateConso(){return _dateConso;}
  inline int& dateLimite(){return _dateLimite;}
  inline QString& region(){return _region;}
  inline QString& sousRegion(){return _sousRegion;}
  inline QString& domaine(){return _domaine;}
  inline QString& cuvee(){return _cuvee;}
  inline QPoint& emlpacement(){return _emlpacement;}

  inline QColor color()const{return cstColorList[_couleur];}

  QDomElement  toDomElement(QDomDocument& document) const;
  Bottle fromDomElement(const QDomElement &elementRequirement);

private:
  Couleur _couleur;
  bool _mousseux;
  int _annee;
  int _dateConso;
  int _dateLimite;
  QString _region;
  QString _sousRegion;
  QString _domaine;
  QString _cuvee;
  QPoint _emlpacement;

};

#endif
