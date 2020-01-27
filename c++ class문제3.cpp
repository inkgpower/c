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
	cout << "재고가 떨어졌습니다.!\n";
	break;
	}
	}
	order[ct].disp();
	machine.calc();
	
	 
	return 0;
}

void c1 :: getname()
{
	cout << "주문하실 제품의 개수를 입력하세요. :";
	cin >> order[ct].count;
	cout << "고객님의 성함을 입력하세요. :";
	cin >> order[ct].name;
	ct++;
	
}

void c2 :: sold()
{
	
	cout << "자판기의 재고량과 개당 가격을 입력(ex. 20 1000)";
	cin >> machine.investing >> machine.unit_price;
	
}
void c1 :: disp()
{
	int i;
	for(i = 0; i < 3; i++)
	cout << order[i].name << "님께서 주문하신 주스의 개수 :" << order[i].count << endl;
}


void c2 :: calc()
{
	int i, sum;
	sum = 0;
	
	for(i = 0; i < ct; i++)
	sum += order[i].get_count();
	
	cout << "========================================================\n";
	cout << "총 수익은" << machine.unit_price * sum << "입니다.\n"; 
	if(machine.investing <= 0)
	cout << "남은 제품의 수는 0 개 입니다.\n";
	else
	cout << "남은 제품의 수는" << machine.investing - sum << "입니다.\n";
		
}

