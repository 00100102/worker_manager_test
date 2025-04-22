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
	WorkerManager(); //�������������ܼ�{}����Ȼ�����ظ�����
	const string FileName = "workerInfo.txt";
	bool fileIsEmpty = false;

	void showMainMenu(); //��������ʾ
	void mainExit();//�������˳�
	Worker** mWorkerArray;//����һ��Ա������ָ��
	int workerNum;//����һ��Ա������
	void initWorkerArray();
	void addWorker(); //���ְ����������
	void save(); //��������
	void showWorkerInfo(); //��ʾְ������
	int isExit(int id);
	void deleteWorker(int id);
	void updateWorker(int id);
	//int getWorkerNum();
	~WorkerManager();
};


