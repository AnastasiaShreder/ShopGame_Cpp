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
private:
    int points;
};

#endif // BUYER_H
