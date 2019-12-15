#include <QFont>
#include "game.h"
#include "score.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QGraphicsTextItem>
//#include <QFont>
#include <QBrush>
#include <QImage>
//#include "healthpoints.h"
//#include "queue.h"


Game::Game(QWidget *parent)
{
  // create the scene
  QGraphicsScene * scene = new QGraphicsScene();
  setScene(scene);
  scene->setSceneRect(0,0,800,600);
  setBackgroundBrush(QBrush(QImage(":/img/scene.png")));
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800,600);
  setCursor(Qt::PointingHandCursor);
  //set music
  QMediaPlayer * music = new QMediaPlayer();
  music->setMedia(QUrl("qrc:/snd/background.mp3"));
  music->play();
  //set score
  Score * score = new Score();
  score->setPos(score->x() + 650, score->y() + 10);
  scene->addItem(score);

}

void Game::createBuyers()
{
 int cashNumber = rand() % 3 + 1;
 //int bType = 1 + (rand() % 3);
 switch (cashNumber)
 {
  case 1:
   {
   int bType = rand() % 3;
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   //putBuyerToQueue(1, *buyer);
   if (first_.empty())
   {
     putBuyerToQueue(1, *buyer);
     buyer->setPos(buyer->x() + 28, buyer->y() + 435);
     scene()->addItem(buyer);
   }
   else if (first_.size() == 1)
   {
     putBuyerToQueue(1, *buyer);
     buyer->setPos(buyer->x() + 60, buyer->y() + 340);
     scene()->addItem(buyer);
   }
   else if (first_.size() == 2)
   {
     putBuyerToQueue(1, *buyer);
     buyer->setPos(buyer->x() + 88, buyer->y() + 245);
     scene()->addItem(buyer);
   }
   else if (first_.size() == 3)
   {
     break;
   }
   break;
   }
  case 2:
 {
   int bType = rand() % 3;
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   //putBuyerToQueue(2, *buyer);
   if (second_.empty())
   {
     putBuyerToQueue(2, *buyer);
     buyer->setPos(buyer->x() + 300, buyer->y() + 435);
     scene()->addItem(buyer);
   }
   else if (second_.size() == 1)
   {
     putBuyerToQueue(2, *buyer);
     buyer->setPos(buyer->x() + 330, buyer->y() + 340);
     scene()->addItem(buyer);
   }
   else if (second_.size() == 2)
   {
     putBuyerToQueue(2, *buyer);
     buyer->setPos(buyer->x() + 360, buyer->y() + 246);
     scene()->addItem(buyer);
   }
   else if (second_.size() == 3)
   {
     break;
   }
   break;
 }
  case 3:
   int bType = rand() % 3;
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   //putBuyerToQueue(3, *buyer);
   if (third_.empty())
   {
     putBuyerToQueue(3, *buyer);
     buyer->setPos(buyer->x() + 560, buyer->y() + 435);
     scene()->addItem(buyer);
   }
   else if (third_.size() == 1)
   {
     putBuyerToQueue(3, *buyer);
     buyer->setPos(buyer->x() + 590, buyer->y() + 340);
     scene()->addItem(buyer);
   }
   else if (third_.size() == 2)
   {
     putBuyerToQueue(3, *buyer);
     buyer->setPos(buyer->x() + 620, buyer->y() + 246);
     scene()->addItem(buyer);
   }
   else if (third_.size() == 3)
   {
     break;
   }
 }

}

void Game::putBuyerToQueue(int cashNumber, Buyer &buyer)
{
  switch (cashNumber)
  {
    case 1:
    {
      first_.push_back(&buyer);
      break;
    }
    case 2:
    {
      second_.push_back(&buyer);
      break;
    }
    case 3:
  {
      third_.push_back(&buyer);
      break;
  }
  }
}
void Game::Play()
{
  scene()->clear();
  //setCursor(Qt::BlankCursor);
  //Queue::createBuyers();
  CashRegister * cashregister_1 = new CashRegister();
  cashregister_1 -> setPos(cashregister_1->x() + 95,cashregister_1->y() + 400);
  scene()->addItem(cashregister_1);

  CashRegister * cashregister_2 = new CashRegister();
  cashregister_2 -> setPos(cashregister_2->x() + 370,cashregister_2->y() + 400);
  scene()->addItem(cashregister_2);

  CashRegister * cashregister_3 = new CashRegister();
  cashregister_3 -> setPos(cashregister_3->x() + 630,cashregister_3->y() + 400);
  scene()->addItem(cashregister_3);

  QTimer *pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &Game::createBuyers);
    pTimer->start(2000);
}



void Game::gameOver()
{
  close();
}
//  Health * health_1 = new Health();
//  healths_.push_back(health_1);
//  health_1->setPos(health_1->x() + 15,health_1->y() + 15);
//  scene->addItem(health_1);

//  Health * health_2 = new Health();
//  healths_.push_back(health_2);
//  health_2->setPos(health_2->x() + 50,health_2->y() + 15);
//  scene->addItem(health_2);

//  Health * health_3 = new Health();
//  healths_.push_back(health_3);
//  health_3->setPos(health_3->x() + 85,health_3->y() + 15);
//  scene->addItem(health_3);

//  scene->removeItem(health_3);
//  healths_.pop_back();
// //decrease(healths_);
//  //scene -> removeItem(health);

//// create the cashiers
//  cashregister = new CashRegister();
//  cashregister -> setPos(cashregister->x() + 95,cashregister->y() + 400);
//  scene->addItem(cashregister);

//  cashregister = new CashRegister();
//  cashregister -> setPos(cashregister->x() + 370,cashregister->y() + 400);
//  scene->addItem(cashregister);

//  cashregister = new CashRegister();
//  cashregister -> setPos(cashregister->x() + 630,cashregister->y() + 400);
//  scene->addItem(cashregister);

