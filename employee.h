#pragma once
#include <iostream>
#include "worker.h"

class Employee : public Worker {
public:
	Employee(int id, string name, int did) {
		this->mId = id;
		this->mName = name;
		this->mDid = did;
	}
	virtual void showInfo() {
		cout << "ְԱ���� " << mId
			<< "\tְԱ���� " << mName
			<< "\tְԱ���ű�� " << mDid 
			<< endl;
	};
	virtual void getDepName() {
	};
};