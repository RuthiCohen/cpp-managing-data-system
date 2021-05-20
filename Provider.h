#ifndef PROVIDER_H
#define PROVIDER_H

#include"Person.h"
#include"Product.h"

class Provider :public Person {
private:
	Product p;
	int numOfProducts;
	//the provider provide only one kind of product
public:
	Provider();
	Provider(char* name, float age, long ID, int numOfProducts,long barcode,float price);
	Provider(const Provider& provide);
	virtual ~Provider();
	virtual void print()const;

};
#endif//!PROVIDER_H