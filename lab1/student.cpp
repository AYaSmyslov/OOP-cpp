#include "student.h"

STUDENT::STUDENT(string name, int age, float grade) {
	SetName(name);
	SetAge(age);
	SetGrade(grade);
}

void STUDENT::SetAge(int age) {
	this->age = age;
}

void STUDENT::SetName(string name) {
	this->name = name;
}

void STUDENT::SetGrade(float grade) {
	this->grade = grade;
}

void STUDENT::Set(string name, int age, float grade) {
	SetName(name);
	SetAge(age);
	SetGrade(grade);
}

string STUDENT::GetName() const {
	return this->name;
}
int STUDENT::GetAge() const{
	return this->age;
}

float STUDENT::GetGrade() const {
	return this->grade;
}

void STUDENT::Show() {
	cout << "Name: " << GetName() << "\tAge:" << GetAge() << "\tGrade:" << GetGrade() << endl;
}
