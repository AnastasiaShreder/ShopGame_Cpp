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
public slots:
    //void createBuyers();
    void gameOver();
private:

    std::list<Buyer *> first_;
    std::list<Buyer *> second_;
    std::list<Buyer *> third_;

    std::vector<Health *> healths_;
    //std::vector<Health>::iterator healthIterator;
    QList<CashRegister> cashes_;
    QList<CashRegister>::iterator cashIterator;
    //QList<Buyer> buyers_;
    //QList<Buyer>::iterator buyerIterator;


};

#endif // GAME_H
