#include "workerManager.h"
#include <limits> // for numeric_limits
#include <cctype> // for isdigit
#include <sstream>

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(this->FileName, ios::out);
	// �ж��Ƿ�����ļ�
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->workerNum = 0;
		this->mWorkerArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ж��Ƿ��ǿ��ļ�
	char tempFirstChar;
	ifs >> tempFirstChar;
	if (ifs.eof()) { //������Ǽ�����ܲ��������һ���ַ����������ܣ���Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->workerNum = 0;
		this->mWorkerArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->initWorkerArray();
	//�������
	cout << "��ǰԱ������Ϊ" << this->workerNum << endl;
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
	this->mWorkerArray = new Worker * [this->workerNum]; //���ٿռ�


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
		this->mWorkerArray[index++] = worker; //���ָ��
	}
	ifs_2.close();
	//�������
	cout << "��ǰԱ������Ϊ" << num << endl;

}


void WorkerManager::addWorker() {
	int workerNumInput = 0;
	cout << "��������Ҫ���ְ��������" << endl;
	cin >> workerNumInput;
	if (cin.fail()) {
		cout << "������Ч��������һ���������ţ�" << endl;
		cin.clear(); // ��������־
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��ջ�����
	}

	if (workerNumInput > 0) {
		int newSize = this->workerNum + workerNumInput;
		Worker** newSpace = new Worker * [newSize]; // ��������һ��newSize��С�Ĵ��ָ��Ŀռ䣬Ȼ���������ָ���ָ��ΪnewSpace

		//����ԭ�����ݣ����������Ҹо�˳����Щ�ҵ��ˣ���û�н����ļ��Ķ�д�أ�ÿ�γ�ʼ��������Ϊ0��Ϊʲô������������������ļ��أ���
		if (this->mWorkerArray != NULL) {
			for (int j = 0; j < this->workerNum; j++) {
				newSpace[j] = mWorkerArray[j];
			}
		}

		//�����µ����ݴ���
		for (int i = 0; i < workerNumInput; ++i) {
			int id;
			string name;
			int did;

			// ���벢��֤ id�����ţ�
			while (true) {
				cout << "�������" << i + 1 << "��ְ���Ĺ��ţ���������" << endl;
				cin >> id;
				if (cin.fail()) {
					cout << "������Ч��������һ���������ţ�" << endl;
					cin.clear(); // ��������־
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ��ջ�����
				}
				else {
					break;
				}
			}

			// ���벢��֤ name�����֣�
			while (true) {
				cout << "�������" << i + 1 << "��ְ�������ƣ�" << endl;
				cin >> name;
				bool valid = true;
				for (char c : name) {
					if (!isalpha(c)) { // ֻ������ĸ
						valid = false;
						break;
					}
				}
				if (!valid) {
					cout << "����ֻ�ܰ�����ĸ�����������룡" << endl;
				}
				else {
					break;
				}
			}

			// ���벢��֤ did��ְλ��ţ�
			while (true) {
				cout << "�������" << i + 1 << "��ְ����ְλ��ţ�" << endl;
				cout << "1 ��ְͨԱ\n2 ����\n3 �ϰ�" << endl;
				cin >> did;
				if (cin.fail() || (did < 1 || did > 3)) {
					cout << "ְλ�����Ч�������� 1��2 �� 3��" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					break;
				}
			}

			Worker* worker = NULL; //Ϊʲô��switch ��������ڲ�������Ϊ������forѭ������������½�������

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
		cout << "�ɹ����" << newSize << "��ְԱ��Ϣ" << endl;

		system("pause");
		system("cls");

	}
	else {
		cout << "�����������½�������" << endl;
	}


}

void WorkerManager::save() {
	if (mWorkerArray == NULL || workerNum == 0) {
		cout << "�޿ɱ�������" << endl;
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
		cout << "�ļ�Ϊ�գ�ְԱ��Ϣ������" << endl;
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
		cout << "��Ա����������" << endl;
	}
	else {
		cout << "�Ѿ����ҵ���Ա��������ɾ����" << endl;

		// ִ��ɾ�������ĺ�������ʵ�֣�����һ��˳���
		for (int i = isExitNum; i < this->workerNum - 1; i++) {
			this->mWorkerArray[i] = this->mWorkerArray[i + 1];
		}
		this->workerNum--;
		this->save();
		cout << "\nɾ���Ѿ����" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::updateWorker(int id) {
	int isExitNum = this->isExit(id); // �������ж��Ƿ������һ��Ա��
	if (this->isExit(id) == -1){
		cout << "��Ա��������" << endl;
	}
	else {
		cout << "�Ѿ����ҵ���Ա�������Խ��и���" << endl;
		//����Ϊ���Ĭ�ϲ���
		int newId = this->mWorkerArray[isExitNum]->mId;
		string newName = this->mWorkerArray[isExitNum]->mName;
		int newDid = this->mWorkerArray[isExitNum]->mDid;
		string input;
		cin.ignore(); // ��� cin ���µĻ��з�

		cout << "��ǰ��ţ�" << this->mWorkerArray[isExitNum]->mId << "�������±�ţ��� Enter ������: ";
		getline(cin, input);
		if (!input.empty()) {
			newId = stoi(input);
		}

		cout << "��ǰ������" << this->mWorkerArray[isExitNum]->mName << "���������������� Enter ������: ";
		getline(cin, input);
		if (!input.empty()) {
			newName = input;
		}

		cout << "��ǰ���ű�ţ�" << this->mWorkerArray[isExitNum]->mDid << "�������²���id���� Enter ������: ";
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
			cout << "����Ĳ��ű�Ų��Ϸ�������ʧ�ܡ�" << endl;
			return;
		}
		this->save();
		cout << "���³ɹ���" << endl;
	}
	system("pause");
	system("cls");

}






WorkerManager::~WorkerManager() {


}