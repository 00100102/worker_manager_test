#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	virtual void showInfo() = 0;//打印信息
	virtual string getDepName() = 0; //显示部门

	int mId;
	string mName;
	int mDid;	
};