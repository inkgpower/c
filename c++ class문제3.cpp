#include <iostream>

using namespace std;

class c1
{
	private :
		int count;
		string name;
	public :
		int get_count(){return count;}
	
		void getname();
		void disp();
						
};
class c2
{
	private :
		int investing;
		int unit_price;
		int all;
	public :
		int get_investing(){return investing;}
		void sold();
		void calc();
		void check();
	
};

int ct = 0;
c1 order[10];
c2 machine; 

int main(void)
{
	int sum = 0;
	int i;
	machine.sold();
	while(1)
	{
	
	order[ct].getname();

	for(i = 0; i < ct; i++)
	sum += order[i].get_count();
	
	
	if(order[ct].get_count() == 0)
	{
	machine.calc();
	}
	
	
	
	if(machine.get_investing() - sum < 0)
	{
	cout << "��� ���������ϴ�.!\n";
	break;
	}
	}
	order[ct].disp();
	machine.calc();
	
	 
	return 0;
}

void c1 :: getname()
{
	cout << "�ֹ��Ͻ� ��ǰ�� ������ �Է��ϼ���. :";
	cin >> order[ct].count;
	cout << "������ ������ �Է��ϼ���. :";
	cin >> order[ct].name;
	ct++;
	
}

void c2 :: sold()
{
	
	cout << "���Ǳ��� ����� ���� ������ �Է�(ex. 20 1000)";
	cin >> machine.investing >> machine.unit_price;
	
}
void c1 :: disp()
{
	int i;
	for(i = 0; i < 3; i++)
	cout << order[i].name << "�Բ��� �ֹ��Ͻ� �ֽ��� ���� :" << order[i].count << endl;
}


void c2 :: calc()
{
	int i, sum;
	sum = 0;
	
	for(i = 0; i < ct; i++)
	sum += order[i].get_count();
	
	cout << "========================================================\n";
	cout << "�� ������" << machine.unit_price * sum << "�Դϴ�.\n"; 
	if(machine.investing <= 0)
	cout << "���� ��ǰ�� ���� 0 �� �Դϴ�.\n";
	else
	cout << "���� ��ǰ�� ����" << machine.investing - sum << "�Դϴ�.\n";
		
}

