#include <iostream> 
#include <vector> 
 
using namespace std; 

// Базовый класс с виртуальным методом show - перегружается в классе Point3D
class base { 
public: 
 virtual void show() {}; 
}; 
 

// Представляет шаблон класса, который описывает точку из двух координат X и Y
// template <class T> - Тема, позволяющая на место T подставлять любой тип данных
template <class T> class Point2D { 
protected: 
 T x, y; 
public: 
 Point2D(T x, T y) : x(x), y(y) {}; // Конструктор класса
}; 
 

// Шаблон класса Z - это третья ось координат, ниже класс Point3D наследует Point2D и Z, 
// что позволяет описывать точки в трехмерном пространстве
template <class T> class Z { 
protected: 
 T z; 
public: 
 Z(T z) : z(z) {}; 
}; 

// Шаблон класса, описывающий точку в трехмерном пространстве, наследует класс описания двумерной точки
// и класс описания оси Z, добавляющий третье измерение в двумерное пространство
// Также наследует класс base и определяет его метод show
template <class T> class Point3D : public Point2D<T>, public Z<T>, base { 
public: 
 Point3D(T x, T y, T z) : Point2D <T>(x, y), Z <T>(z) {}; 

 void show() { 
  cout << "X: " << this->x << ", Y: " << this->y << ", Z: " << this->z << endl; 
 } 
}; 
 
int main() { 
/* Пример магии паттерна полиморфизм */
 Point3D <int> a(1, 2, 3); // координаты имеют тип int 
 a.show(); 
 Point3D <double> b(1.5, 2.2, 3.1); // координаты имеют тип double 
 b.show(); 
 vector<base*> v; 
 v.push_back((base*)&a); 


// Задание - вектор из пяти элементов, состоящий из пяти объектов класса Point3d,
// чтобы все элементы при этом были разного типа
 vector<base*> zadanie; 
 zadanie.push_back((base*)&b); 
 zadanie.push_back((base*) new Point3D<int>(-3, -10, -12)); 
 zadanie.push_back((base*) new Point3D<short>(1, 2, 254)); 
 zadanie.push_back((base*) new Point3D<float>(4.4, 5.5, 6.6)); 
 zadanie.push_back((base*) new Point3D<long>(70000, 80000, 90000)); 
 zadanie.push_back((base*) new Point3D<char>('l', 'o', 'l')); 

 
 cout << "Result" << endl; 
 for (int i = 0; i < zadanie.size(); i++) { 
  zadanie[i]->show(); 
 } 
 return 0; 
}