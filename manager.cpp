#include <iostream>
#include "manager.h"

Manager::Manager(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Manager::showInfo() {
	cout << "ְԱ���� " << mId
		<< "\tְԱ���� " << mName
		<< "\tְԱ���ű�� " << mDid
		<< "\tְԱְ�� ����ϰ������"
		<< endl;
};
string Manager::getDepName() {
	return "����";
};