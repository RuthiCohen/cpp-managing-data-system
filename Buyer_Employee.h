#pragma once

#ifndef BUYER_EMPLOYEE_H
#define BUYER_EMPLOYEE_H

#include"Client.h"
#include"Employee.h"

class Buyer_Employee :public Employee, public Client {
protected:
	double employee_discount;
	//the discount will increase the employee's salary
public:
	Buyer_Employee();
	Buyer_Employee(char* name, float age, long id, int numOfYears,double salary);
	virtual ~Buyer_Employee();
	virtual	void print()const;
	virtual void calculateSalary();


};
#endif // !BUYER_EMPLOYEE_H
