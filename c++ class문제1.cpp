#include <iostream>




using namespace std;


int count = 0;

class cus
{
	private :
		int id;
		int chg;
		string name;
	
	public :
		void set_cus(int _id, int _chg, string _name)
		{
			id = _id;
			chg = _chg;
			name = _name;
		}

		static void add();
		static void disp();
		void in();
		void out();
		
};

cus a[10];

int main(void)
{
	
	int menu;
	
	
	while(1)
	{
		cout << "\n-----Menu-----\n";
		cout << "1. ���°���\n";
		cout << "2. ��    ��\n";
		cout << "3. ��    ��\n";
		cout << "4. ��    ��\n";
		cout << "5. ��    ��\n";
		cout << "�޴��� �����ϼ���. :";
		cin >> menu;
	
	
	switch(menu)
	{
		case 1 : cus :: add(); break;
		case 2 : a[count].in(); break;
		case 3 : a[count].out(); break; 
		case 4 : cus :: disp(); break;
		case 5 : exit(0);
	}
	
	
	}
	return 0;
}

void cus :: add()
{
	
	cout << "id�� �Է��ϼ���. :";
	cin >> a[count].id;
	cout << "�̸��� �Է��ϼ���. :"; 
	cin >> a[count].name;
	cout << "�ݾ��� �Է��ϼ���. :";
	cin >> a[count].chg;
	count++;
}

void cus :: disp()
{
	int i;
	for(i = 0; i < count; i++)
	{
		
	cout << "[���°���]\n"; 
	cout << "����ID :";
	cout << a[i].id << endl;
	cout << "�� �� :";
	cout << a[i].name << endl;
	cout << "�Աݾ� :";
	cout << a[i].chg << endl;
	
	}
}

void cus :: in()
{
	
	int id, i, in;
	
	cout << "id�� �Է��ϼ���. :";
	cin >> id;
	cout << "�Ա��� �ݾ��� �Է��ϼ���.:";
	cin >> in;
	for(i = 0; i < count; i++)
	if(id == a[i].id)
	{
	a[i].chg += in;
	cout << "�ԱݿϷ�.\n";
	return;
	}

	
}

void cus :: out()
{
	
	int id, i, in;
	
	cout << "id�� �Է��ϼ���. :";
	cin >> id;
	cout << "����� �ݾ��� �Է��ϼ���.:";
	cin >> in;
	for(i = 0; i < count; i++)
	if(id == a[i].id)
	{
	a[i].chg -= in;
	cout << "��ݿϷ�.\n";
	return;
	}

	
}


