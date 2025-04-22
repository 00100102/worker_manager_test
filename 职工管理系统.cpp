#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	int mainChoice = 0;
	WorkerManager wm;

	/*
	Worker * emp = new Employee(1, "����", 1);
	emp->showInfo();
	string temp_1 = emp->getDepName();
	cout << temp_1 << endl;


	Worker* man = new Manager(1, "����", 1);
	man->showInfo();
	string temp_2 = man->getDepName();
	cout << temp_2 << endl;

	Worker* bos = new Boss(1, "����", 1);
	bos->showInfo();
	string temp_3 = bos->getDepName();
	cout << temp_3 << endl;

	delete emp;
	delete man;
	delete bos;
	*/


	while (true) {
		wm.showMainMenu();
		cout << "������һ��������ִ����Ӧ����" << endl;
		cin >> mainChoice;
		switch (mainChoice) {
		case 0: //�˳�
			wm.mainExit();
			break;
		case 1: // ���ְ����Ϣ
			wm.addWorker();
			wm.save();
			break;
		case 2: // ��ʾְ����Ϣ
			wm.showWorkerInfo();
			break;
		case 3: // ɾ����ְְ��
		{
			int deleteId = 0;
			cout << "������һ��Ա��id������ɾ������" << endl;
			cin >> deleteId;
			wm.deleteWorker(deleteId);
			break;
		}

		case 4: // �޸�ְ����Ϣ
		{
			int updateId = 0;
			cout << "������һ��Ա��id�����и��²���" << endl;
			cin >> updateId;
			wm.updateWorker(updateId);
			break;
		}
		case 5: // ����ְ����Ϣ
			break;
		case 6: // ���ձ������
			break;
		case 7: // ��������ĵ�
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}