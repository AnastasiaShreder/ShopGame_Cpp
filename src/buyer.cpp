#include "buyer.h"
#include <ctime>

Buyer::Buyer(BuyerType buyerType, QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
  setType(buyerType);
}


void Buyer::setType(BuyerType buyerType)
  {
    buyerType_ = buyerType;
    switch (buyerType_)
     {
       case BuyerType::type1:
       {
         QPixmap oPixmap(":/img/buyer_1.png");
         setPixmap(oPixmap);
         break;
       }
       case BuyerType::type2:
       {
         QPixmap oPixmap(":/img/buyer_2.png");
         setPixmap(oPixmap);
         break;
       }
       case BuyerType::type3:
       {
         QPixmap oPixmap(":/img/buyer_3.png");
         setPixmap(oPixmap);
         break;
       }
       case BuyerType::type4:
       {
         QPixmap oPixmap(":/img/buyer_4.png");
         setPixmap(oPixmap);
         break;
       }
    }
  }

Buyer::~Buyer()
{
}


