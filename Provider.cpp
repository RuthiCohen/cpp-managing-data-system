#include<iostream>
using namespace std;
#include"Provider.h"

Provider::Provider():Person(),p(), numOfProducts(0) {

}
Provider::Provider(char* name, float age, long ID, int numOfProducts, long barcode, float price):Person(name,age,ID),numOfProducts(numOfProducts),p(barcode,price) {

}
Provider::Provider(const Provider& provide):Person(provide),numOfProducts(provide.numOfProducts),p(provide.p) {

}
Provider::~Provider() {

}
void Provider::print()const {
	Person::print();
	cout << "number of products: " << numOfProducts << endl;
	p.print();
}
