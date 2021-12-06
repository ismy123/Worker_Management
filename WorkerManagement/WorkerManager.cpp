#include "Worker.h"
#include "WorkerManager.h"
#include <stdio.h>
#include <fstream>
#include <string>


void WorkerM::InputDefault() //등록
{
	system("cls");
	int n;
	
	
	cout << "--- 근로자 등록 ---" << endl;
	
	cout << endl;
	cout << "--- 1.정규직  2.일용직  3.파트타임 ---" << endl;
	cout << "고용타입 : ";
	cin >> n;
	cout << endl;

	WorkerFactory w;
	switch (n)
	{
	case 1:
		lt.push_back(w.Create(eWork::PERWORK));
		break;

	case 2:
		lt.push_back(w.Create(eWork::DAYWORK));
		break;

	case 3:
		lt.push_back(w.Create(eWork::PARTWORK));
		break;

	default:
		cout << "잘못된 입력입니다." << endl;
		cout << endl;
		break;
	}

	cout << "--- 등록 완료 ---" << endl;
	getchar();
	getchar();
	
}

void WorkerM::ShowAll() //전체조회
{
	system("cls");
	int i = 1;
	cout << "--- 전체 조회 ---" << endl;
	cout << "총 " << lt.size() << "개의 정보가 등록되어 있습니다." << endl;
	cout << endl;

	for (iterCur = lt.begin(); iterCur != lt.end(); iterCur++)
	{
		cout << endl;
		cout << "--- " << i << " ---" << endl;
		Worker* p = (*iterCur);
		p->ShowInfo();
		++i;
	}
	cout << "--- 조회 완료 ---" << endl;
	getchar();
	getchar();

}


void WorkerM::Show(char* pname) //선택조회
{
	
	cout << "--- 선택 조회 ---" << endl;
	for (iterCur = lt.begin(); iterCur != lt.end(); ++iterCur)
	{
		Worker* p = (*iterCur);
		if (strcmp(p->GetName(), pname) == 0)
		{
			p->ShowInfo();
			break;
		}

	}
	cout << "--- 조회 완료 ---" << endl;
	getchar();
	getchar();
}


void WorkerM::Edit(char* pname) //편집
{
	
	int n3 = 0;
	int n4 = 0;

	for (iterCur = lt.begin(); iterCur != lt.end(); ++iterCur)
	{
		char name[10];
		int m;

		Worker* p = (*iterCur);
		if (strcmp(p->GetName(), pname) == 0)
		{
			cout << "편집하고자 하는 정보" << endl;
			cout << "1.이름  2.근로직  3.월급  4.편집종료" << endl;
			cin >> n3;
			switch (n3)
			{
			case 1:
				cout << "--- 이름 편집 ---" << endl;
				cout << p->GetName() << " -> ";
				
				cin >> name;
				p->GetName(name);
				break;
			
			case 2:

				char* editN;
				int editM;
				editN = p->GetName(); //이름 정보 복사
				editM = p->GetMon(); //월급 정보 복사

				cout << "--- 근로직 편집 ---" << endl;
				cout << "1.정규직  2.일용직  3.파트타임" << endl;
				cout << p->GetEm() << " -> ";
				cin >> n4;
				switch (n4)
				{
				case 1:
					lt.erase(iterCur); //기존 요소 삭제
					p = new PerWorker(editN,editM); // 직군을 변경해 새 데이터 생성
					lt.push_back(p); // 생성한 새 데이터를 리스트에 추가
					break;

				case 2:
					lt.erase(iterCur);
					p = new DayWorker(editN, editM,1);
					lt.push_back(p);
					break;

				case 3:
					lt.erase(iterCur);
					p = new PartTWorker(editN, editM,1);
					lt.push_back(p);
					break;

				default:
					cout << "--- 다시 입력하세요 ---" << endl;
					break;
				}
				
				
				break;

			case 3:

				cout << "--- 월급 편집 ---" << endl;
				cout << p->GetMon() << " -> ";
				cin >> m;
				p->GetMon(m);
				break;

			case 4:
				break;

			default:
				cout << "다시 입력하세요." << endl;
			}
			break;
		}
	}
	cout << "--- 편집 완료 ---" << endl;
	cout << endl;
	getchar();
	getchar();
}

void WorkerM::Del(char* pname) //선택삭제
{
	
	for (iterCur = lt.begin(); iterCur != lt.end(); ++iterCur)
	{
		Worker* p = (*iterCur);
		if (strcmp(p->GetName(), pname) == 0)
		{
			lt.erase(iterCur);
			break;
		}
	}
	cout << "--- 삭제 완료 ---" << endl;
	getchar();
	getchar();
}

void WorkerM::DelAll() //전체삭제
{
	cout << "--- 전체 삭제 ---" << endl;
	lt.clear();
	cout << "--- 삭제 완료 ---" << endl;
	cout << endl;
	getchar();
	getchar();

}


int WorkerM::Save() //파일스트림 - txt 저장
{

	ofstream fout;
	fout.open("Worker.txt");
	
	for (iterCur = lt.begin(); iterCur != lt.end(); iterCur++)
	{
		Worker* p = (*iterCur);
		fout << p->GetEm() << " "<< p->GetName() <<" "<<  p->GetMon() << "만원"<< endl;
	}
	cout << " - 완료 - ";
	fout.close();
	getchar();
	getchar();
	return 0;

}

int WorkerM::Load() //파일스트림 - txt 읽어오기
{
	char buffer[256];
	ifstream ifs("Worker.txt");

	if (!ifs.is_open())
	{
		cout << "Error opening file";
		exit(1);
	}
	while(!ifs.eof())
	{
		ifs.getline(buffer, 100);
		cout << buffer << endl;
	}
	cout << " - 완료 - ";

	getchar();
	getchar();
	return 0;
}