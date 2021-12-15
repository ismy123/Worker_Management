#include "Worker.h"
#include "WorkerManager.h"
void Worker::ShowInfo()
{
	cout << nameA << ")  " << Ename << " ... " << _mon << "��" << endl;
}

PerWorker::PerWorker(char* _name, int mon)
{
	_mon = mon;

	GetEm("������");
	GetName(_name);
	CalMoney();
}

DayWorker::DayWorker(char* _name, int daycount, int daymon)
{
	_daycount = daycount;
	_daymon = daymon;

	GetEm("�Ͽ���");
	GetName(_name);
	CalMoney();
}

PartTWorker::PartTWorker(char* _name, int WorkT, int Tmon)
{
	_WorkT = WorkT;
	_Tmon = Tmon;

	GetEm("��ƮŸ��");
	GetName(_name);
	CalMoney();
}

Worker* WorkerFactory::Create(eWork work)
{
	system("cls");
	Worker* pWorker = NULL;
	char _name[10];
	int mon = 0;
	int daycount = 0;
	int daymon = 0;
	int WorkT = 0;
	int Tmon = 0;
	

	switch (work)
	{
	case eWork::PERWORK:

		cout << "--- ������ ��� ---" << endl;
		cout << endl;
		cout << "�̸� : ";
		cin >> _name;
		cout << "����(��) : ";
		cin >> mon;

		pWorker = new PerWorker(_name, mon);
		break;

	case eWork::DAYWORK:

		cout << "--- �Ͽ��� ��� ---" << endl;
		cout << endl;
		cout << "�̸� : ";
		cin >> _name;
		cout << "�ٹ��ϼ�: ";
		cin >> daycount;
		cout << "�ϴ�(��): ";
		cin >> daymon;

		pWorker = new DayWorker(_name, daycount, daymon);
		break;

	case eWork::PARTWORK:

		cout << "--- ��ƮŸ�� ��� ---" << endl;
		cout << endl;
		cout << "�̸� : ";
		cin >> _name;
		cout << "�ٹ��ϼ�: ";
		cin >> WorkT;
		cout << "�ϴ�(��): ";
		cin >> Tmon;

		pWorker = new PartTWorker(_name, WorkT, Tmon);
		break;

	}

	return pWorker;
}
