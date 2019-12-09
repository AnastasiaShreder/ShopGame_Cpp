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

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Health * health;
    Score * score;
    CashRegister * cashregister;
    Buyer * buyer;
    int healthPoints;
private:
    std::list<Health> healths_;
    //std::list<Health>::iterator healthIterator;
    QList<CashRegister> cashes_;
    QList<CashRegister>::iterator cashIterator;
    QList<Buyer> buyers_;
    QList<Buyer>::iterator buyerIterator;


};

#endif // GAME_H
