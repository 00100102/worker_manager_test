#include <iostream>
#include "manager.h"

Manager::Manager(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Manager::showInfo() {
	cout << "职员工号 " << mId
		<< "\t职员名称 " << mName
		<< "\t职员部门编号 " << mDid
		<< "\t职员职责 完成老板的需求"
		<< endl;
};
string Manager::getDepName() {
	return "经理";
};