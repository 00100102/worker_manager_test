#include <iostream>
#include "employee.h"

Employee::Employee(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Employee::showInfo() {
	cout << "ְԱ���� " << mId
		<< "\tְԱ���� " << mName
		<< "\tְԱ���ű�� " << mDid
		<< "\tְԱְ�� ��ɾ����ŵĹ���"
		<< endl;
};
string Employee::getDepName() {
	return "��Ա";
};