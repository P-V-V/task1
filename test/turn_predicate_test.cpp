/*  Copyright 2016, Viacheslav
 *
 * Тестирование функции task1::task1_internal::TurnPredicate
 * Необходимо протестировать 3 случая расположения точки:
 * слева, справа и коллениарна.
 * Отдельно тестируем предельные значения координат.
 * Исключаем из рассмотрения крайние случаи, т.к.
 * по условию задачи точки не могут совпадать.
 */

#include "gtest/gtest.h"
#include "task1_internal.h"

namespace impl = task1::task1_internal;

TEST(Task1_TurnPredicate, LeftTurn) {
EXPECT_EQ(impl::TurnPredicate({1, 1}, {1, 2}, {0, 0}),
    impl::TurnEnum::kLeftTurn);
}

TEST(Task1_TurnPredicate,  Collinear) {
EXPECT_EQ(impl::TurnPredicate({1, 1}, {1, 2}, {1, 0}),
    impl::TurnEnum::kCollinear);
}

TEST(Task1_TurnPredicate,  RightTurn) {
EXPECT_EQ(impl::TurnPredicate({1, 1}, {2, 2}, {3, 0}),
    impl::TurnEnum::kRightTurn);
}


TEST(Task1_TurnPredicate,  BigValuesRight) {
  EXPECT_EQ(impl::TurnPredicate({-1000000000l, -1000000000l},
                                {1000000000l, 1000000000l}, {1, 0}),
            impl::TurnEnum::kRightTurn);
}

TEST(Task1_TurnPredicate,  BigValuesCollinear) {
  EXPECT_EQ(impl::TurnPredicate({-1000000000l, -1000000000l},
                                {1000000000l, 1000000000l},
                                {0, 0}),
            impl::TurnEnum::kCollinear);
}

TEST(Task1_TurnPredicate,  BigValuesLeft) {
  EXPECT_EQ(impl::TurnPredicate({-2, 0},
                                {-1000000000l, -1000000000l},
                                {1000000000l, 1000000000l}),
            impl::TurnEnum::kLeftTurn);
}
