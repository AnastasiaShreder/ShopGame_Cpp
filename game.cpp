#include <QFont>
#include "game.h"
#include "score.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

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
  health = new Health();
  //healths_.push_back(health);
  health->setPos(health->x() + 15,health->y() + 15);
  scene->addItem(health);

  health = new Health();
//  healths_.push_back(health);
  health->setPos(health->x() + 50,health->y() + 15);
  scene->addItem(health);

  health = new Health();
//  healths_.push_back(health);
  health->setPos(health->x() + 85,health->y() + 15);
  scene->addItem(health);
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
