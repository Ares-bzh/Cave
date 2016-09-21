#include "BottleList.h"

BottleList::BottleList()
{

}

Bottle* BottleList::fromPos(QPoint pos)
{
  Bottle* ret=NULL;
  for(int i=0; i<count() && NULL == ret; i++)
    if(pos == at(i).emlpacement())
      ret = &(operator [](i));
  return ret;
}


void BottleList::toDomElement(QDomDocument& document, QDomElement& parentElement) const
{
  foreach (const Bottle& currentBottle, *this)
    parentElement.appendChild(currentBottle.toDomElement(document));
}

BottleList BottleList::fromDomElement(const QDomElement &bottleListElement)
{
  QDomNodeList xmlBottleList = bottleListElement.elementsByTagName("Bottle");
  for(int i=0; i<xmlBottleList.count(); i++)
    append(Bottle().fromDomElement(xmlBottleList.at(i).toElement()));
  return *this;
}
