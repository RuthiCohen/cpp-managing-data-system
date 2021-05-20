#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "Driver.h"
using namespace std;


Driver::Driver():Employee(), numOfDelivaries(0), delivaries(NULL) {
	//default driver c-tor

}


Driver::Driver(char* name, float age, long id, int numOfYears, double salary) :Person(name,age,id), Employee(name, age, id,numOfYears, salary) {
	numOfDelivaries = 0;
	delivaries = NULL;
}


Driver::Driver(const Driver &d) :Employee(d) {
	delivaries = NULL;
	numOfDelivaries = d.numOfDelivaries;
	if (d.numOfDelivaries != 0) {
		delivaries = new Delivary[numOfDelivaries];
		for (int i = 0; i < numOfDelivaries; i++)
		{
			delivaries[i] = d.delivaries[i];
		}
	}
	

}


Driver::~Driver() {
	if(delivaries)
	delete[] delivaries;
}


///////////////////////////////////////

void Driver::print()const {
	Employee::print();
	cout << "Number of delivaries :" << numOfDelivaries << endl;
	cout << "Details of delivaries: " << endl;
	for (int i = 0; i < numOfDelivaries; i++)
	{
		delivaries[i].print();
	}

}

void Driver::operator+=(const Delivary& d) {
	Delivary *newArr = new Delivary[numOfDelivaries + 1];
	int i;
	for (i = 0; i < numOfDelivaries; i++)
	{
		//if the size is 0 so the loop will not do anything
		newArr[i] = this->delivaries[i];
	}
	newArr[i] = d;
	numOfDelivaries++;

	//free the old array before losing access to it
	if (delivaries != NULL)
		delete[] delivaries;

	delivaries = newArr;


}
