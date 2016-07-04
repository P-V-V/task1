# Task1

   Проект представляет собой решение геометрической задачи на С++11
   с использованием google test.
   Условие задачи см ниже.
   Алгоритм решения см. в task1.cpp

   Версии:  cmake 3.5.1; gcc 5.2.1; google-test 1.7.


   Пример запуска тестов:
   
```shell
   git clone https://github.com/P-V-V/task1.git
   cd task1
   ./run_all_tests.sh
```



######   Задача 1

    В заданном облаке точек на плоскости (каждая точка определяется двумя
    целочисленными координатами: x, y) найти 3 любые точки, которые
    образуют невырожденный треугольник (имеющий ненулевую площадь).
    Все остальные точки должны находиться строго за пределами этого
    треугольника. Заданные точки не принадлежат одной прямой. Никакие две
    точки не находятся в одной позиции. Количество точек может быть
    от 3 до 1е5. Каждая из заданных координат может находиться в пределах
    от -1е9 до 1е9.
    Метод Solve() принимает облако точек, заданных в плоскости,
    и возвращает 3 индекса точек из заданного облака, удовлетворяющих
    решению поставленной задачи

    Сигнатуры:

    struct Point2 {
      int x;
      int y;
    };
    std::array<std::size_t, 3> Solve(const std::vector<Point2> &points);

