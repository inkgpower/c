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
		cout << "1. 개좌개설\n";
		cout << "2. 입    금\n";
		cout << "3. 출    금\n";
		cout << "4. 출    력\n";
		cout << "5. 종    료\n";
		cout << "메뉴를 선택하세요. :";
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
	
	cout << "id를 입력하세요. :";
	cin >> a[count].id;
	cout << "이름을 입력하세요. :"; 
	cin >> a[count].name;
	cout << "금액을 입력하세요. :";
	cin >> a[count].chg;
	count++;
}

void cus :: disp()
{
	int i;
	for(i = 0; i < count; i++)
	{
		
	cout << "[개좌개설]\n"; 
	cout << "계좌ID :";
	cout << a[i].id << endl;
	cout << "이 름 :";
	cout << a[i].name << endl;
	cout << "입금액 :";
	cout << a[i].chg << endl;
	
	}
}

void cus :: in()
{
	
	int id, i, in;
	
	cout << "id를 입력하세요. :";
	cin >> id;
	cout << "입금할 금액을 입력하세요.:";
	cin >> in;
	for(i = 0; i < count; i++)
	if(id == a[i].id)
	{
	a[i].chg += in;
	cout << "입금완료.\n";
	return;
	}

	
}

void cus :: out()
{
	
	int id, i, in;
	
	cout << "id를 입력하세요. :";
	cin >> id;
	cout << "출금할 금액을 입력하세요.:";
	cin >> in;
	for(i = 0; i < count; i++)
	if(id == a[i].id)
	{
	a[i].chg -= in;
	cout << "출금완료.\n";
	return;
	}

	
}


