#include "workerManager.h"

WorkerManager::WorkerManager() {


}

void WorkerManager::showMainMenu() {
	cout << "******************************************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}

void WorkerManager::mainExit() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager() {


}