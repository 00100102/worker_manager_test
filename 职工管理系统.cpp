#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	int mainChoice = 0;
	WorkerManager wm;

	/*
	Worker * emp = new Employee(1, "张三", 1);
	emp->showInfo();
	string temp_1 = emp->getDepName();
	cout << temp_1 << endl;


	Worker* man = new Manager(1, "张三", 1);
	man->showInfo();
	string temp_2 = man->getDepName();
	cout << temp_2 << endl;

	Worker* bos = new Boss(1, "张三", 1);
	bos->showInfo();
	string temp_3 = bos->getDepName();
	cout << temp_3 << endl;

	delete emp;
	delete man;
	delete bos;
	*/


	while (true) {
		wm.showMainMenu();
		cout << "请输入一个数字来执行相应操作" << endl;
		cin >> mainChoice;
		switch (mainChoice) {
		case 0: //退出
			wm.mainExit();
			break;
		case 1: // 添加职工信息
			wm.addWorker();
			wm.save();
			break;
		case 2: // 显示职工信息
			wm.showWorkerInfo();
			break;
		case 3: // 删除离职职工
		{
			int deleteId = 0;
			cout << "请输入一个员工id来进行删除操作" << endl;
			cin >> deleteId;
			wm.deleteWorker(deleteId);
			break;
		}

		case 4: // 修改职工信息
		{
			int updateId = 0;
			cout << "请输入一个员工id来进行更新操作" << endl;
			cin >> updateId;
			wm.updateWorker(updateId);
			break;
		}
		case 5: // 查找职工信息
			break;
		case 6: // 按照编号排序
			break;
		case 7: // 清空所有文档
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}