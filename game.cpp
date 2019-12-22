#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QTime>
#include <QCoreApplication>
#include <QDebug>
#include <QFont>
#include "game.h"
#include "score.h"
#include "cashregister.h"

Game::Game()
{
  QGraphicsScene * scene = new QGraphicsScene();
  setScene(scene);
  scene->setSceneRect(0,0,800,600);
  setBackgroundBrush(QBrush(QImage(":/img/scene.png")));
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800,600);
  setCursor(Qt::PointingHandCursor);

  QMediaPlayer * music = new QMediaPlayer();
  music->setMedia(QUrl("qrc:/snd/background.mp3"));
  music->play();
}

void Game::increaseScore()
{
  score -> increase();
}

void Game::replaceBuyers(std::list<Buyer*> &list, std::list<Buyer*>::iterator &iter, unsigned int i) //i - index of cash
{
  setFocusPolicy(Qt::StrongFocus);
  cashes_[i] -> setFocus();

  if ((cashes_[i] -> getStatus()) == 1) //if cashier want to begin service
  {
    cashes_[i] -> setStatus(4); //then set cashier in default mode

    QTime dieTime= QTime::currentTime().addSecs(5);  //set time of service
    while (QTime::currentTime() < dieTime)
      {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
      }
    cashes_[i] -> setStatus(3); //after 5 seconds cashier ready to finish service
  }
  else if ((cashes_[i] -> getStatus()) == 3) //if cashier ready to finish service
  {
    if (list.size() == 3) //if there are 3 buyers in queue
    {
      iter = ++(list.begin());
      scene() -> removeItem(*(list.begin()));
      list.pop_front();
      if (i == 0) // if the queue in the first cash
      {
        (*iter)->setPos(28, 435);
        ++iter;
        (*iter)->setPos(60, 340);
      }
      if (i == 1) // if the queue in the second cash
      {
        (*iter)->setPos(300, 435);
        ++iter;
        (*iter)->setPos(330, 340);
      }
      if (i == 2) // if the queue in the third cash
      {
        (*iter)->setPos(560, 435);
        ++iter;
        (*iter)->setPos(590, 340);
      }
      cashes_[i] -> setStatus(1); //cashier want to begin service next buyer
    }
    else if (list.size() == 2)//if there are 2 buyers in queue
    {
      iter = ++(list.begin());
      scene() -> removeItem(*list.begin());

      if (i == 0)// if the queue in the first cash
      {
        (*iter)->setPos(28, 435);
      }
      if (i == 1) // if the queue in the second cash
      {
        (*iter)->setPos(300, 435);
      }
      if (i == 2) // if the queue in the third cash
      {
        (*iter)->setPos(560, 435);
      }
      list.pop_front();
      cashes_[i] -> setStatus(1); //cashier want to begin service next buyer
    }
    else if (list.size() == 1)//if there are 1 buyer in queue
    {
      scene() -> removeItem(*(list.begin()));
      list.pop_front();
      cashes_[i] -> setStatus(4);//set cashier in default mode
    }
    increaseScore();
  }
}

void Game::keyPressEvent(QKeyEvent *event)
{
  qDebug()<<event->key();
  switch (event->key())
  {
    case (Qt::Key_1):
    {
      qDebug() << "Key_1";
      replaceBuyers(first_, buyerIter_1, 0); // the first cash
      break;
    }
    case (Qt::Key_2):
    {
      qDebug() << "Key_2";
      replaceBuyers(second_, buyerIter_2, 1);//the second cash
      break;
    }
    case (Qt::Key_3):
    {
      qDebug() << "Key_3";
      replaceBuyers(third_, buyerIter_3, 2);//the third cash
      break;
    }
  }
}

void Game::createBuyers()
{
 int cashNumber = rand() % 3 + 1;
 switch (cashNumber)
 {
  case 1:
  {
    int bType = rand() % 4;
    Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
    if (first_.empty()) // if there are no buyers at first queue
    {
      putBuyerToQueue(1, *buyer);
      buyer->setPos(buyer->x() + 28, buyer->y() + 435);
      scene()->addItem(buyer);
      cashes_[0] ->setStatus(1);
      buyerIter_1 = first_.begin();
    }
    else if (first_.size() == 1) // if there is 1 buyer at first queue
    {
      putBuyerToQueue(1, *buyer);
      buyer->setPos(buyer->x() + 60, buyer->y() + 340);
      scene()->addItem(buyer);
    }
    else if (first_.size() == 2) // if there are 2 buyers at first queue
    {
      putBuyerToQueue(1, *buyer);
      buyer->setPos(buyer->x() + 88, buyer->y() + 245);
      scene()->addItem(buyer);
    }
    else if (first_.size() == 3) // if there are 3 buyers at first queue
    {
      delete buyer;
      break;
    }
    break;
   }
  case 2:
  {
    int bType = rand() % 4;
    Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
    if (second_.empty())
    {
      putBuyerToQueue(2, *buyer);
      buyer->setPos(buyer->x() + 300, buyer->y() + 435);
      scene()->addItem(buyer);
      cashes_[1] ->setStatus(1);
      buyerIter_2 = second_.begin();
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
      delete buyer;
      break;
    }
    break;
  }
  case 3:
  {
    int bType = rand() % 4;
    Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
    if (third_.empty())
    {
      putBuyerToQueue(3, *buyer);
      buyer->setPos(buyer->x() + 560, buyer->y() + 435);
      scene()->addItem(buyer);
      cashes_[2] ->setStatus(1);
      buyerIter_3 = third_.begin();
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
      delete buyer;
      break;
    }
    break;
  }
 }
 if ((first_.size() == 3) && (second_.size() == 3) && (third_.size() == 3))
   this->close();
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
}

void Game::Play()
{
  scene()->clear();
  createCashes();

  score = new Score();
  scene()->addItem(score);

  QTimer *pTimer = new QTimer(this);
  connect(pTimer, &QTimer::timeout, this, &Game::createBuyers);
  pTimer->start(2000);  //buyers will be created every 2 seconds
}
