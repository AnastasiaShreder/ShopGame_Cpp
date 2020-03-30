#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <list>
#include <iterator>
#include <cstdlib>
#include "cashregister.h"
#include "buyer.h"
#include "score.h"

class Game: public QGraphicsView
{
  Q_OBJECT
  public:
    Game();
    void Play();
    void putBuyerToQueue(int cashNumber, Buyer &buyer);
    void createBuyers();
    void createCashes();
    void changeStatus(int statusNumber);
    void increaseScore();
    void replaceBuyers(std::list<Buyer*> &list, std::list<Buyer*>::iterator &iter, unsigned int i);
  protected:
    void keyPressEvent(QKeyEvent *event) override;
  private:
    Score * score = nullptr;
    std::list<Buyer *> first_;  //list buyers from first cash
    std::list<Buyer *> second_; //list buyers from second cash
    std::list<Buyer *> third_;  //list buyers from third cash
    std::vector<CashRegister *> cashes_;
    std::vector<CashRegister *>::iterator cashIterator;
    std::list<Buyer *>::iterator buyerIter_1; //iterator for first_
    std::list<Buyer *>::iterator buyerIter_2; //iterator for second_
    std::list<Buyer *>::iterator buyerIter_3; //iterator for third_
};

#endif // GAME_H
