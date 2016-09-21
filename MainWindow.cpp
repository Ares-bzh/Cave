#include "MainWindow.h"
#include "Rack.h"
#include "BottleList.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);

  BottleList bottleList;
  bottleList.append(Bottle(Bottle::DryWhite, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(1,1)));
  bottleList.append(Bottle(Bottle::SweetWhite, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(3,0)));
  bottleList.append(Bottle(Bottle::Rose, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(1,3)));
  bottleList.append(Bottle(Bottle::Red, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(2,5)));
  bottleList.append(Bottle(Bottle::Red, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(2,6)));
  bottleList.append(Bottle(Bottle::Red, false, QDate(2012, 1, 1), QDate(2012, 1, 1), QDate(2012, 1, 1),"", "", "", QPoint(2,7)));

  Rack rack(15, 6, Rack::Quincunx);
  graphicsView->setScene(new QGraphicsScene());

  rack.draw(graphicsView->scene(), bottleList);

}
