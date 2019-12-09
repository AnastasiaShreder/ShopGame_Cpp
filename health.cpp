#include "health.h"
#include <QGraphicsScene>
#include "game.h"

Health::Health(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw graphics
    setPixmap(QPixmap(":/img/element_red_square.png"));
}
