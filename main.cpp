/*names:
Dvora Leah Mizrachi 207919341
Blimy Rosenfeld 211591219
Rut Bracha Cohen 314653320
Chaya Levin 211397757
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<typeinfo>
#include"Product.h"
#include"Delivary.h"
#include"Provider.h"
#include"Ceo.h"
#include"Seller.h"
#include"Buyer_Employee.h"
#include"ClubMember.h"
#include"Person.h"
#include"Employee.h"
#include"Client.h"
#include"Driver.h"
#include"Manager.h"

bool  menu(Person **parr);
void fillCarr(Person *c);
void fillDarr(Person *d);
int searchById(Person **parr, int size, int id);


//initializing static parameter
int ClubMember::static_num_member = 1;

int main() {
	int size, i;
	cout << "Number of people: ";
	cin >> size;

	//size validty check
	//if negative size was entered set size to default
	if (size < 0) {
		size = 0;
	}

	//allocate array
	Person** parr = new Person*[size];

	//fill array
	for (i = 0; i < size; i++)
	{
		//sending each cell in the array to the folfeel function
		if (!(menu(&(parr[i])))) {
			--i;//fill cell again
			cout << "invalid input enter again" << endl;
		}


	}

	/*adding another object to the array
	copy existing array to the new one and adding new object*/
	cout << "enter another person" << endl;
	Person **temp = new Person*[size + 1];

	for (i = 0; i < size; i++)
	{
		temp[i] = parr[i];
	}

	int flag = 1;

	//trying to fill the another cell in the array
	//untill it is succeeded
	while (flag == 1) {
		if (!(menu(&(temp[i])))) {
			cout << "invalid input enter again" << endl;
		}
		else
		{
			flag = 0;
		}
	}

	//updating details of array
	size++;
	delete[] parr;
	parr = temp;



	//--------------------------------------------------------------------

	//search a person in the array by its id
	cout << "enter id in the array" << endl;
	cin >> i;

	int index = searchById(parr, size, i);
	if (index == -1) {
		cout << "no id is found" << endl;
	}
	else
	{
		/*allocate new arr in size-1 and update it yo contain the
		same objects without the person with the requested id*/
		Person **newArr = new Person*[size - 1];
		for (i = 0; i < size; i++)
		{
			if (i < index) //copying as usual
				newArr[i] = parr[i];

			else if (i > index)
				newArr[i - 1] = parr[i];

			//else i==index
			//skip this index
		}

		//updating array details
		size--;
		if (parr != NULL)
			delete[] parr;

		parr = newArr;

	}

	


	//----------------------------------------------------------------------------
	//print the array
	for (int i = 0; i < size; i++)
	{
		parr[i]->print();
	}

	//---------------------------------------------------------------------------

	//releasing all the array cells
	for (i = 0; i < size; i++)
	{
		delete parr[i];
	}

	delete[] parr;

	return 0;
}

bool menu(Person **parr) {

	//this fun' fill objects 
	int  choice, pa, j, choice2, numY;
	char name[30] = { 0 };
	long id, bc;
	float age, price;
	double discount, salary, bonus;


	cout << "Enter your choice: " << endl;
	cout << "1=Provider, 2=Employee, 3=Client" << endl;
	cin >> choice;

	cout << "Enter name, id, age for general person " << endl;
	cin >> name >> id >> age;

	if (choice == 1) {//provider
		cout << "enter number of product, barcode and price ";
		cin >> pa >> bc >> price;
		*parr = new Provider(name, age, id, pa, bc, price);

	}
	else if (choice == 2) {//Employee
		cout << "enter 1=Employee, 2=driver, 3=manager, 4=ceo, 5=seller, 6=buyer employee" << endl;
		cin >> choice2;
		cout << "enter salary and num of years for genaral Employee" << endl;
		cin >> salary >> numY;
		switch (choice2)
		{
		case 1:
			*parr = new Employee(name, age, id, numY, salary);
			break;
		case 2:

			*parr = new Driver(name, age, id, numY, salary);
			cout << "enter number of delivaries ";
			cin >> pa;
			for (j = 0; j < pa; j++) {
				fillDarr(*parr);
			}
			break;
		case 3:
			cout << "enter bonus ";
			cin >> bonus;
			*parr = new Manager(name, age, id, numY, salary, bonus);
			break;
		case 4:
			cout << "enter bonus ";
			cin >> bonus;
			*parr = new Ceo(name, age, id, numY, salary, bonus);
			break;
		case  5:
			cout << "extra hour ";
			cin >> pa;
			*parr = new Seller(name, age, id, numY, salary, pa);
			break;
		case 6:
			cout << "how many products the buyer has? ";
			cin >> pa;
			*parr = new Buyer_Employee(name, age, id, numY, salary);
			for (j = 0; j < pa; j++) {
				fillCarr(*parr);
			}
			break;
		default:
			return false;
		}
	}
	else if (choice == 3) {//client
		cout << "enter your choice: " << endl;
		cout << "1=client, 2=club member, 3= buyer employee" << endl;
		cin >> choice2;

		switch (choice2)
		{
		case 1: //client
			*parr = new Client(name, age, id);
			cout << "enter number of products ";
			cin >> pa;
			for (j = 0; j < pa; j++) {
				fillCarr(*parr);
			}
			break;
		case 2://club member
			cout << "enter discount for club member" << endl;
			cin >> discount;
			*parr = new ClubMember(name, age, id, discount);
			break;
		case 3://buyer employee
			cout << "enter number of years in company salary, number of products:" << endl;
			cin >> numY >> salary >> pa;
			*parr = new Buyer_Employee(name, age, id, numY, salary);
			for (j = 0; j < pa; j++) {
				fillCarr(*parr);
			}
			break;
		default:
			return false;
		}
	}
	else
		return false;

	return true;

}


void fillCarr(Person *c) {
	//fill client array
	long barcode;
	float price;
	cout << "enter barcode and price " << endl;
	cin >> barcode >> price;
	Product prod(barcode, price);
	if (dynamic_cast<Client*>(c)) {
		*(dynamic_cast<Client*>(c)) += prod;
	}
}


void fillDarr(Person *d) {
	//fill Driver array
	float price, weight;
	cout << "enter weight and price " << endl;
	cin >> weight >> price;
	Delivary del(weight, price);
	if (dynamic_cast<Driver*>(d)) {
		*(dynamic_cast<Driver*>(d)) += del;
	}
}



int searchById(Person **parr, int size, int id) {
	for (int i = 0; i < size; i++)
	{
		if (parr[i]->getId() == id)
			return i;
	}

	return -1;

}



