#include "MainWindow.h"
#include "DialogRack.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);

  topMenuBar->addAction(actionModifierCasier);


  connect(actionModifierCasier, SIGNAL(triggered(bool)), this, SIGNAL(editRack()));
}

void MainWindow::editRack()
{
  DialogRack dialog(graphicsView->rack(), this);
  if(QDialog::Accepted == dialog.exec())
  {
    graphicsView->setRack();
  }
}
