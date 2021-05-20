#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Ceo.h"
using namespace std;

Ceo::Ceo():Manager(){
}

Ceo::Ceo(char* name, float a, long i_d, int n_years,double salary,double bonus):Person(name,a,i_d),Manager(name, a, i_d, n_years,salary,bonus){
	calculateSalary();//set val in salary
}
Ceo::Ceo(const Ceo& c):Manager(c){
	//slicing
}
Ceo:: ~Ceo() {}

void Ceo::print()const {
	Manager::print();//thew father fun' 
}
void Ceo::calculateSalary() {
	salary += (double)200 * numOfYears +bonus;
	//the ceo earns 200$ for each year he worksed+ bonus 
}