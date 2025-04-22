#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

using namespace std;

class WorkerManager {
public:
	WorkerManager(); //函数声明，不能加{}，不然报错重复声明
	const string FileName = "workerInfo.txt";
	bool fileIsEmpty = false;

	void showMainMenu(); //主界面显示
	void mainExit();//主界面退出
	Worker** mWorkerArray;//常见一个员工数组指向
	int workerNum;//创建一个员工数量
	void initWorkerArray();
	void addWorker(); //添加职工功能声明
	void save(); //保存数据
	void showWorkerInfo(); //显示职工数据
	int isExit(int id);
	void deleteWorker(int id);
	void updateWorker(int id);
	//int getWorkerNum();
	~WorkerManager();
};


