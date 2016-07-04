/*  Copyright 2016, Viacheslav
 */

#include "task1.h"

#include <iostream>

#include "task1_internal.h"

namespace task1 {

/*
 * Решение задачи 1.
 * Внутренние фунции, используемые при решении задачи, вынесены в
 * отдельный модуль task1::task1_internal для удобства тестирования
 * с помощью google test
 */
namespace impl = task1::task1_internal;


/*
 * Задача 1
 * В заданном облаке точек на плоскости (каждая точка определяется двумя
 * целочисленными координатами: x, y) найти 3 любые точки, которые
 * образуют невырожденный треугольник (имеющий ненулевую площадь).
 * Все остальные точки должны находиться строго за пределами этого
 * треугольника. Заданные точки не принадлежат одной прямой. Никакие две
 * точки не находятся в одной позиции. Количество точек может быть
 * от 3 до 1е5. Каждая из заданных координат может находиться в пределах
 * от -1е9 до 1е9.
 * Метод Solve() принимает облако точек, заданных в плоскости,
 * и возвращает 3 индекса точек из заданного облака, удовлетворяющих
 * решению поставленной задачи
 *
*   Входные данные: points - облако точек
*   Выходные данные: массив из трех найденных индексов
*
*   Алгоритм:
*  Положим начальную точку (idx_0=0) в облаке вершиной искомого
*  треугольника. Далее эта вершина менятся не будет.
*  Допустим, что следующая точка так же является вершиной.
*  Проверяем все оставшиеся точки:
*  Если точка принадлежит одной из сторон треугольника (коллинеарна
*  стороне и расположена между вершинами) - заменяем  одну из вершин
*  этой стороны.
*  Если треугольник еще не определен,
*  определяем его.
* Если точка находится внутри треугольника - она становится новой вершиной.
*
 */

std::array<std::size_t, 3> Solve(const std::vector<Point2> &points) {
  //индексы точек, образующих возвращаемый треугольник
  constexpr std::size_t idx_0 = 0;
  std::size_t idx_1 = 1;
  std::size_t idx_2 = 0;  // 0 - признак того, что вершина еще неопределена

  for (std::size_t i = 2; i < points.size(); ++i) {
    impl::TurnEnum turn_1 = impl::TurnPredicate(points[i],
                                                points[idx_0], points[idx_1]);
    if (turn_1 == impl::TurnEnum::kCollinear) {
      if (impl::IsMiddlePointBetween(points[idx_0], points[i], points[idx_1]))
        idx_1 = i;
      continue;
    } else {  //  если треугольник еще не определен, определяем его
      if (idx_2 == 0) {
        idx_2 = i;
        continue;
      }
    }
    impl::TurnEnum turn_2 = impl::TurnPredicate(points[i],
                                                points[idx_1], points[idx_2]);
    if (turn_2 == impl::TurnEnum::kCollinear) {
      if (impl::IsMiddlePointBetween(points[idx_1], points[i], points[idx_2]))
        idx_2 = i;
      continue;
    }
    impl::TurnEnum turn_3 = impl::TurnPredicate(points[i],
                                                points[idx_2], points[idx_0]);
    if (turn_3 == impl::TurnEnum::kCollinear) {
      if (impl::IsMiddlePointBetween(points[idx_0], points[i], points[idx_2]))
        idx_2 = i;
      continue;
    }
    //Если у точки одинаковое вращение относительно каждой стороны
    // треугольника, значит точка находится внутри треугольника, и
    // необходимо перенести вершину треугольника
    if ((turn_1 == turn_2) && (turn_2 == turn_3))
      idx_2 = i;
  }
  return {idx_0, idx_1, idx_2};
}

}  // namespace task1
