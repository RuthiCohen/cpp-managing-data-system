#pragma once

#ifndef CLUBMEMBER_H
#define CLUBMEMBER_H

#include"Client.h"
class ClubMember : public Client {
private:
	const int num_member;
	static int static_num_member;
	double discount;
public:
	ClubMember(char* name, float age, long id, double discount);
	ClubMember(const ClubMember &c);
	virtual ~ClubMember();
	virtual void print();
};

#endif // !CLUBMEMBER_H
