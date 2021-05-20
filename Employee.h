#pragma once
#include<iostream>
#include "Person.h"
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee:public virtual Person
{
protected:
	double salary;
	int numOfYears; //number of years in the company

public:
	Employee();
	Employee(char* name, float age, long id, int numOfYears,double salary);
	Employee(const Employee& e);
	virtual ~Employee();
	virtual void print()const;
	virtual void calculateSalary();
	double getSalary()const;

};



#endif// !EMPLOYEE_H