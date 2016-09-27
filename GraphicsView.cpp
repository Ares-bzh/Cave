#include "GraphicsView.h"
#include "QDebug"
#include <qmath.h>
#include "PosGraphicsEllipseItem.h"
#include "DialogBottle.h"
#include <QMenu>
#include <QAction>

GraphicsView::GraphicsView(QWidget *parent) : QGraphicsView(parent)
{

  setScene(new QGraphicsScene());
  _copy.setAnnee(0);

  _rack.setCol(4);
  _rack.setRow(4);
  _rack.setType(Rack::Quincunx);

  _rack.draw(scene(), _bottleList);

  connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showCustomContextMenu(QPoint)));
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
  static int zoom=0;

  int zoomTmp = qMax(qMin(10, zoom+event->angleDelta().y()/120), -10);
  if(10 > zoomTmp && zoomTmp > -10)
  {
    qreal scl = qPow(2, 0.5*(zoom-zoomTmp));
    scale(scl,scl);
    zoom = zoomTmp;
  }

  event->accept();
}


void GraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
  QGraphicsItem* item = itemAt(event->pos());

  if(NULL !=item && QGraphicsEllipseItem::Type == item->type())
    editBottle(((PosGraphicsEllipseItem*)item)->emlpacement());

  event->accept();
}

void GraphicsView::showCustomContextMenu(QPoint pos)
{
  QGraphicsItem* item = itemAt(pos);

  if(NULL !=item && QGraphicsEllipseItem::Type == item->type())
  {
    QMenu menu;
    Bottle* bottle = _bottleList.fromPos(((PosGraphicsEllipseItem*)item)->emlpacement());
    if(NULL == bottle)
    {
      menu.addAction("Ajouter");
      if(0 != _copy.annee())
        menu.addAction("Coller");
    }
    else
    {
      menu.addAction("Editer");
      menu.addAction("Copier");
      menu.addAction("Supprimer");
    }
    QAction* act = menu.exec(mapToGlobal(pos));

    if(NULL  != act)
    {
      if(act->text() == "Ajouter" || act->text() == "Editer")
        editBottle(((PosGraphicsEllipseItem*)item)->emlpacement());
      else if (act->text() == "Coller")
        pasteBottle(((PosGraphicsEllipseItem*)item)->emlpacement());
      else if (act->text() == "Copier")
        _copy = *bottle;
      else if (act->text() == "Supprimer")
        rmBottle(bottle);
    }
  }

}



void GraphicsView::editBottle(QPoint emplacement)
{
  Bottle* bottle = _bottleList.fromPos(emplacement);
  bool newBottle = bottle==NULL;
  if(newBottle)
  {
    bottle = new Bottle();
    bottle->setEmlpacement(emplacement);
  }

  DialogBottle dialog(*bottle, this);
  if(QDialog::Accepted == dialog.exec())
  {
    if(newBottle)
      _bottleList.append(*bottle);
    _rack.draw(scene(), _bottleList);
  }

  if(newBottle)
    free(bottle);
}

void GraphicsView::pasteBottle(QPoint emplacement)
{
  Bottle bottle(_copy);
  bottle.setEmlpacement(emplacement);
  _bottleList.append(bottle);

  _rack.draw(scene(), _bottleList);
}

void GraphicsView::rmBottle(Bottle* bottle)
{
  _bottleList.removeOne(*bottle);

  _rack.draw(scene(), _bottleList);
}
