#include "MainWindow.h"
#include "Rack.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);

  Rack rack(15, 6, Rack::Quincunx);
  graphicsView->setScene(new QGraphicsScene());

  rack.draw(graphicsView->scene());

}
