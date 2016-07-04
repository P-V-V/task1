/*  Copyright 2016, Viacheslav
  */

#ifndef SRC_TASK1_INTERNAL_H_
#define SRC_TASK1_INTERNAL_H_

/*
 * функции, используемые при решении задачи 1 и  вынесенные  в отдельный
 * модуль для удобства тестирования.
 */

#include "task1.h"

namespace task1 {
namespace task1_internal {

/*
 * Вращение на плоскости
 */
enum class TurnEnum: int {
  kLeftTurn = -1,
  kCollinear = 0,
  kRightTurn = 1
};


/*
 * Возвращает true когда точка  p1 расположена между точками p0 и p2
 * Точки p1,  p2,  p3 находятся на одной прямой.
 */
bool IsMiddlePointBetween(const task1::Point2 &p0,
                          const task1::Point2 &p1,
                          const task1::Point2 &p2);


/*
 *  Возвращает вращение точки  c относительно вектора (a,  b)
 *  Вращение определяется через знак косого произведения векторов
 */
TurnEnum TurnPredicate(const task1::Point2 &a, const task1::Point2 &b,
                       const task1::Point2 &c);

}  //  namespace task1_internal
}  //  namespace task1
#endif  //  SRC_TASK1_INTERNAL_H_
