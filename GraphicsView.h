#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDomElement>
#include "Rack.h"
#include "BottleList.h"

class GraphicsView : public QGraphicsView
{
  Q_OBJECT
public:
  explicit GraphicsView(QWidget *parent = 0);
  inline void setBottleList(const BottleList& bottleList){_bottleList=bottleList;}
  inline void setRack(const Rack rack){_rack=rack;}

  inline const BottleList& bottleList()const{return _bottleList;}
  inline const Rack& rack()const{return _rack;}

  inline BottleList& bottleList(){return _bottleList;}
  inline Rack& rack(){return _rack;}

  inline void draw(){_rack.draw(scene(), _bottleList);}

public slots :
  void showCustomContextMenu(QPoint pos);

protected:
  void wheelEvent(QWheelEvent *event);
  void mouseDoubleClickEvent(QMouseEvent *event);
  void editBottle(QPoint emplacement);
  void rmBottle(Bottle* bottle);
  void pasteBottle(QPoint emplacement);

public slots:


private :
  BottleList _bottleList;
  Rack _rack;
  Bottle _copy;
};

#endif // GRAPHICSVIEW_H
