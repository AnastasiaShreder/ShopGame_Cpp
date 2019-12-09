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

// void
// set graphic
// robotError = new QGraphicsPixmapItem
// robotError = setPixmap(QPixmap(":/img/robot_error.png"));



