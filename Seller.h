#ifndef SELLER_H
#define SELLER_H
#include"Employee.h"

class Seller :public Employee {
private:
	int extraHours;
public:
	Seller();
	Seller(char* name, float age, long ID, int numOfYears,double salary, int eH);
	Seller(const Seller &s);
	virtual ~Seller();
	virtual void print()const;
	virtual void calculateSalary();
};
#endif //!SELLER_H
