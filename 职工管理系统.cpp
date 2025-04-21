#include <iostream>
#include "workerManager.h"
#include "employee.h"

int main() {
	int mainChoice = 0;
	WorkerManager wm;
	Worker * worker = new Employee(1, "张三", 1);
	worker->showInfo();
	//while (true) {
	//	wm.showMainMenu();
	//	cout << "请输入一个数字来执行相应操作" << endl;
	//	cin >> mainChoice;
	//	switch (mainChoice) {
	//	case 0: //退出
	//		wm.mainExit();
	//		break;
	//	case 1: // 添加职工信息
	//		break;
	//	case 2: // 显示职工信息
	//		break;
	//	case 3: // 删除离职职工
	//		break;
	//	case 4: // 修改职工信息
	//		break;
	//	case 5: // 查找职工信息
	//		break;
	//	case 6: // 按照编号排序
	//		break;
	//	case 7: // 清空所有文档
	//		break;
	//	default:
	//		system("cls");
	//		break;
	//	}
	//}
	system("pause");
	return 0;
}