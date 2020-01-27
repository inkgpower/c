#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

using namespace std;

class person
{
	private :
		string s[2];
		int n;
	public :
		person()
			{
				s[0] = "player 1>>"; s[1] = "player 2>>"; n = -1;
			}
				
		string getname()
		{
			n++;
			return s[n%2];
		}
};

class upanddowngame
{
	private :
		int result = 0;
		int low = 0, high = 99;
	public :
		void game();
};

upanddowngame g;
person player;

int main(void)
{
	g.game();
	return 0;
}



void upanddowngame :: game()
{
	

	int n1, a, b;
	srand(time(NULL));
	n1 = rand()%100;

	while(1)
	{
	cout << player.getname();
	cin >> a;
	if(a < n1)
	cout << "답은" << a << "와" << high << "사이에 있습니다.\n";
	else
	cout << "답은" << low << "와" << a << "사이에 있습니다.\n";
	if(a > n1)
	high = a;
	else if(a < n1)
	low = a;
	else
	{
	cout << "승리했습니다.";
	break;
	}
	}
	
	
	
	
}
