#include <iostream>
#include "workerManager.h"
#include "employee.h"

int main() {
	int mainChoice = 0;
	WorkerManager wm;
	Worker * worker = new Employee(1, "����", 1);
	worker->showInfo();
	//while (true) {
	//	wm.showMainMenu();
	//	cout << "������һ��������ִ����Ӧ����" << endl;
	//	cin >> mainChoice;
	//	switch (mainChoice) {
	//	case 0: //�˳�
	//		wm.mainExit();
	//		break;
	//	case 1: // ���ְ����Ϣ
	//		break;
	//	case 2: // ��ʾְ����Ϣ
	//		break;
	//	case 3: // ɾ����ְְ��
	//		break;
	//	case 4: // �޸�ְ����Ϣ
	//		break;
	//	case 5: // ����ְ����Ϣ
	//		break;
	//	case 6: // ���ձ������
	//		break;
	//	case 7: // ��������ĵ�
	//		break;
	//	default:
	//		system("cls");
	//		break;
	//	}
	//}
	system("pause");
	return 0;
}