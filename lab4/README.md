# Описание программы для работы с точками

Данная программа создана для работы с точками на плоскости. В программе реализовано добавление новых точек, удаление выбранных точек и удаление точек, находящихся в заданной прямоугольной области. 

## Инструкция по использованию

После запуска программы на экране появится меню, содержащее список доступных операций:

1. Добавить точку
2. Удалить точку
3. Удалить точки в области
4. Выход

Для выбора нужной операции необходимо ввести соответствующий номер и нажать клавишу Enter.

### Добавление новой точки

При выборе операции "Добавить точку" на экране появится сообщение с запросом ввода координат новой точки. Необходимо последовательно ввести значение координат x и y, разделяя их нажатием клавиши Enter после каждого ввода. После ввода координат новая точка будет добавлена в список точек.

### Удаление точки

При выборе операции "Удалить точку" на экране появится список всех имеющихся точек с их порядковыми номерами. Необходимо ввести номер точки, которую нужно удалить, и нажать клавишу Enter. После этого точка будет удалена из списка.

### Удаление точек в области

При выборе операции "Удалить точки в области" на экране появится сообщение с запросом ввода координат прямоугольной области, в которой находятся точки, которые необходимо удалить. Необходимо последовательно ввести координаты двух противоположных углов области - левого верхнего и правого нижнего, разделяя их нажатием клавиши Enter после каждого ввода. После этого будут удалены все точки, которые находятся в заданной области.

## Описание кода


Описание класса точки Point находится в файле Point.h:

```cpp
class Point {
public:
 int x, y;
 Point(int x = 0, int y = 0);
 void print();
};
```

В конструкторе класса инициализируются координаты точки, метод print() выводит координаты на экран.

Файл main.cpp содержит описание функций, реализующих операции работы с точками: добавление новой точки, удаление точки, удаление точек в прямоугольной области, а также функции, отображающей список точек на экране