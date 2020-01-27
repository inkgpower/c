#include <iostream>
using namespace std;

int ct = 0;
int ct1 = 0;
class student
{
	private :
		string name;
		string department;
	public :
	
		string get_name(){return name;}
		void set_name(string q){name = q;}
			
		string get_department(){return department;}
		void set_department(string w){name = w;}
		
		
};

class undergraduate : public student
{
	private : 
		int score;
		string grade;
	public	:
		
		int get_score(){return score;}
		void set_score(ing e){score = e;}
		
		string get_grade(){return grade;}
		void set_grade(string r){grade = r;}
		
		void disp1();
};

class graduate : public student
{
	private :
		string assistant;
		int scholarship;
	public	:
		
		string get_assistant(){return assistant;}
		void set_assistane(string t){assistant = t;}
	
		int get_scholarship(){return scholarship;}
		void set_scholarship(int y){scholarship = y;}
};		

undergraduate a[10];

int main(void)
{
	int select;
	
	while(1)
	{
	
	cout << "입력할 학생 신분 선택(1. 대학원생, 2. 대학생, 3. 종료) :";
	cin >> select; 
	switch(select)
	{
		case 1 : 
	}

	}
		
	return 0;
}





void undergraduate :: disp1()
{
	cout << "대학원 생 명단>\n";
	cout << "이    름 :";
	cout << a[ct].get_name();
	cout << "\n소속학과 :";
	cout << a[ct].get_department();
	cout << "\n점    수 :";
	cout << a[ct].get_score;
	cout << "\n학    점 :";
	cout << a[ct].get_grade;
	ct++;
}
