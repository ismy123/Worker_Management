#pragma once
#include "Worker.h"
#include <list>
class WorkerM
{
protected:
	char _name[10];
public:
	int count = 0; //�ٷ��� ��

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
			cout << "--- �۾��� �����ϼ��� ---" << endl;
			cout << endl;
			cout << "1. �ٷ��� ���  2. ��ȸ  3. ����  4. ����  5. txt  6. ����" << endl;
			cout << ">> ";
			cin >> n1;
			cout << "------------------------" << endl;
			cout << endl;

			switch (n1)
			{
			case 1://���
				if (count > 10) //�ٷ��� 10�� �ʰ� ��
				{
					cout << endl;
					cout << ">> FULL <<" << endl;
					break;
				}
				else
					InputDefault();
				++count;
				break;

			case 2://��ȸ
				cout << "1. ������ȸ 2. ��ü��ȸ" << endl;
				cout << ">> ";
				cin >> n2;
				cout << endl;

				if (n2 == 1)
				{
					system("cls");
					char name[10];
					cout << "��ȸ�ϰ��� �ϴ� ��� �̸�  : ";
					cin >> name;
					Show(name);
				}
				else if (n2 == 2)
					ShowAll();

				break;

			case 3://����
				system("cls");
				char name[10];
				cout << "--- ���� ---" << endl;
				cout << "�����ϰ��� �ϴ� ��� �̸�  : ";
				cin >> name;
				cout << endl;
				Edit(name);
				break;

			case 4://����
				cout << "1. ���û��� 2. ��ü����" << endl;
				cin >> n2;
				cout << endl;

				if (n2 == 1)
				{
					system("cls");
					cout << "--- ���� ���� ---" << endl;
					char name[10];
					cout << "�����ϰ��� �ϴ� ��� �̸�  : ";
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

			case 5://���Ͻ�Ʈ��
				system("cls");
				cout << "--- txt ---" << endl;
				cout << "--- 1. txt ����  2. txt �ҷ����� ---" << endl;
				cout << ">> ";
				cin >> n1;
				if (n1 == 1)
					Save();
				else if (n1 == 2)
					Load();
				else
					cout << "-�߸� �Է��ϼ̽��ϴ�.-" << endl;
				break;

			case 6://����
				done = 1;
				break;
			}
				
		
		}
	}
};