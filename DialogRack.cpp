#include "DialogRack.h"

DialogRack::DialogRack(Rack &rack, QWidget *parent) :
  QDialog(parent), _rack(rack)
{
  setupUi(this);

  spinBoxColumn->setValue(_rack.col());
  spinBoxRow->setValue(_rack.row());
  checkBox->setChecked(_rack.type()==Rack::Quincunx);
}

void DialogRack::accept()
{
  _rack.setType((Rack::Type)checkBox->isChecked());
  _rack.setCol(spinBoxColumn->value());
  _rack.setRow(spinBoxRow->value());

  QDialog::accept();
}
