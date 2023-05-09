#pragma once
#include <iostream>

using namespace std;

class STUDENT {
	string name;
	int age;
	float grade;
public:
	STUDENT(string name="student", int age = 0, float grade = .0f);
	string GetName() const;
	int GetAge() const;
	float GetGrade() const;
	void SetName(string);
	void SetAge(int);
	void SetGrade(float);
	void Set(string, int, float);
	void Show();
};
