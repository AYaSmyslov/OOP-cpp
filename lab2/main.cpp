#include <iostream>
#include "Employee.h"

using namespace std;

int Employee::cnt = 0;

int main() {
	Employee::showCount();
	const Employee* a = new Employee();
	a->setAge(11);
	Employee::showCount();		// 1
	const Employee* b = new Employee();
	Employee::showCount();		// 2
	b->setAge(20);
	cout << (b > a) << endl;
	delete b;
	Employee::showCount();		// 1

	return 0;
}