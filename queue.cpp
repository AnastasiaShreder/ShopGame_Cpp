#include "queue.h"

Queue::Queue()
{

}

void Queue::putBuyerToQueue(const Buyer &buyer, CashNumber number)
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

bool QueueWithPriority::empty() const
{
  return first_.empty() && second_.empty() && third_.empty();
}
