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
		cout << "职员工号 " << mId
			<< "\t职员名称 " << mName
			<< "\t职员部门编号 " << mDid 
			<< endl;
	};
	virtual void getDepName() {
	};
};