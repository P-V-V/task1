/*  Copyright 2016, Viacheslav
 *
 * функции, используемые при решении задачи 1 и  вынесенные  в отдельный
 * модуль для удобства тестирования.
 */

#include "task1.h"
#include "task1_internal.h"

#include <algorithm>

namespace task1 {
namespace task1_internal {

/*
 *  Возвращает вращение точки  c относительно вектора (a,  b)
 *  Вращение определяется через знак косого произведения векторов
 */

TurnEnum TurnPredicate(const task1::Point2 &a,
                       const task1::Point2 &b,
                       const task1::Point2 &c) {
  const int64_t cross_product =
      (static_cast<int64_t>(c.x - a.x)) * (static_cast<int64_t>(b.y - a.y))
       - (static_cast<int64_t>(b.x - a.x)) * (static_cast<int64_t>(c.y - a.y));
  if (cross_product < 0)
    return TurnEnum::kLeftTurn;
  else if (cross_product > 0)
    return TurnEnum::kRightTurn;
  else
    return TurnEnum::kCollinear;
}


/*
 * Возвращает true когда точка  p1 расположена между точками p0 и p2
 * Точки p1,  p2,  p3 находятся на одной прямой.
 */
bool IsMiddlePointBetween(const task1::Point2 &p0,
                          const task1::Point2 &p1,
                          const task1::Point2 &p2) {
  return ((std::min(p0.x, p2.x) <= p1.x) && (p1.x <= std::max(p0.x, p2.x))
      && (std::min(p0.y, p2.y) <= p1.y) && (p1.y <= std::max(p0.y, p2.y)));
}

}  //  namespace task1_internal
}  //  namespace task1
