#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Employee.h"
using namespace std;

Employee::Employee():Person(), numOfYears(0),salary(0)
{
}

//-------------------------------------------------
Employee::Employee(char* name, float age, long id, int numOfYears,double salary):
	Person(name, age, id), numOfYears(numOfYears),salary(salary)
{
	calculateSalary();
}
//------------------------------------------------------
Employee::Employee(const Employee& e):Person(e),
	salary(e.salary), numOfYears(e.numOfYears)
{

}
//---------------------------------------------------------
Employee::~Employee()
{
	
}
//------------------------------------------------------
void Employee::print()const
{
	Person::print();
	cout << "Salary: " << salary << endl;
	cout << "Number of years: " << numOfYears << endl;

}
//-------------------------------------------------
void Employee::calculateSalary()
{
	salary += (double)100 * numOfYears;
	//for each year the employee gets 100 $ per month
}
//-----------------------------------------------------
double Employee::getSalary()const
{
	return salary;
}
//---------------------------------------------------
