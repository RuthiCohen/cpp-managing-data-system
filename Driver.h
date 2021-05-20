#pragma once
#include "Employee.h"
#include "Delivary.h"

#ifndef DRIVER_H
#define DRIVER_H

class Driver: public Employee
{
protected:
	Delivary* delivaries;
	int numOfDelivaries;
public:
	Driver();
	Driver(char* name, float age, long id, int numOfYears, double salary);
	Driver(const Driver& d);
	virtual ~Driver();
	virtual void print()const;
	void operator+=(const Delivary& d);

};


#endif // !DRIVER_H
