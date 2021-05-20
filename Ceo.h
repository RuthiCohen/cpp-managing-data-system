
#include<iostream>
using namespace std;
#ifndef CEO_H
#define CEO_H
#include "Manager.h"

class Ceo: public Manager {
public:
	Ceo();
	Ceo(char* name, float age, long i_d, int n_years,double salary,double bonus);
	Ceo(const Ceo& c);
	virtual ~Ceo();
	virtual void print()const;
	virtual void calculateSalary();
};
#endif