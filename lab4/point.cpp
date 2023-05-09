#include "Point.h"
Point::Point(int x, int y) { this->x = x;
 this->y = y;}
void Point::print() {
 cout << "x: " << x << "\ty: " << y << endl;}