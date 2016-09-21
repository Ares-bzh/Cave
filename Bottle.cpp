#include "Bottle.h"

Bottle::Bottle()
{

}

Bottle::Bottle(
      const Couleur& couleur,
      const bool& mousseux,
      const QDate& annee,
      const QDate& dateConso,
      const QDate& dateLimite,
      const QString& region,
      const QString& sousRegion,
      const QString& appelation,
      const QPoint& emlpacement):
    _couleur(couleur),
    _mousseux(mousseux),
    _annee(annee),
    _dateConso(dateConso),
    _dateLimite(dateLimite),
    _region(region),
    _sousRegion(sousRegion),
    _appelation(appelation),
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
    _appelation=a.appelation();
    _emlpacement=a.emlpacement();
    return *this;
}

QDomElement Bottle::toDomElement(QDomDocument& document) const
{
    QDomElement bottleElement = document.createElement("Bottle");

    bottleElement.setAttribute("couleur", _couleur);

    bottleElement.setAttribute("annee", _annee.toString("yyyy"));

    bottleElement.setAttribute("dateConso", _dateConso.toString("yyyy"));

    bottleElement.setAttribute("dateLimite", _dateLimite.toString("yyyy"));

    bottleElement.setAttribute("region", _region);

    bottleElement.setAttribute("sousRegion", _sousRegion);

    bottleElement.setAttribute("appelation", _appelation);

    bottleElement.setAttribute("x", _emlpacement.x());

    bottleElement.setAttribute("y", _emlpacement.y());

    bottleElement.setAttribute("mousseux", _mousseux);

    return bottleElement;
}

Bottle Bottle::fromDomElement(const QDomElement &bottleElement)
{
    _couleur = (Couleur)bottleElement.attribute("couleur").toInt();

    _annee = QDate::fromString(bottleElement.attribute("annee"), "yyyy");

    _dateConso = QDate::fromString(bottleElement.attribute("dateConso"), "yyyy");

    _dateLimite = QDate::fromString(bottleElement.attribute("dateLimite"), "yyyy");

    _region = bottleElement.attribute("region");

    _sousRegion = bottleElement.attribute("sousRegion");

    _appelation = bottleElement.attribute("appelation");

    _emlpacement.setX(bottleElement.attribute("x").toInt());

    _emlpacement.setY(bottleElement.attribute("y").toInt());

    _mousseux = bottleElement.attribute("mousseux").toInt();

    return *this;
}
