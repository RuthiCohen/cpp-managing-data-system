#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
protected:
	long barcode;
	double price;
public:
	Product();
	Product(long barcode, double price);
	Product(const Product& p);
	~Product();
	void print()const;
	double getPrice()const {
		return price;
	}
	bool operator<(const Product &p)const;
	bool operator>(const Product &p)const;
	bool operator==(const Product &p)const;

};
#endif //PRODUCT_H
