#include "Worker.h"
#include "WorkerManager.h"
void Worker::ShowInfo()
{
	cout << nameA << ")  " << Ename << " ... " << _mon << "원" << endl;
}

PerWorker::PerWorker(char* _name, int mon)
{
	_mon = mon;

	GetEm("정규직");
	GetName(_name);
	CalMoney();
}

DayWorker::DayWorker(char* _name, int daycount, int daymon)
{
	_daycount = daycount;
	_daymon = daymon;

	GetEm("일용직");
	GetName(_name);
	CalMoney();
}

PartTWorker::PartTWorker(char* _name, int WorkT, int Tmon)
{
	_WorkT = WorkT;
	_Tmon = Tmon;

	GetEm("파트타임");
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

		cout << "--- 정규직 등록 ---" << endl;
		cout << endl;
		cout << "이름 : ";
		cin >> _name;
		cout << "월급(원) : ";
		cin >> mon;

		pWorker = new PerWorker(_name, mon);
		break;

	case eWork::DAYWORK:

		cout << "--- 일용직 등록 ---" << endl;
		cout << endl;
		cout << "이름 : ";
		cin >> _name;
		cout << "근무일수: ";
		cin >> daycount;
		cout << "일당(원): ";
		cin >> daymon;

		pWorker = new DayWorker(_name, daycount, daymon);
		break;

	case eWork::PARTWORK:

		cout << "--- 파트타임 등록 ---" << endl;
		cout << endl;
		cout << "이름 : ";
		cin >> _name;
		cout << "근무일수: ";
		cin >> WorkT;
		cout << "일당(원): ";
		cin >> Tmon;

		pWorker = new PartTWorker(_name, WorkT, Tmon);
		break;

	}

	return pWorker;
}
