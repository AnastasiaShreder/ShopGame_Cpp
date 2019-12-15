#include "buyer.h"
#include <ctime>

Buyer::Buyer(BuyerType buyerType, QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
  setType(buyerType);
}


void Buyer::setType(BuyerType buyerType)
  {
    buyerType_ = buyerType;
    //int randomType = rand() % 3 + 1;
    switch (buyerType_)
     {
       case BuyerType::type1:
       {
           QPixmap oPixmap(":/img/buyer_1.png");
           setPixmap(oPixmap);
           size_t timeWaiting;
           int points = 25;
           break;
       }
       case BuyerType::type2:
    {
        QPixmap oPixmap(":/img/buyer_2.png");
        setPixmap(oPixmap);
        size_t timeWaiting;
        int points = 15;
        break;
    }
    case BuyerType::type3:
    {
        QPixmap oPixmap(":/img/buyer_3.png");
        setPixmap(oPixmap);
        size_t timeWaiting;
        int points = 20;
        break;
    }
    case BuyerType::type4:
    {
        QPixmap oPixmap(":/img/buyer_4.png");
        setPixmap(oPixmap);
        size_t timeWaiting;
        int points = 10;
        break;
    }
  }

}

//void Buyer::setType()
//{
//  int randomType = rand() % 3;
//  switch (randomType)
//   {
//     case 0:
//     {
//         QPixmap oPixmap(":/img/buyer_1.png");
//         setPixmap(oPixmap);
//         size_t time;
//         int points = 25;
//         break;
//     }
//     case 1:
//     {
//         QPixmap oPixmap(":/img/buyer_2.png");
//         setPixmap(oPixmap);
//         size_t time;
//         int points = 15;
//         break;
//     }
//     case 2:
//     {
//         QPixmap oPixmap(":/img/buyer_3.png");
//         setPixmap(oPixmap);
//         size_t time;
//         int points = 20;
//         break;
//     }
//     case 3:
//     {
//         QPixmap oPixmap(":/img/buyer_4.png");
//         setPixmap(oPixmap);
//         size_t time;
//         int points = 10;
//         break;
//     }

//   }
//}
