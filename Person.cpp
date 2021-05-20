#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Person.h"
using namespace std;

Person::Person():name(NULL), age(18), id(100000000)
{
	//set default values;
}
Person::Person(char* name, float age, long id) :age(age), id(id)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
//---------------------------------------------------
Person::Person(const Person& p):id(p.id), age(p.age)
{
	this->name = new char[strlen(p.name) + 1];
	strcpy(this->name,p.name);
}
//------------------------------------------------------
Person::~Person()
{
	if (name)
		delete[] name;
}
//-------------------------------------------------
void Person::print()const
{
	cout << "**********************" << endl;
	cout << "Details:" << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "ID: " << id << endl;
}
//------------------------------------------------------


