#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Health: public QObject,public QGraphicsPixmapItem {
    Q_OBJECT
public:
  Health(QGraphicsItem * parent=0);
};

#endif
