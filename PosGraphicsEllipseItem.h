#ifndef POSGRAPHICSELLIPSEITEM_H
#define POSGRAPHICSELLIPSEITEM_H

#include <QGraphicsEllipseItem>

class PosGraphicsEllipseItem : public QGraphicsEllipseItem
{
public:
  PosGraphicsEllipseItem(const QPoint& emlpacement, QGraphicsItem *parent = Q_NULLPTR);
  inline void setEmlpacement(const QPoint& emlpacement){_emlpacement=emlpacement;}
  inline const QPoint& emlpacement()const{return _emlpacement;}
  inline QPoint& emlpacement(){return _emlpacement;}

private:
  QPoint _emlpacement;
};

#endif // POSGRAPHICSELLIPSEITEM_H
