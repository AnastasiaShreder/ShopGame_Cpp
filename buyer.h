#ifndef BUYER_H
#define BUYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

enum BuyerType
{
    type1, type2, type3, type4
};

class Buyer: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Buyer(BuyerType buyerType, QGraphicsItem * parent = nullptr);
//public slots:
    //void move();
    void setType(BuyerType buyerType);
private:
    BuyerType buyerType_;
    int points;
    size_t timeWaiting;
};

#endif // BUYER_H
