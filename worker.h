#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
public:
	virtual void showInfo() = 0;//��ӡ��Ϣ
	virtual void getDepName() = 0; //��ʾ����

	int mId;
	string mName;
	int mDid;	
};