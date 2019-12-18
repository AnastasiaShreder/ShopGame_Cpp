#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <list>

class CashRegister:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CashRegister(QGraphicsItem * parent = nullptr);
    void changeStatus(int statusNumber);
private:
    QMediaPlayer * cashsound;
    QMediaPlayer * clicksound;
};

#endif // CASHREGISTER_H
