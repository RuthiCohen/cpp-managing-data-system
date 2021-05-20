#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Product.h"
using namespace std;

Product::Product() {
	barcode = 0;
	price = 0;
}
Product::Product(long barcode, double price) {
	this->barcode = barcode;
	this->price = price;
}
Product::Product(const Product&p) {
	barcode = p.barcode;
	price = p.price;
}
Product::~Product() {

}
void Product :: print()const {
	cout << "barcode of prduct: " << barcode << endl;
	cout<< "Price: " << price << endl;
}


bool Product ::operator<(const Product &p)const {
	//check if this product is cheaper than p
	return this->price < p.price;
}
bool Product ::operator>(const Product &p)const {
	//check if this product is more expensive than p
	return this->price > p.price;
}
bool Product ::operator==(const Product &p)const {
	//check if the prices are the same
	return this->price == p.price;
}