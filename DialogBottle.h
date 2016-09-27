#ifndef DIALOGBOTTLE_H
#define DIALOGBOTTLE_H

#include "ui_DialogBottle.h"
#include "Bottle.h"

class DialogBottle : public QDialog, private Ui::DialogBottle
{
  Q_OBJECT

public:
  explicit DialogBottle(Bottle& bottle, QWidget *parent = 0);

public slots :
  void accept();

private :
  Bottle& _bottle;
};

#endif // DIALOGBOTTLE_H
