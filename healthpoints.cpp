#include "healthpoints.h"
#include "health.h"
#include "game.h"

HealthPoints::HealthPoints()
{
  Health * health_1 = new Health();
  healths_.emplace_back(health_1);
  health_1->setPos(health_1->x() + 15,health_1->y() + 15);
  scene->addItem(health_1);

  Health * health_2 = new Health();
  healths_.emplace_back(health_2);
  health_2->setPos(health_2->x() + 50,health_2->y() + 15);
  scene->addItem(health_2);

  Health * health_3 = new Health();
  healths_.emplace_back(health_3);
  health_3->setPos(health_3->x() + 85,health_3->y() + 15);
  scene->addItem(health_3);


}

void HealthPoints::decrease(std::vector<Health> & vector)
{
  //Health &currentHeart = vector.back();
  scene->removeItem(&vector.back());
  vector.pop_back();
}
