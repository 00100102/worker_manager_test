#include <iostream>
#include "boss.h"

Boss::Boss(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Boss::showInfo() {
	cout << "职员工号 " << mId
		<< "\t职员名称 " << mName
		<< "\t职员部门编号 " << mDid
		<< "\t职员职责 管理整个公司"
		<< endl;
};
string Boss::getDepName() {
	return "老板";
};