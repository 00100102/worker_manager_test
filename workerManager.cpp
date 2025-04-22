#include "workerManager.h"
#include <limits> // for numeric_limits
#include <cctype> // for isdigit
#include <sstream>

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(this->FileName, ios::out);
	// 判断是否存在文件
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->workerNum = 0;
		this->mWorkerArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//判断是否是空文件
	char tempFirstChar;
	ifs >> tempFirstChar;
	if (ifs.eof()) { //这里就是检测他能不能输出流一个字符，符过不能，则为空
		cout << "文件为空" << endl;
		this->workerNum = 0;
		this->mWorkerArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->initWorkerArray();
	//测试语句
	cout << "当前员工数量为" << this->workerNum << endl;
}

void WorkerManager::showMainMenu() {
	cout << "******************************************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManager::mainExit() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::initWorkerArray() {
	ifstream ifs_1;
	ifs_1.open(FileName, ios::in);

	int id;
	string name;
	int did;
	int num = 0;
	while (ifs_1 >> id >> name >> did) {
		num++;
	}
	ifs_1.close();

	this->workerNum = num;
	this->mWorkerArray = new Worker * [this->workerNum]; //开辟空间


	ifstream ifs_2;
	ifs_2.open(FileName, ios::in);

	int index = 0;
	while (ifs_2 >> id >> name >> did) {
		Worker* worker = nullptr;
		switch (did) {
		case 1:
			worker = new Employee(id, name, did);
			break;
		case 2:
			worker = new Manager(id, name, did);
			break;
		case 3:
			worker = new Boss(id, name, did);
			break;
		default:
			break;
		}
		this->mWorkerArray[index++] = worker; //存放指针
	}
	ifs_2.close();
	//测试语句
	cout << "当前员工数量为" << num << endl;

}


void WorkerManager::addWorker() {
	int workerNumInput = 0;
	cout << "请输入你要添加职工的数量" << endl;
	cin >> workerNumInput;
	if (cin.fail()) {
		cout << "输入无效，请输入一个整数工号！" << endl;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
	}

	if (workerNumInput > 0) {
		int newSize = this->workerNum + workerNumInput;
		Worker** newSpace = new Worker * [newSize]; // 堆区创建一个newSize大小的存放指针的空间，然后将数组的首指针的指针为newSpace

		//处理原本数据，讲到这里我感觉顺序有些乱掉了，还没有进行文件的读写呢，每次初始化数量都为0，为什么在这里进行链接已有文件呢？？
		if (this->mWorkerArray != NULL) {
			for (int j = 0; j < this->workerNum; j++) {
				newSpace[j] = mWorkerArray[j];
			}
		}

		//进行新的数据传递
		for (int i = 0; i < workerNumInput; ++i) {
			int id;
			string name;
			int did;

			// 输入并验证 id（工号）
			while (true) {
				cout << "请输入第" << i + 1 << "个职工的工号（整数）：" << endl;
				cin >> id;
				if (cin.fail()) {
					cout << "输入无效，请输入一个整数工号！" << endl;
					cin.clear(); // 清除错误标志
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空缓冲区
				}
				else {
					break;
				}
			}

			// 输入并验证 name（名字）
			while (true) {
				cout << "请输入第" << i + 1 << "个职工的名称：" << endl;
				cin >> name;
				bool valid = true;
				for (char c : name) {
					if (!isalpha(c)) { // 只允许字母
						valid = false;
						break;
					}
				}
				if (!valid) {
					cout << "名字只能包含字母，请重新输入！" << endl;
				}
				else {
					break;
				}
			}

			// 输入并验证 did（职位编号）
			while (true) {
				cout << "请输入第" << i + 1 << "个职工的职位编号：" << endl;
				cout << "1 普通职员\n2 经理\n3 老板" << endl;
				cin >> did;
				if (cin.fail() || (did < 1 || did > 3)) {
					cout << "职位编号无效，请输入 1、2 或 3！" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					break;
				}
			}

			Worker* worker = NULL; //为什么在switch 外而不在内部，是因为我们在for循环这个作用域下进行输入

			switch (did) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->workerNum + i] = worker;
		}

		delete[] this->mWorkerArray;
		this->mWorkerArray = newSpace;
		this->workerNum = newSize;
		cout << "成功添加" << newSize << "个职员信息" << endl;

		system("pause");
		system("cls");

	}
	else {
		cout << "输入有误，重新进行输入" << endl;
	}


}

void WorkerManager::save() {
	if (mWorkerArray == NULL || workerNum == 0) {
		cout << "无可保存数据" << endl;
		return;
	}
	ofstream wor;
	wor.open("workerInfo.txt", ios::out);

	if (this->mWorkerArray != nullptr) {
		for (int i = 0; i < this->workerNum; i++) {
			if (this->mWorkerArray[i] != nullptr) {
				wor << this->mWorkerArray[i]->mId << " "
					<< this->mWorkerArray[i]->mName << " "
					<< this->mWorkerArray[i]->mDid << " "
					<< endl;
			}
		}
	}
	wor.close();
}

void WorkerManager::showWorkerInfo() {
	if (this->fileIsEmpty) {
		cout << "文件为空，职员信息不存在" << endl;
		return;
	}
	for (int i = 0; i < this->workerNum; i++) {
		this->mWorkerArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

int WorkerManager::isExit(int id) {
	int exitindex = -1;
	for (int i = 0; i < this->workerNum; i++) {
		if (mWorkerArray[i]->mId == id) {
			return i;
		}
	}
	return exitindex;
}

void WorkerManager::deleteWorker(int id) {
	int isExitNum = this->isExit(id);
	if (this->isExit(id) == -1) {
		cout << "该员工并不存在" << endl;
	}
	else {
		cout << "已经查找到该员工，正在删除中" << endl;

		// 执行删除操作的函数功能实现，这是一个顺序表
		for (int i = isExitNum; i < this->workerNum - 1; i++) {
			this->mWorkerArray[i] = this->mWorkerArray[i + 1];
		}
		this->workerNum--;
		this->save();
		cout << "\n删除已经完毕" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::updateWorker(int id) {
	int isExitNum = this->isExit(id); // 还是先判断是否存在这一个员工
	if (this->isExit(id) == -1){
		cout << "该员工不存在" << endl;
	}
	else {
		cout << "已经查找到该员工，可以进行更新" << endl;
		//我认为这个默认不变
		int newId = this->mWorkerArray[isExitNum]->mId;
		string newName = this->mWorkerArray[isExitNum]->mName;
		int newDid = this->mWorkerArray[isExitNum]->mDid;
		string input;
		cin.ignore(); // 清除 cin 留下的换行符

		cout << "当前编号：" << this->mWorkerArray[isExitNum]->mId << "，输入新编号（按 Enter 跳过）: ";
		getline(cin, input);
		if (!input.empty()) {
			newId = stoi(input);
		}

		cout << "当前性名：" << this->mWorkerArray[isExitNum]->mName << "，输入新性名（按 Enter 跳过）: ";
		getline(cin, input);
		if (!input.empty()) {
			newName = input;
		}

		cout << "当前部门编号：" << this->mWorkerArray[isExitNum]->mDid << "，输入新部门id（按 Enter 跳过）: ";
		getline(cin, input);
		if (!input.empty()) {
			newDid = stoi(input);
		}

		delete mWorkerArray[isExitNum];
		switch (newDid) {
		case(1):
			mWorkerArray[isExitNum] = new Employee(newId, newName, newDid);
			break;
		case(2):
			mWorkerArray[isExitNum] = new Manager(newId, newName, newDid);
			break;
		case(3):
			mWorkerArray[isExitNum] = new Boss(newId, newName, newDid);
			break;
		default:
			cout << "输入的部门编号不合法，更新失败。" << endl;
			return;
		}
		this->save();
		cout << "更新成功！" << endl;
	}
	system("pause");
	system("cls");

}






WorkerManager::~WorkerManager() {


}