#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#include"ClubMember.h"

ClubMember::ClubMember(char* name, float age, long id, double discount) :Person(name,age,id),Client(name, age, id), num_member(static_num_member++) {

}


ClubMember::ClubMember(const ClubMember &c):Client(c),num_member(c.num_member),discount(c.discount) {

}


ClubMember::~ClubMember() {

}


void ClubMember::print(){
	Client::print();
	cout << "Member number: " << num_member << endl;
	cout<<"Discount: " << discount << endl;
}