#ifndef BUYER_H
#define BUYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Buyer: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Buyer(QGraphicsItem * parent=0);
//public slots:
    //void move();
    void setType();
private:
    int points;
    size_t timeWaiting;
};

#endif // BUYER_H
