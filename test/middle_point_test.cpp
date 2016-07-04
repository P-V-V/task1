/*  Copyright 2016, Viacheslav
 *
 * Тестирование функции  task1::task1_internal::IsMiddlePointBetween
 *
 */

#include "gtest/gtest.h"

#include "task1_internal.h"

namespace impl = task1::task1_internal;


/*
 * Исключаем из рассмотрения крайние случаи, т.к.
 * по условию задачи, точки не могут совпадать.
 *
 */

/*
 *  Точка на вертикальном отрезке
 */
TEST(Task1_MiddlePoint, BetweenVertical) {
  EXPECT_TRUE(impl::IsMiddlePointBetween({1, 1}, {1, 2}, {1, 3}));
}

/*
 * Точка выше вертикального отрезка
 */
TEST(Task1_MiddlePoint, UpperSideVertical) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {1, 5}, {1, 1}));
}

/*
 * Точка ниже вертикального отрезка
 */
TEST(Task1_MiddlePoint, LowerSideVertical) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {1, 0}, {1, 3}));
}

/*
 * Точка на горизонтальном отрезке
 */
TEST(Task1_MiddlePoint, BetweenHorizontal) {
  EXPECT_TRUE(impl::IsMiddlePointBetween({1, 1}, {2, 1}, {3, 1}));
}

/*
 * Точка слева от горизонтального отрезка
 */
TEST(Task1_MiddlePoint, LeftSideHorizontal) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {0, 1}, {2, 1}));
}

/*
 * Точка справа от горизонтального отрезка
 */
TEST(Task1_MiddlePoint, RightSideHorizontal) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {5, 1}, {2, 1}));
}

/*
 * Точка на отрезке
 */
TEST(Task1_MiddlePoint, Between) {
  EXPECT_TRUE(impl::IsMiddlePointBetween({1, 1}, {2, 2}, {3, 3}));
}

/*
 * Точка слева от отрезка
 */
TEST(Task1_MiddlePoint, LeftSide) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {0, 0}, {3, 3}));
}

/*
 * Точка справа от  отрезка
 */
TEST(Task1_MiddlePoint, RightSide) {
  EXPECT_FALSE(impl::IsMiddlePointBetween({1, 1}, {5, 5}, {3, 3}));
}
