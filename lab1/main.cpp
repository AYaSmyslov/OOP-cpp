#include <iostream>
#include "student.h"

#define STUDENTS_CNT 5

using namespace std;

int main() {

	STUDENT* a = new STUDENT[STUDENTS_CNT];
	float avgAge = 0;
	for (int i = 0; i < STUDENTS_CNT; i++) {
		a[i].SetAge((i+1)*10);
		avgAge += a[i].GetAge();
	}
	avgAge /= STUDENTS_CNT;
	cout << "Students average age = " << avgAge << endl;
	return 0;
}