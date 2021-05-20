#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Delivary.h"
using namespace std;

Delivary::Delivary() 
{
	weight = 0;
	price = 0;
}
//----------------------------------------------
Delivary::Delivary(float weight, float price)
{
	this->weight = weight;
	this->price = price;
}
//------------------------------------------------
Delivary::Delivary(const Delivary& d) 
{
	weight = d.weight;
	price = d.price;
}
//-----------------------------------------------
Delivary::~Delivary()
{

}
//--------------------------------------------------
void Delivary::print()const
{
	cout << "Price: " << price << endl;
	cout << "Weight: " << weight << endl;
}



Delivary& Delivary::operator+(const Delivary &d) {
	this->price += d.price;
	this->weight+=d.weight;
	return *this;
}
Delivary& Delivary::operator-(const Delivary &d) {
	this->price -= d.price;
	this->weight -= d.weight;
	return *this;
}