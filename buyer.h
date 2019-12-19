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

class Buyer: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Buyer(BuyerType buyerType, QGraphicsItem * parent = nullptr);
    ~Buyer();
//public slots:
    //void move();
    void setType(BuyerType buyerType);
private:
    BuyerType buyerType_;
    int points;
    size_t timeWaiting;
public slots:
   void move(int pointX, int pointY);
};

#endif // BUYER_H
