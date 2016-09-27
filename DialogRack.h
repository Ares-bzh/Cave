#ifndef DIALOGRACK_H
#define DIALOGRACK_H

#include "ui_DialogRack.h"
#include "Rack.h"

class DialogRack : public QDialog, private Ui::DialogRack
{
  Q_OBJECT

public:
  explicit DialogRack(Rack &rack, QWidget *parent = 0);

public slots :
  void accept();

private:
  Rack& _rack;
};

#endif // DIALOGRACK_H
