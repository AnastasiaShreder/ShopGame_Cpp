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
    Game();
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
    void createHealths();
    void changeStatus(int statusNumber);
    void increaseScore();
    void replaceBuyers(std::list<Buyer*> &list, std::list<Buyer*>::iterator &iter, unsigned int i);
protected:
    void keyPressEvent(QKeyEvent *event) override;
public slots:
    //void createBuyers();
    void gameOver();
    //void decreaseHealth();
    //void increaseScore();
    //void changeCash(int status);
private:
    Score * score = nullptr;
    std::list<Buyer *> first_;
    std::list<Buyer *> second_;
    std::list<Buyer *> third_;

    std::vector<Health *> healths_;
    //std::vector<Health>::iterator healthIterator;
    std::vector<CashRegister *> cashes_;
    std::vector<CashRegister *>::iterator cashIterator;
//    //QList<Buyer> buyers_;
    std::list<Buyer *>::iterator buyerIter_1;
    std::list<Buyer *>::iterator buyerIter_2;
    std::list<Buyer *>::iterator buyerIter_3;


};

#endif // GAME_H
