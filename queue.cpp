#include "queue.h"
#include "game.h"
#include <QGraphicsScene>

Queue::Queue()
{
}

void Queue::putBuyerToQueue(Queue &queue, Buyer &buyer, CashNumber number)
{
  switch (number)
  {
    case CashNumber::FIRST:
      first_.push_back(buyer);
      break;

    case CashNumber::SECOND:
      second_.push_back(buyer);
      break;

    case CashNumber::THIRD:
      third_.push_back(buyer);
      break;
  }
}

//void Queue::createBuyers()
//{
// int cashNumber = 1 + (rand() % 3);
// int bType = 1 + (rand() % 3);
// Queue queue;
// switch (cashNumber)
// {
//  case 1:
//   {
//   int bType = 1 + (rand() % 3);
//   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
//   putBuyerToQueue(queue, *buyer, CashNumber::FIRST);
//   if (first_.size() == 0)
//   {
//     buyer->setPos(buyer->x() + 28, buyer->y() + 435);
//     scene()->addItem(buyer);
//   }
//   else if (first_.size() == 1)
//   {
//     buyer->setPos(buyer->x() + 28, buyer->y() + 435);
//     scene()->addItem(buyer);
//   }
//   else if (first_.size() == 2)
//   {

//   }
//   }
//  case 2:
//   {
//   int bType = 1 + (rand() % 3);
//   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
//   putBuyerToQueue(*buyer, CashNumber::SECOND);
//   buyer->setPos(buyer->x() + 60, buyer->y() + 340);
//   break;
//   }
//  case 3:
// {
//   int bType = 1 + (rand() % 3);
//   Buyer * buyer = new Buyer(static_cast<BuyerType>(bType));
//   putBuyerToQueue(*buyer, CashNumber::THIRD);
//   buyer->setPos(buyer->x() + 60, buyer->y() + 340);
// }
// }

// //putBuyerToQueue(const Buyer &buyer, CashNumber number)

// Buyer * buyer1 = new Buyer(static_cast<BuyerType>(bType));
// buyer1 -> setPos(buyer1->x() + 28, buyer1->y() + 435);
// scene()->addItem(buyer1);
//}

bool Queue::empty() const
{
  return first_.empty() && second_.empty() && third_.empty();
}
