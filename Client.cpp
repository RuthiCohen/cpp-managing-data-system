#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


#include"Client.h"

Client::Client() :Person(), numOfproduct(0), products(NULL) {
	//default client c-tor

}


Client::Client(char* name, float age, long id) : Person(name, age, id) {
	numOfproduct = 0;
	products = NULL;
}


Client::Client(const Client &c) :Person(c) {
	numOfproduct = c.numOfproduct;
	if (c.numOfproduct != 0) {
		products = new Product[numOfproduct];
		for (int i = 0; i < numOfproduct; i++)
		{
			products[i] = c.products[i];
		}
	}

}


Client::~Client() {
	if (products)
		delete[]products;
}


///////////////////////////////////////

void Client::print()const {
	Person::print();
	cout << "Number of products: " << numOfproduct << endl;
	for (int i = 0; i < numOfproduct; i++)
	{
		products[i].print();
	}

}
void Client::operator+=(const Product&p) {
	Product *newArr = new Product[numOfproduct + 1];
	int i;
	for (i = 0; i < numOfproduct; i++)
	{
		//if the size is 0 so the loop will not do anything
		newArr[i] = this->products[i];
	}
	newArr[i] = p;
	numOfproduct++;

	//free the old array before losing access to it
	if (products != NULL)
		delete[] products;

	products = newArr;


}

double Client::getWasting() {
	double wasting=0;
	for (int i = 0; i < numOfproduct; i++)
	{
		wasting += products[i].getPrice();
	}
	return wasting;
}
