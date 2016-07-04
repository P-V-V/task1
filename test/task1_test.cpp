/*  Copyright 2016, Viacheslav
 *
 * Тесты решения Задачи 1.
 * Поскольку правильных ответов может быть много, из непрохождения теста
 * не следует ошибка в решении. Возможно для данного набора входных данных
 * выдается другое правильное решение.
 * Для проверки решения используется вспомогательная функция MatchIndexes
 * которая возврещает ::testing::AssertionSuccess в случае, когда наборы
 * индексов эквиваленты.
 * Функция MatchIndexes тестируется отдельно в этом же модуле.
 */

#include "gtest/gtest.h"
#include "task1.h"



/*
 * Сравнивает два набора индексов вершин. Каждый из expected
 * индексов должен содержаться в actual
 *
 * Возвращает ::testing::AssertionSuccess() при эквивалентном наборе индексов
 */
::testing::AssertionResult MatchIndexes(
    const std::array<std::size_t, 3> &actual,
    const std::array<std::size_t, 3> &expected) {
  for (const auto &it : expected) {
    if (std::find(actual.begin(), actual.end(), it) == actual.end())
      return ::testing::AssertionFailure() << " expected index "
          << it << " not found";
  }
  return ::testing::AssertionSuccess() << " indexes matched";
}

/*
 * В MatchIndexes_test собраны тесты для MatchIndexes.
 */
TEST(MatchIndexes_test, Trivial) {
  EXPECT_TRUE(MatchIndexes({1, 5, 0}, {1, 5, 0}));
  EXPECT_TRUE(MatchIndexes({1, 0, 5}, {1, 5, 0}));
  EXPECT_FALSE(MatchIndexes({1, 5, 3}, {1, 2, 3}));
  EXPECT_FALSE(MatchIndexes({1, 2, 3}, {1, 5, 3}));
}

/*
 * Несколько простейших случаев
 */
TEST(Task1_test, Trivial) {
  EXPECT_TRUE(MatchIndexes(task1::Solve({{1, 2}, {3, 4}, {5, 7}}),
                           {0, 1, 2}));
  EXPECT_TRUE(MatchIndexes(task1::Solve({{0, 0}, {5, 5}, {5, 0}, {10, 1}}),
                           {0, 1, 2}));
  EXPECT_TRUE(MatchIndexes(task1::Solve({{0, 0}, {5, 5}, {5, 0}, {1, 1}}),
                           {0, 2, 3}));
  EXPECT_TRUE(MatchIndexes(task1::Solve({{1, 0}, {-1, 0}, {0, -3}, {0, 0}}),
                           {0, 3, 2}));
}

/*
 * Варианты с коллинеарными точками
 */
TEST(Task1_test, PointOnBound) {
  EXPECT_TRUE(MatchIndexes(task1::Solve(
      {{1, 1}, {2, 1}, {3, 1}, {2, 3}, {3, 3}}), {0, 1, 3}));
  EXPECT_TRUE(MatchIndexes(task1::Solve(
      {{0, 0}, {-1, 0}, {1, 0}, {4, 1}}), {0, 1, 3}));
  EXPECT_TRUE(MatchIndexes(task1::Solve(
      {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 1}}), {0, 1, 4}));
  EXPECT_TRUE(MatchIndexes(task1::Solve(
      {{1, 0}, {3, 0}, {2, 0}, {4, 0}, {5, 1}}), {0, 2, 4}));
}
