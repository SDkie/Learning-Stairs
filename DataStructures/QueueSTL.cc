#include<queue>
#include<iostream>
using namespace std;
	
class student
{
	char name[10];
	int rollnumber;
	public:
	void read()
	{
		cout<<"Enter name";
		cin>>name;
		cout<<"rollnumber";
		cin>>rollnumber;
	}
friend void display(deque<student> &v);
};
void display(deque<student> &v);
void display(deque<student> &v)
{
	deque<student>::iterator a;
	for(a=v.begin();a<v.end();a++)//remember this whole
	{
		cout<<a->rollnumber<<"\t"<<a->name<<"\n";
	}
}
int main()
{
	
	
	int choice;
	deque<student> a;
	student var;
	do
	{
		cout<<"Enter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				var.read();
				a.push_back(var);
				break;
			case 2:
				var.read();
				a.push_front(var);
				break;
			case 3:
				a.pop_back();
				break;
			case 4:
				a.pop_front();
				break;
			case 5:
				display(a);
				break;
		}
	}while(choice!=0);
}
