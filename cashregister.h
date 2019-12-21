#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <list>
#include <QWidget>

class CashRegister:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CashRegister(QGraphicsItem * parent = nullptr);
    //void mousePressEvent(QMouseEvent *event);
    int getStatus();
    std::string pixmap;
public slots:
    void setStatus(int statusNumber);
private:
    QMediaPlayer * cashsound;
    QMediaPlayer * clicksound;
};

#endif // CASHREGISTER_H
