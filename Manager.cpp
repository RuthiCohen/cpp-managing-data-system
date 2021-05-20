#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Manager.h"
using namespace std;


Manager::Manager():Employee(), bonus(0) {
}
Manager::Manager(char* name, float age, long i_d,int n_years,double salary,double b):
	Person(name,age,i_d),Employee(name,age,i_d,n_years,salary),bonus(b) {
	calculateSalary();
}
Manager::Manager(const Manager &m):
	Employee(m),bonus(m.bonus) {
}
Manager:: ~Manager() {}


void Manager::print()const {
	Employee::print();
	cout <<"Bonus: "<<bonus<< endl;
}
void Manager::calculateSalary() {
	salary += (double)150 * numOfYears+bonus;

}