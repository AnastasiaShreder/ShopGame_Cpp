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
#include "healthpoints.h"


Game::Game(QWidget *parent){
// create the scene
  scene = new QGraphicsScene();
  scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
  setBackgroundBrush(QBrush(QImage(":/img/scene.png")));

// make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
// it can be used to visualize scenes)
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFixedSize(800,600);
//set health
  Health * health_1 = new Health();
  healths_.push_back(health_1);
  health_1->setPos(health_1->x() + 15,health_1->y() + 15);
  scene->addItem(health_1);

  Health * health_2 = new Health();
  healths_.push_back(health_2);
  health_2->setPos(health_2->x() + 50,health_2->y() + 15);
  scene->addItem(health_2);

  Health * health_3 = new Health();
  healths_.push_back(health_3);
  health_3->setPos(health_3->x() + 85,health_3->y() + 15);
  scene->addItem(health_3);

  scene->removeItem(healths_.back());
  healths_.pop_back();
 //decrease(healths_);
  //scene -> removeItem(health);
//set score
  score = new Score();
  score->setPos(score->x() + 650, score->y() + 10);
  scene->addItem(score);
// play background music
  QMediaPlayer * music = new QMediaPlayer();
  music->setMedia(QUrl("qrc:/snd/background.mp3"));
  music->play();
// create the cashiers
  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 95,cashregister->y() + 400);
  scene->addItem(cashregister);

  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 370,cashregister->y() + 400);
  scene->addItem(cashregister);

  cashregister = new CashRegister();
  cashregister -> setPos(cashregister->x() + 630,cashregister->y() + 400);
  scene->addItem(cashregister);

// create the buyers
  buyer = new Buyer();
  buyer -> setPos(buyer->x() + 35,buyer->y() + 400);
  scene->addItem(buyer);

}
