#ifndef BOTTLELIST_H
#define BOTTLELIST_H

#include <QList>
#include "Bottle.h"

class BottleList: public QList<Bottle>
{
public:
    BottleList();

    void toDomElement(QDomDocument& document, QDomElement& parentElement) const;
    BottleList fromDomElement(const QDomElement &elementRequirement);

    Bottle* fromPos(QPoint pos);
};

#endif
