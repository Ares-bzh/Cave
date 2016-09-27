#include "Bottle.h"
#include <QDate>

const QStringList Bottle::cstColorName = QStringList()<<"Blanc" << "Rouge" << "Rosé";
const QList<QColor> Bottle::cstColorList = QList<QColor>() << QColor(244, 242, 155) << QColor(160, 20, 20) << QColor(255, 160, 160);


Bottle::Bottle()
{
  _couleur=Red;
  _mousseux=false;
  _annee=2012;
  _dateConso=2016;
  _dateLimite=2020;
}

Bottle::Bottle(
      const Couleur& couleur,
      const bool& mousseux,
      const int& annee,
      const int& dateConso,
      const int& dateLimite,
      const QString& region,
      const QString& sousRegion,
      const QString& domaine,
    const QString& cuvee,
      const QPoint& emlpacement):
    _couleur(couleur),
    _mousseux(mousseux),
    _annee(annee),
    _dateConso(dateConso),
    _dateLimite(dateLimite),
    _region(region),
    _sousRegion(sousRegion),
    _domaine(domaine),
    _cuvee(cuvee),
    _emlpacement(emlpacement)
{

}

Bottle::Bottle(const Bottle& a)
{
    *this = a;
}

Bottle& Bottle::operator=(const Bottle& a)
{
    _couleur=a.couleur();
    _mousseux=a.mousseux();
    _annee=a.annee();
    _dateConso=a.dateConso();
    _dateLimite=a.dateLimite();
    _region=a.region();
    _sousRegion=a.sousRegion();
    _domaine=a.domaine();
    _cuvee=a.cuvee();
    _emlpacement=a.emlpacement();
    return *this;
}


bool Bottle::operator==(const Bottle& a)
{
    bool ret = _couleur==a.couleur();
    ret = ret && _mousseux==a.mousseux();
    ret = ret && _annee==a.annee();
    ret = ret && _dateConso==a.dateConso();
    ret = ret && _dateLimite==a.dateLimite();
    ret = ret && _region==a.region();
    ret = ret && _sousRegion==a.sousRegion();
    ret = ret && _domaine==a.domaine();
    ret = ret && _cuvee==a.cuvee();
    ret = ret && _emlpacement==a.emlpacement();
    return ret;
}

QDomElement Bottle::toDomElement(QDomDocument& document) const
{
    QDomElement bottleElement = document.createElement("Bottle");

    bottleElement.setAttribute("couleur", _couleur);

    bottleElement.setAttribute("annee", _annee);

    bottleElement.setAttribute("dateConso", _dateConso);

    bottleElement.setAttribute("dateLimite", _dateLimite);

    bottleElement.setAttribute("region", _region);

    bottleElement.setAttribute("sousRegion", _sousRegion);

    bottleElement.setAttribute("domaine", _domaine);

    bottleElement.setAttribute("cuvee", _cuvee);

    bottleElement.setAttribute("x", _emlpacement.x());

    bottleElement.setAttribute("y", _emlpacement.y());

    bottleElement.setAttribute("mousseux", _mousseux);

    return bottleElement;
}

Bottle Bottle::fromDomElement(const QDomElement &bottleElement)
{
    _couleur = (Couleur)bottleElement.attribute("couleur").toInt();

    _annee = bottleElement.attribute("annee").toInt();

    _dateConso = bottleElement.attribute("dateConso").toInt();

    _dateLimite = bottleElement.attribute("dateLimite").toInt();

    _region = bottleElement.attribute("region");

    _sousRegion = bottleElement.attribute("sousRegion");

    _domaine = bottleElement.attribute("domaine");

    _cuvee = bottleElement.attribute("cuvee");

    _emlpacement.setX(bottleElement.attribute("x").toInt());

    _emlpacement.setY(bottleElement.attribute("y").toInt());

    _mousseux = bottleElement.attribute("mousseux").toInt();

    return *this;
}


QColor Bottle::colorConso()const
{
  int currentYear = QDate::currentDate().year();
  if(_dateConso> currentYear)
    return QColor(255,255,255);
  else if(_dateLimite> currentYear)
    return QColor(0,255,0);
  else if(_dateLimite==currentYear)
    return QColor(255,255,0);
  else
    return QColor(255,0,0);
}
