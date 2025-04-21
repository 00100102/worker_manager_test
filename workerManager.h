#pragma once
#include <iostream>
using namespace std;

class WorkerManager {
public:
	WorkerManager(); //函数声明，不能加{}，不然报错重复声明

	void showMainMenu(); //主界面显示
	void mainExit();//主界面退出

	~WorkerManager();
};


