#include "Rack.h"
#include "PosGraphicsEllipseItem.h"

Rack::Rack()
{

}

Rack::Rack(
    const int& row,
    const int& col,
    const Type& type):
  _row(row),
  _col(col),
  _type(type)
{

}

Rack::Rack(const Rack& a)
{
  *this = a;
}

Rack& Rack::operator=(const Rack& a)
{
  _row=a.row();
  _col=a.col();
  _type=a.type();
  return *this;
}

QDomElement Rack::toDomElement(QDomDocument& document) const
{
  QDomElement rackElement = document.createElement("Rack");

  rackElement.setAttribute("row", _row);
  rackElement.setAttribute("col", _col);
  rackElement.setAttribute("type", _type);

  return rackElement;
}

Rack Rack::fromDomElement(const QDomElement &rackElement)
{
  _row = rackElement.attribute("row").toInt();
  _col = rackElement.attribute("col").toInt();
  _type = (Type)rackElement.attribute("type").toInt();

  return *this;
}

void Rack::draw(QGraphicsScene* scene, BottleList& bottleList)
{
  int higth, width;
  QPen pen(QColor(0, 0, 0));

  scene->clear();
  higth = ((Straight == _type)?40:30) * _row;
  width = 40 * _col;

  scene->setSceneRect(0, 0, width+20, higth+20);

  scene->addRect(20, 20, width, higth, QPen(QColor(128, 128, 128)), QBrush(QColor(128, 128, 128)));

  if(Straight == _type)
  {
    for(int r=0; r<_row; r++)
    {
      for(int c=0; c<_col; c++)
      {
        Bottle* currentBottle = bottleList.fromPos(QPoint(c,r));
        QBrush brush(Qt::SolidPattern);
        if(NULL != currentBottle)
        {
          brush.setColor(currentBottle->color());
          brush.setStyle(currentBottle->mousseux()?Qt::Dense2Pattern:Qt::SolidPattern);
        }
        else
          brush.setColor(QColor(255, 255, 255));

        PosGraphicsEllipseItem* item = new PosGraphicsEllipseItem(QPoint(c,r));
        item->setPen(pen);
        item->setBrush(brush);
        item->setRect(25 + c*40, 25 + r*40, 30, 30);
        scene->addItem(item);

        if(NULL != currentBottle)
        {
          brush.setStyle(Qt::SolidPattern);
          brush.setColor(currentBottle->colorConso());
          scene->addRect(30 + c*40, 30 + r*40, 5, 5, pen, brush);
        }
      }
    }
  }
  else
  {
    for(int r=0; r<_row; r++)
    {
      for(int c=0; c<_col-(r%2); c++)
      {
        Bottle* currentBottle = bottleList.fromPos(QPoint(c,r));
        QBrush brush(Qt::SolidPattern);
        if(NULL != currentBottle)
        {
          brush.setColor(currentBottle->color());
          brush.setStyle(currentBottle->mousseux()?Qt::Dense3Pattern:Qt::SolidPattern);
        }
        else
          brush.setColor(QColor(255, 255, 255));

        PosGraphicsEllipseItem* item = new PosGraphicsEllipseItem(QPoint(c,r));
        item->setPen(pen);
        item->setBrush(brush);
        item->setRect((r%2)?(25 + c*40 + 20):(25 + c*40), 25 + r*28, 30, 30);
        scene->addItem(item);

        if(NULL != currentBottle)
        {
          brush.setStyle(Qt::SolidPattern);
          brush.setColor(currentBottle->colorConso());
          scene->addRect((r%2)?(30 + c*40 + 20):(30 + c*40), 30 + r*28, 5, 5, pen, brush);
        }

      }
    }
  }
}
