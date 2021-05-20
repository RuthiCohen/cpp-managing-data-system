#include<iostream>
using namespace std;
#include"Seller.h"
Seller::Seller() :Employee(),extraHours(0){
	
}
Seller::Seller(char* name, float age, long ID, int numOfYears,double salary, int eH):Person(name,age,ID),Employee(name,age,ID,numOfYears,salary),extraHours(eH) {
	calculateSalary();
}
Seller::Seller(const Seller &sell):Employee(sell),extraHours(sell.extraHours) {

}
Seller::~Seller() {

}
void Seller::print()const {
	Employee::print();
	cout << "Extra Hours: " << extraHours << endl;
}
void Seller::calculateSalary() {
	salary += (double)100 * numOfYears + extraHours*50;
	//for each extra hour that the seller work he gets 50 $
}