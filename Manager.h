#ifndef Manager_H
#define Manager_H

#include"Employee.h"
#include<iostream>
using namespace std;

class Manager:public Employee {
protected:
	double bonus;

public:
	Manager();
	Manager(char* name,float age,long i_d,int n_years,double s,double b);
	Manager(const Manager& m);
	virtual ~Manager();
	virtual void print()const;
	virtual void calculateSalary();
};
#endif