#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "Product.h"

class Client : public virtual Person
{
protected:
	Product* products;
	int numOfproduct;
	//array of products
public:
	Client();
	Client(char* name, float age, long id);
	Client(const Client &c);
	virtual ~Client();
	virtual void print()const;
	void operator+=(const Product&p);
	double getWasting();
};

#endif //CLIENT_H

