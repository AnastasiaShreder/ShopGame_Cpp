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
#include "queue.h"


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
  //setStyleSheet("border-style:none");
  //set music
  QMediaPlayer * music = new QMediaPlayer();
  music->setMedia(QUrl("qrc:/snd/background.mp3"));
  music->play();
}

void Game::createBuyers()
{
 int cashNumber = 1 + (rand() % 3);
 int bType = 1 + (rand() % 3);
 Queue queue;
 switch (cashNumber)
 {
  case 1:
   {
   int bType = 1 + (rand() % 3);
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   putBuyerToQueue(queue, *buyer, CashNumber::FIRST);
   if (first_.size() == 0)
   {
     buyer->setPos(buyer->x() + 28, buyer->y() + 435);
     scene()->addItem(buyer);
   }
   else if (first_.size() == 1)
   {
     buyer->setPos(buyer->x() + 28, buyer->y() + 435);
     scene()->addItem(buyer);
   }
   else if (first_.size() == 2)
   {

   }
   }
  case 2:
   {
   int bType = 1 + (rand() % 3);
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   putBuyerToQueue(*buyer, CashNumber::SECOND);
   buyer->setPos(buyer->x() + 60, buyer->y() + 340);
   break;
   }
  case 3:
 {
   int bType = 1 + (rand() % 3);
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   putBuyerToQueue(*buyer, CashNumber::THIRD);
   buyer->setPos(buyer->x() + 60, buyer->y() + 340);
 }
 }

 //putBuyerToQueue(const Buyer &buyer, CashNumber number)

 Buyer * buyer1 = new Buyer(static_cast<BuyerType>(bType));
 buyer1 -> setPos(buyer1->x() + 28, buyer1->y() + 435);
 scene()->addItem(buyer1);
}

void Game::Play()
{
  scene()->clear();
  //setCursor(Qt::BlankCursor);
  //Queue::createBuyers();
  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 95,cashregister->y() + 400);
  scene()->addItem(cashregister);

  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 370,cashregister->y() + 400);
  scene()->addItem(cashregister);

  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 630,cashregister->y() + 400);
  scene()->addItem(cashregister);

  QTimer *pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &queue::createBuyers());
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
////set score
//  score = new Score();
//  score->setPos(score->x() + 650, score->y() + 10);
//  scene->addItem(score);
//// play background music
//  QMediaPlayer * music = new QMediaPlayer();
//  music->setMedia(QUrl("qrc:/snd/background.mp3"));
//  music->play();
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

// create the buyers

//  Buyer * buyer2 = new Buyer();
//  buyer2 -> setPos(buyer2->x() + 60,buyer2->y() + 340);
//  scene->addItem(buyer2);

//  Buyer * buyer3 = new Buyer();
//  buyer3 -> setPos(buyer3->x() + 88,buyer3->y() + 245);
//  scene->addItem(buyer3);

//  Buyer * buyer4 = new Buyer();
//  buyer4 -> setPos(buyer4->x() + 300,buyer4->y() + 435);
//  scene->addItem(buyer4);

//  Buyer * buyer5 = new Buyer();
//  buyer5 -> setPos(buyer5->x() + 330,buyer5->y() + 340);
//  scene->addItem(buyer5);

//  Buyer * buyer6 = new Buyer();
//  buyer6 -> setPos(buyer6->x() + 360,buyer6->y() + 246);
//  scene->addItem(buyer6);

//  Buyer * buyer7 = new Buyer();
//  buyer7 -> setPos(buyer7->x() + 560,buyer7->y() + 435);
//  scene->addItem(buyer7);

//  Buyer * buyer8 = new Buyer();
//  buyer8 -> setPos(buyer8->x() + 590,buyer8->y() + 340);
//  scene->addItem(buyer8);

//  Buyer * buyer9 = new Buyer();
//  buyer9 -> setPos(buyer9->x() + 620,buyer9->y() + 246);
//  scene->addItem(buyer9);

