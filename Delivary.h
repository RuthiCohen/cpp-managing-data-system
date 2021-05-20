#pragma once
#ifndef DELIVARY_H
#define DELIVARY_H

class Delivary
{
private:
	float weight;
	float price;

public:
	Delivary();
	Delivary(float weight, float price);
	Delivary(const Delivary& d);
	~Delivary();
	void print()const;
	Delivary& operator+(const Delivary &d);
	Delivary& operator-(const Delivary &d);

};



#endif// !DELIVARY
