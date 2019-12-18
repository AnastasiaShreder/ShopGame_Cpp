#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "health.h"
#include "score.h"
#include "cashregister.h"
#include <list>
#include "buyer.h"
#include "iterator"
#include <QList>
#include "queue.h"
#include <QGraphicsScene>
#include <cstdlib>


//extern QGraphicsScene * scene;

class Game: public QGraphicsView
{
  Q_OBJECT
public:
    Game(QWidget * parent=0);
    void Play();

    //QGraphicsScene * scene;
    //Health * health;
    //Score * score;
    //CashRegister * cashregister;
    //Buyer * buyer;
    int healthPoints;
    void putBuyerToQueue(int cashNumber, Buyer &buyer);
    Buyer getElementFromQueue(std::list<Buyer> list);
    void createBuyers();
    void createCashes();
    void changeStatus(int statusNumber);
    int timer(int time);
    //void mousePressEvent(QMouseEvent *event);
public slots:
    //void createBuyers();
    void gameOver();
    //void changeCash(int status);
private:

    std::list<Buyer *> first_;
    std::list<Buyer *> second_;
    std::list<Buyer *> third_;

    std::vector<Health *> healths_;
    //std::vector<Health>::iterator healthIterator;
    std::list<CashRegister *> cashes_;
    std::list<CashRegister *>::iterator cashIterator;
//    //QList<Buyer> buyers_;
    std::list<Buyer *>::iterator cashIter_1;
    std::list<Buyer *>::iterator cashIter_2;
    std::list<Buyer *>::iterator cashIter_3;


};

#endif // GAME_H
