#include <iostream> 
#include <list> 
#include "Point.h" 
 
using namespace std; 
 
void printList(list<Point>* p) { 
 if (p->size() > 0) { 
  int cnt = 0; 
  for (auto i = p->begin(); i != p->end(); i++) { 
   cout << cnt << ":\t"; 
   i->print(); 
   cnt++; 
  } 
  cout << endl; 
 } 
} 
 
void menu(list<Point>* p) { 
 printList(p); 
 cout << "1. Append point" << endl; 
 cout << "2. Remove point" << endl; 
 cout << "3. Remove area" << endl; 
 cout << "4. Exit" << endl; 
 cout << "[Input num]: "; 
} 
 
void append(list<Point> *p) { 
 int x, y; 
 cout << "Input coords" << endl; 
 cout << "x = "; 
 cin >> x; 
 cout << "y = "; 
 cin >> y; 
 p->push_back(Point(x, y)); 
} 
 
void remove(list<Point>* p) { 
 printList(p); 
 cout << "Input index for remove this coord" << endl; 
 int ind; 
 cout << "[Index]: "; 
 cin >> ind; 
 auto i = p->begin(); 
 advance(i, ind); 
 p->erase(i); 
} 
 
 
 
void removeRect(list<Point>* p) { 
 printList(p); 
 cout << "Input RECT for remove coords in RECT" << endl; 
 int x1, x2, y1, y2; 
 cout << "Input coords of RECT" << endl; 
 cout << "x1 = "; 
 cin >> x1; 
 cout << "y1 = "; 
 cin >> y1; 
 cout << "x2 = "; 
 cin >> x2; 
 cout << "y2 = "; 
 cin >> y2; 
 for (auto i = p->begin(); i != p->end(); i++) { 
  if (((i->x >= x1) && (i->x <= x2)) && ((i->y >= y1) && (i->y <= y2))) { 
   p->erase(i); 
   i = p->begin(); 
  } 
 } 
} 
 
 
int main() { 
 int choice = 0; 
 list<Point> pl; 
 do { 
  menu(&pl); 
  cin >> choice; 
  system("cls"); 
  switch (choice) { 
  case 1: append(&pl);  break; 
  case 2: remove(&pl); break; 
  case 3: removeRect(&pl); break; 
  case 4: break; 
  } 
  system("cls"); 
 } while (choice != 4); 
 return 0; 
}