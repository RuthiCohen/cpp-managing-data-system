#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;



#include"Buyer_Employee.h"

Buyer_Employee::Buyer_Employee() :Person(), Employee(), Client(), employee_discount(0) {

}


Buyer_Employee::Buyer_Employee(char* name, float age, long id, int numOfYears, double salary) : Person(name, age, id), Employee(name, age, id, numOfYears,salary), Client(name, age, id) {
	employee_discount = 10;
}

Buyer_Employee::~Buyer_Employee() {

}

void Buyer_Employee::print()const {
	Client::print();
	cout << "Salary: " << salary << endl;
	cout << "Number of years of working: " << numOfYears << endl;
}

void Buyer_Employee::calculateSalary() {
	salary += getWasting() * employee_discount*0.01;
	//for each buying the employee will get extra money to his salary
	//which is employee_discount% 
}

