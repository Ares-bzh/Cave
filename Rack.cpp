#include "Rack.h"

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

void Rack::draw(QGraphicsScene* scene)
{
  int higth, width;

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
        scene->addEllipse(25 + c*40,
                          25 + r*40,
                          30,
                          30,
                          QPen(QColor(0, 0, 0)),
                          QBrush(QColor(255, 255, 255)));
      }
    }
  }
  else
  {
    for(int r=0; r<_row; r++)
    {
      for(int c=0; c<_col-(r%2); c++)
      {
        if(0 ==r%2)
        {
          scene->addEllipse(25 + c*40,
                            25 + r*28,
                            30,
                            30,
                            QPen(QColor(0, 0, 0)),
                            QBrush(QColor(255, 255, 255)));
        }
        else
        {
          scene->addEllipse(25 + c*40 + 20,
                            25 + r*28,
                            30,
                            30,
                            QPen(QColor(0, 0, 0)),
                            QBrush(QColor(255, 255, 255)));
        }
      }
    }
  }
}
