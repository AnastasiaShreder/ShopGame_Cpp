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
    int getStatus();
    std::string pixmap; // pixmap show the status of cashregister
  public slots:
    void setStatus(int statusNumber);
};

#endif // CASHREGISTER_H
