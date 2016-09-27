#include "MainWindow.h"
#include "DialogRack.h"
#include <QFileDialog>
#include <QDir>
#include <QDomDocument>


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent)
{
  setupUi(this);

  topMenuBar->addAction(actionModifierCasier);


  connect(actionModifierCasier, SIGNAL(triggered(bool)), this, SLOT(editRack()));
  connect(actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
  connect(actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
}

void MainWindow::editRack()
{
  DialogRack dialog(graphicsView->rack(), this);
  if(QDialog::Accepted == dialog.exec())
  {
    graphicsView->draw();
  }
}

void MainWindow::open()
{
  QDomDocument document;
  Rack rack;
  BottleList bottleList;
  QString fileName = QFileDialog::getOpenFileName(this, "Ouvrir", QDir::homePath(), "*.xml");

  if(!fileName.isEmpty())
  {
    _file.setFileName(fileName);
    _file.open(QIODevice::ReadOnly);
    document.setContent(_file.readAll());
    _file.close();
    rack.fromDomElement(document.elementsByTagName("Rack").at(0).toElement());
    bottleList.fromDomElement(document.elementsByTagName("BottleList").at(0).toElement());

    graphicsView->setRack(rack);
    graphicsView->setBottleList(bottleList);
    graphicsView->draw();
  }
}

void MainWindow::save()
{
  QDomDocument document;
  QDomElement do_element = document.createElement("DATA");
  do_element.setAttribute("SUBJECT", "XML");

  do_element.appendChild(graphicsView->rack().toDomElement(document));
    QDomElement bottleListElement = document.createElement("BottleList");
  graphicsView->bottleList().toDomElement(document, bottleListElement);
  do_element.appendChild(bottleListElement);

  document.appendChild(do_element);

  QDomNode node( document.createProcessingInstruction( "xml", "version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\" " ) );
  document.insertBefore( node, document.firstChild() );

  if(!_file.exists())
  {
    QString fileName = QFileDialog::getSaveFileName(this, "Sauvegarder", QDir::homePath());
    if(!fileName.isEmpty())
    {
      _file.setFileName(fileName);
    }
  }

  if(!_file.fileName().isEmpty())
  {
    _file.open(QIODevice::WriteOnly);
    _file.write(document.toByteArray());
    _file.close();
  }
}
