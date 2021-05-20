#pragma once
#ifndef PERSON_H
#define PERSON_H

#include<iostream>
using namespace std;

class Person
{
protected:
	char* name;
	float age;
	long id;

public:
	Person();
	Person(char* name, float age, long id);
	Person(const Person& p);
	virtual ~Person();
	virtual void print()const = 0;
	int getId() { return id; }
	
};


#endif // !PERSON_H

