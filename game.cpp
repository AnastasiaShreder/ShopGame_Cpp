#include <QFont>
#include "game.h"
#include "score.h"
#include "cashregister.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QGraphicsTextItem>
//#include <QFont>
#include <QBrush>
#include <QImage>
//#include "switch.h"
//#include "healthpoints.h"
//#include "queue.h"
#include <QTime>
#include <QCoreApplication>

Game::Game()
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

void Game::replaceBuyers(std::list<Buyer*> list)
{
  setFocusPolicy(Qt::StrongFocus);
    cashes_[0] -> setFocus();
    if ((cashes_[0] -> getStatus()) == 1)
    {
      cashes_[0] -> setStatus(4);
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    cashes_[0] -> setStatus(3);
    }
    if ((cashes_[0] -> getStatus()) == 3)
    {
      if (list.size() == 3)
      {
      buyerIter_1 = (list.begin())++;
      scene() -> removeItem(*list.begin());
      list.pop_front();
      --buyerIter_1;
      --(list.end());
       QTimer * bTimer_1 = new QTimer(*buyerIter_1);
       connect(bTimer_1, SIGNAL(&QTimer::timeout), *buyerIter_1, SLOT(&Buyer::move(32, 435)));
       bTimer_1->start(10);
       QTimer * bTimer_2 = new QTimer(*list.end());
       connect(bTimer_2, SIGNAL(&QTimer::timeout), *buyerIter_1, SLOT(&Buyer::move(28, 340)));
       bTimer_2->start(10);
      }
      else if (list.size() == 2)
      {
        buyerIter_1 = (list.begin())++;
        scene() -> removeItem(*list.begin());
        list.pop_front();
        --buyerIter_1;
        QTimer * bTimer_1 = new QTimer(*buyerIter_1);
        connect(bTimer_1, SIGNAL(&QTimer::timeout), *buyerIter_1, SLOT(&Buyer::move(32, 435)));
        bTimer_1->start(10);
      }
      else if (list.size() == 1)
      {
        list.pop_front();
      }
    }
  }

void Game::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
    case (Qt::Key_1):
    {
    replaceBuyers(first_);
    break;
    }
    case (Qt::Key_2):
    {
      replaceBuyers(second_);
      break;
    }
    case (Qt::Key_3):
    {
      replaceBuyers(third_);
      break;
    }

  }
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
     //QTimer::singleShot(5000, cashes_[0], setStatus(3))
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
     cashIter_2 = second_.begin();
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
 {
   int bType = rand() % 3;
   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
   //putBuyerToQueue(3, *buyer);
   if (third_.empty())
   {
     putBuyerToQueue(3, *buyer);
     buyer->setPos(buyer->x() + 560, buyer->y() + 435);
     scene()->addItem(buyer);
     cashIter_3 = third_.begin();
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
 if (first_.size() != 0)
 {
   cashes_[0] -> setStatus(1);
   cashes_[0]->pixmap = ":/img/robot_cashier.png";
 }
 if (second_.size() != 0)
 {
   cashes_[1] -> setStatus(1);
   cashes_[1]->pixmap = ":/img/robot_cashier.png";
 }
 if (third_.size() != 0)
 {
   cashes_[2] -> setStatus(1);
   cashes_[2]->pixmap = ":/img/robot_cashier.png";
 }
 QTime dieTime= QTime::currentTime().addSecs(5);
 while (QTime::currentTime() < dieTime)
     QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

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
void Game::createCashes()
{
  CashRegister * cashregister_1 = new CashRegister();
  cashes_.push_back(cashregister_1);
  cashregister_1 -> setPos(cashregister_1->x() + 95,cashregister_1->y() + 400);
  scene()->addItem(cashregister_1);

  CashRegister * cashregister_2 = new CashRegister();
  cashes_.push_back(cashregister_2);
  cashregister_2 -> setPos(cashregister_2->x() + 370,cashregister_2->y() + 400);
  scene()->addItem(cashregister_2);

  CashRegister * cashregister_3 = new CashRegister();
  cashes_.push_back(cashregister_3);
  cashregister_3 -> setPos(cashregister_3->x() + 630,cashregister_3->y() + 400);
  scene()->addItem(cashregister_3);

  //cashIterator = cashes_.begin();
}
void Game::Play()
{
  scene()->clear();
  //setCursor(Qt::BlankCursor);
  //Queue::createBuyers();
  createCashes();
  cashes_[0] -> setFocus();

  QTimer *pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &Game::createBuyers);
    pTimer->start(500);

  //if (cashIter_1 == first_.begin())

}

//int Game::timer(int time)
//{
//  for (int i = 0; i < time; i++)
//    return i;
//}

//changeCash(3);




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


