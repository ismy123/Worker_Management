#include "Worker.h"
#include "WorkerManager.h"
#include <stdio.h>
#include <fstream>
#include <string>


void WorkerM::InputDefault() //���
{
	system("cls");
	int n;
	
	
	cout << "--- �ٷ��� ��� ---" << endl;
	
	cout << endl;
	cout << "--- 1.������  2.�Ͽ���  3.��ƮŸ�� ---" << endl;
	cout << "���Ÿ�� : ";
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
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << endl;
		break;
	}

	cout << "--- ��� �Ϸ� ---" << endl;
	getchar();
	getchar();
	
}

void WorkerM::ShowAll() //��ü��ȸ
{
	system("cls");
	int i = 1;
	cout << "--- ��ü ��ȸ ---" << endl;
	cout << "�� " << lt.size() << "���� ������ ��ϵǾ� �ֽ��ϴ�." << endl;
	cout << endl;

	for (iterCur = lt.begin(); iterCur != lt.end(); iterCur++)
	{
		cout << endl;
		cout << "--- " << i << " ---" << endl;
		Worker* p = (*iterCur);
		p->ShowInfo();
		++i;
	}
	cout << "--- ��ȸ �Ϸ� ---" << endl;
	getchar();
	getchar();

}


void WorkerM::Show(char* pname) //������ȸ
{
	
	cout << "--- ���� ��ȸ ---" << endl;
	for (iterCur = lt.begin(); iterCur != lt.end(); ++iterCur)
	{
		Worker* p = (*iterCur);
		if (strcmp(p->GetName(), pname) == 0)
		{
			p->ShowInfo();
			break;
		}

	}
	cout << "--- ��ȸ �Ϸ� ---" << endl;
	getchar();
	getchar();
}


void WorkerM::Edit(char* pname) //����
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
			cout << "�����ϰ��� �ϴ� ����" << endl;
			cout << "1.�̸�  2.�ٷ���  3.����  4.��������" << endl;
			cin >> n3;
			switch (n3)
			{
			case 1:
				cout << "--- �̸� ���� ---" << endl;
				cout << p->GetName() << " -> ";
				
				cin >> name;
				p->GetName(name);
				break;
			
			case 2:

				char* editN;
				int editM;
				editN = p->GetName(); //�̸� ���� ����
				editM = p->GetMon(); //���� ���� ����

				cout << "--- �ٷ��� ���� ---" << endl;
				cout << "1.������  2.�Ͽ���  3.��ƮŸ��" << endl;
				cout << p->GetEm() << " -> ";
				cin >> n4;
				switch (n4)
				{
				case 1:
					lt.erase(iterCur); //���� ��� ����
					p = new PerWorker(editN,editM); // ������ ������ �� ������ ����
					lt.push_back(p); // ������ �� �����͸� ����Ʈ�� �߰�
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
					cout << "--- �ٽ� �Է��ϼ��� ---" << endl;
					break;
				}
				
				
				break;

			case 3:

				cout << "--- ���� ���� ---" << endl;
				cout << p->GetMon() << " -> ";
				cin >> m;
				p->GetMon(m);
				break;

			case 4:
				break;

			default:
				cout << "�ٽ� �Է��ϼ���." << endl;
			}
			break;
		}
	}
	cout << "--- ���� �Ϸ� ---" << endl;
	cout << endl;
	getchar();
	getchar();
}

void WorkerM::Del(char* pname) //���û���
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
	cout << "--- ���� �Ϸ� ---" << endl;
	getchar();
	getchar();
}

void WorkerM::DelAll() //��ü����
{
	cout << "--- ��ü ���� ---" << endl;
	lt.clear();
	cout << "--- ���� �Ϸ� ---" << endl;
	cout << endl;
	getchar();
	getchar();

}


int WorkerM::Save() //���Ͻ�Ʈ�� - txt ����
{

	ofstream fout;
	fout.open("Worker.txt");
	
	for (iterCur = lt.begin(); iterCur != lt.end(); iterCur++)
	{
		Worker* p = (*iterCur);
		fout << p->GetEm() << " "<< p->GetName() <<" "<<  p->GetMon() << "����"<< endl;
	}
	cout << " - �Ϸ� - ";
	fout.close();
	getchar();
	getchar();
	return 0;

}

int WorkerM::Load() //���Ͻ�Ʈ�� - txt �о����
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
	cout << " - �Ϸ� - ";

	getchar();
	getchar();
	return 0;
}