#ifndef QUEUE_H
#define QUEUE_H

#include <list>
#include "buyer.h"


  typedef enum
  {
    FIRST,
    SECOND,
    THIRD
  } CashNumber;

class Queue:public QObject
  {
  Q_OBJECT
  public:
    Queue();
    //void createBuyers();
    void putBuyerToQueue(Queue &queue, Buyer &buyer, CashNumber number);
    Buyer getElementFromQueue();
    bool empty() const;

//   typedef std::pair<int, int> position;
 private:
//    std::list<Buyer> first_;
//    std::list<Buyer> second_;
//    std::list<Buyer> third_;
  };

#endif
///////////////////////////////////////////////////////////////
/*
 * Идея: создать три листа позиций. Позиция = координаты x и y, куда должен встать покупатель. Так как позиции константные (покупатели визуально
 * встают на одни и те же места), то можем проинициализировать все позиции, заполнив листы.*/
