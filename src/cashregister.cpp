#include "cashregister.h"
#include <QGraphicsScene>
#include <QKeyEvent>

CashRegister::CashRegister(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
  setPixmap(QPixmap(":/img/robot_cashier")); //set normal state for cashier(default mode)
}

void CashRegister::setStatus(int statusNumber)      // statusNumber = 1 - cashier want to begin service
{                                                   // statusNumber = 2 - cashier with error
  switch (statusNumber)                             // statusNumber = 3 - cashier ready to finish service
  {                                                 // statusNumber = 4 - cashier in default mode
    case 1:
    {
      setPixmap(QPixmap(":/img/robot_lamp.png"));
      pixmap = ":/img/robot_lamp.png";
      break;
    }
    case 2:
    {
      setPixmap(QPixmap(":/img/robot_error.png"));
      pixmap = ":/img/robot_error.png";
      break;
    }
    case 3:
    {
      setPixmap(QPixmap(":/img/robot_ready.png"));
      pixmap = ":/img/robot_ready.png";
      break;
    }
    case 4:
    {
      setPixmap(QPixmap(":/img/robot_cashier.png"));
      pixmap = ":/img/robot_cashier.png";
      break;
    }
  }
}

int CashRegister::getStatus()
{
  if (pixmap == ":/img/robot_lamp.png")
  {
    return 1;
  }
  if (pixmap == ":/img/robot_error.png")
  {
    return 2;
  }
  if (pixmap == ":/img/robot_ready.png")
  {
    return 3;
  }
  if (pixmap == ":/img/robot_cashier.png")
  {
    return 4;
  }
}

