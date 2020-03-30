#ifndef BUYER_H
#define BUYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

enum BuyerType
{
    type1, type2, type3, type4
};

//type 1 - ":/img/buyer_1.png"
//type 2 - ":/img/buyer_2.png"
//type 3 - ":/img/buyer_3.png"
//type 4 - ":/img/buyer_4.png"

class Buyer: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
  public:
    Buyer(BuyerType buyerType, QGraphicsItem * parent = nullptr);
    ~Buyer();
    void setType(BuyerType buyerType);
  private:
    BuyerType buyerType_;
};

#endif
