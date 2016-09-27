#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

public slots:
  void editRack();
  void open();
  void save();

public:
  explicit MainWindow(QWidget *parent = 0);

private:
  QFile _file;

};

#endif // MAINWINDOW_H
