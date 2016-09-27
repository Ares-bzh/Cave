#include "DialogBottle.h"

DialogBottle::DialogBottle(Bottle &bottle, QWidget *parent) :
  QDialog(parent), _bottle(bottle)
{
  setupUi(this);

  comboBoxCouleur->addItems(Bottle::cstColorName);
  comboBoxCouleur->setCurrentIndex(bottle.couleur());
  checkBoxMousseux->setChecked(bottle.mousseux());
  spinBoxAnnee->setValue(bottle.annee());
  spinBoxAnneeConso->setValue(bottle.dateConso());
  spinBoxAnneeLimite->setValue(bottle.dateLimite());
  lineEditRegion->setText(bottle.region());
  lineEditSousRegion->setText(bottle.sousRegion());
  lineEditDomaine->setText(bottle.domaine());
  lineEditCuvee->setText(bottle.cuvee());
}

void DialogBottle::accept()
{
  _bottle.setCouleur((Bottle::Couleur)comboBoxCouleur->currentIndex());
  _bottle.setMousseux(checkBoxMousseux->isChecked());
  _bottle.setAnnee(spinBoxAnnee->value());
  _bottle.setDateConso(spinBoxAnneeConso->value());
  _bottle.setDateLimite(spinBoxAnneeLimite->value());
  _bottle.setRegion(lineEditRegion->text());
  _bottle.setSousRegion(lineEditSousRegion->text());
  _bottle.setDomaine(lineEditDomaine->text());
  _bottle.setCuvee(lineEditCuvee->text());

  QDialog::accept();
}
