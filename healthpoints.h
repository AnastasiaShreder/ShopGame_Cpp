#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H

#include <vector>
#include <iterator>
#include "health.h"
//#include "game.h"

extern std::vector<Health> healths_;
class HealthPoints
{
public:
  HealthPoints();
  void decrease(std::vector<Health> &);

};

#endif // HEALTHPOINTS_H
