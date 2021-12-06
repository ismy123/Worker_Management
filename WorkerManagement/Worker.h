#pragma once
#include <iostream>
#include <string>
#pragma warning( disable : 4996 )
using namespace std;

class Worker
{
protected:

	string Ename; //근로직 이름
	char nameA[10]; //사람 이름
	int _mon = 0; //money

public:
	
	Worker() {};
	virtual ~Worker() {};
	Worker( string Ename, char* name, int mon ) {}
	
	void ShowInfo();

	void GetEm(string emName) { Ename = emName; }; // 근로직 이름
	string GetEm() { return Ename; }

	void GetName(char* _name) { strcpy(nameA, _name); } // 사람 이름
	char *GetName() { return nameA; }

	void GetMon(int mon) { _mon = mon; } // 월급
	int GetMon() { return _mon; }

	
	virtual void CalMoney() = 0; //순수 가상 함수 - 구현은 자식에서


};

class PerWorker : public Worker //정규직 클래스
{
public:
	PerWorker(char* _name, int mon);
	virtual ~PerWorker() {};
	virtual void CalMoney() {} 
};

class DayWorker : public Worker //일용직 클래스
{
protected:
	int _daycount = 0; //근무일수
	int _daymon = 0; //일당

public:
	DayWorker(char* _name, int daycount, int daymon);
	virtual ~DayWorker() {};
	virtual void CalMoney() { _mon = _daycount * _daymon; } 

};

class PartTWorker : public Worker //파트타임 클래스
{
protected:
	int _WorkT; //근무시간
	int _Tmon; //시급
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

class WorkerFactory //팩토리 패턴
{
public:
	WorkerFactory() {};
	virtual ~WorkerFactory() {};

	Worker* Create(eWork work);
};

