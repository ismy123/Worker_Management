#pragma once
#include <iostream>
#include <string>
#pragma warning( disable : 4996 )
using namespace std;

class Worker
{
protected:

	string Ename; //�ٷ��� �̸�
	char nameA[10]; //��� �̸�
	int _mon = 0; //money

public:
	
	Worker() {};
	virtual ~Worker() {};
	Worker( string Ename, char* name, int mon ) {}
	
	void ShowInfo();

	void GetEm(string emName) { Ename = emName; }; // �ٷ��� �̸�
	string GetEm() { return Ename; }

	void GetName(char* _name) { strcpy(nameA, _name); } // ��� �̸�
	char *GetName() { return nameA; }

	void GetMon(int mon) { _mon = mon; } // ����
	int GetMon() { return _mon; }

	
	virtual void CalMoney() = 0; //���� ���� �Լ� - ������ �ڽĿ���


};

class PerWorker : public Worker //������ Ŭ����
{
public:
	PerWorker(char* _name, int mon);
	virtual ~PerWorker() {};
	virtual void CalMoney() {} 
};

class DayWorker : public Worker //�Ͽ��� Ŭ����
{
protected:
	int _daycount = 0; //�ٹ��ϼ�
	int _daymon = 0; //�ϴ�

public:
	DayWorker(char* _name, int daycount, int daymon);
	virtual ~DayWorker() {};
	virtual void CalMoney() { _mon = _daycount * _daymon; } 

};

class PartTWorker : public Worker //��ƮŸ�� Ŭ����
{
protected:
	int _WorkT; //�ٹ��ð�
	int _Tmon; //�ñ�
public:
	PartTWorker(char* _name, int WorkT, int Tmon);
	virtual ~PartTWorker() {};
	virtual void CalMoney(){ _mon = _WorkT * _Tmon; }
	
};

enum eWork
{
	PERWORK,
	DAYWORK,
	PARTWORK
};

class WorkerFactory //���丮 ����
{
public:
	WorkerFactory() {};
	virtual ~WorkerFactory() {};

	Worker* Create(eWork work);
};

