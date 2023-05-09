#pragma once
#include <iostream>
using namespace std;

class Employee {
	static int cnt;
	string org;
	string pos;
	double exp;
	string name;
	char gender;
	int age;
	double salary;
public:
	Employee(string org="None", string pos = "None", double exp = 0, string name = "None", char gender = '0', int age = 18, double salary = .0f);
	~Employee();

	// set
	static void setOrg(string org);
	static void setPos(string pos);
	static void setExp(double exp);
	static void setName(string name);
	static void setGender(char gender);
	static void setAge(int age);
	static void setSalary(double salary);

	// get
	string getOrg();
	string getPos();
	double getExp();
	string getName();
	char getGender();
	int getAge();
	double getSalary();

	static void showCount();

	bool operator>(Employee* x);
	void changeSalary(double x);
};
