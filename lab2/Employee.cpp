#include "Employee.h"

Employee::Employee(string org, string pos, double exp, string name, char gender, int age, double salary) {
	cnt++;
	setOrg(org);
	setPos(pos);
	setExp(exp);
	setName(name);
	setGender(gender);
	setAge(age);
	setSalary(salary);
}

Employee::~Employee() {
	cnt--;
}
void Employee::setOrg(string org) {
	org = org;
}
void Employee::setPos(string pos) {
	pos = pos;
}
void Employee::setExp(double exp) {
	exp = exp;
}
void Employee::setName(string name) {
	name = name;
}
void Employee::setGender(char gender) {
	gender = gender;
}
void Employee::setAge(int age) {
	age = age;
}
void Employee::setSalary(double salary) {
	salary = salary;
}

string Employee::getOrg() {
	return org;
}
string Employee::getPos() {
	return pos;
}
double Employee::getExp() {
	return exp;
}
string Employee::getName() {
	return name;
}
char Employee::getGender() {
	return gender;
}
int Employee::getAge() {
	return age;
}
double Employee::getSalary() {
	return salary;
}

bool Employee::operator>(Employee* x) {
	return age > x->getAge();
}


void Employee::changeSalary(double x) {
	salary += x;
}

void Employee::showCount(){
	cout << "Count: " << cnt << endl;
}
