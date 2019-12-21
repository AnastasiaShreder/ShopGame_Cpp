#include "cashregister.h"
#include <QGraphicsScene>
#include <QKeyEvent>

CashRegister::CashRegister(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
// set cash-sound
  cashsound = new QMediaPlayer();
  cashsound->setMedia(QUrl(":/snd/cash-register.mp3"));
// set click-sound
  clicksound = new QMediaPlayer();
  clicksound->setMedia(QUrl("qrc:/snd/click.wav"));
// set graphic
  setPixmap(QPixmap(":/img/robot_cashier"));
}

void CashRegister::setStatus(int statusNumber)
{
  switch (statusNumber)
  {
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
//void CashRegister::mousePressEvent(QMouseEvent *event)
//{
//   if (getStatus(cashes_[0]))
//    if(event->button()==Qt::RightButton)
//        emit btnRightClicked();
//}
// void
// set graphic
// robotError = new QGraphicsPixmapItem
// robotError = setPixmap(QPixmap(":/img/robot_error.png"));



