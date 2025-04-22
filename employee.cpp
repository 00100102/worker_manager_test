#include <iostream>
#include "employee.h"

Employee::Employee(int id, string name, int did) {
	this->mId = id;
	this->mName = name;
	this->mDid = did;
}
void Employee::showInfo() {
	cout << "职员工号 " << mId
		<< "\t职员名称 " << mName
		<< "\t职员部门编号 " << mDid
		<< "\t职员职责 完成经理安排的工作"
		<< endl;
};
string Employee::getDepName() {
	return "雇员";
};