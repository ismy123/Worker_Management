#pragma once
#include "Worker.h"
#include <list>
class WorkerM
{
protected:
	char _name[10];
public:
	int count = 0; //근로자 수

	list<Worker*> lt;
	list<Worker*>::iterator iterCur;


	void InputDefault();
	void Show(char* pname);
	void ShowAll();
	void Edit(char* pname);
	void Del(char* pname);
	void DelAll();
	int Save();
	int Load();

	void MainProcess()
	{
		int n1, n2;
		int done = 0;
		

		while (done != 1) 
		{
			system("cls");
			cout << "--- 작업을 선택하세요 ---" << endl;
			cout << endl;
			cout << "1. 근로자 등록  2. 조회  3. 편집  4. 삭제  5. txt  6. 종료" << endl;
			cout << ">> ";
			cin >> n1;
			cout << "------------------------" << endl;
			cout << endl;

			switch (n1)
			{
			case 1://등록
				if (count > 10) //근로자 10명 초과 시
				{
					cout << endl;
					cout << ">> FULL <<" << endl;
					break;
				}
				else
					InputDefault();
				++count;
				break;

			case 2://조회
				cout << "1. 선택조회 2. 전체조회" << endl;
				cout << ">> ";
				cin >> n2;
				cout << endl;

				if (n2 == 1)
				{
					system("cls");
					char name[10];
					cout << "조회하고자 하는 사람 이름  : ";
					cin >> name;
					Show(name);
				}
				else if (n2 == 2)
					ShowAll();

				break;

			case 3://편집
				system("cls");
				char name[10];
				cout << "--- 편집 ---" << endl;
				cout << "편집하고자 하는 사람 이름  : ";
				cin >> name;
				cout << endl;
				Edit(name);
				break;

			case 4://삭제
				cout << "1. 선택삭제 2. 전체삭제" << endl;
				cin >> n2;
				cout << endl;

				if (n2 == 1)
				{
					system("cls");
					cout << "--- 선택 삭제 ---" << endl;
					char name[10];
					cout << "삭제하고자 하는 사람 이름  : ";
					cin >> name;
					cout << endl;
					Del(name);

				}
				else if (n2 == 2)
				{
					system("cls");
					DelAll();
				}
				break;

			case 5://파일스트림
				system("cls");
				cout << "--- txt ---" << endl;
				cout << "--- 1. txt 저장  2. txt 불러오기 ---" << endl;
				cout << ">> ";
				cin >> n1;
				if (n1 == 1)
					Save();
				else if (n1 == 2)
					Load();
				else
					cout << "-잘못 입력하셨습니다.-" << endl;
				break;

			case 6://종료
				done = 1;
				break;
			}
				
		
		}
	}
};