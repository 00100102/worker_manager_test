#include <iostream>
#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Boss::showInfo() {
	cout << "ְԱ���� " << mId
		<< "\tְԱ���� " << mName
		<< "\tְԱ���ű�� " << mDid
		<< "\tְԱְ�� ����������˾"
		<< endl;
};
string Boss::getDepName() {
	return "�ϰ�";
};