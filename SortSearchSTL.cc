//insert end
//delete specified
//sort
//find record
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
class student
{
	public:
	int roll;
	char name[10];
	void read()
	{
		cout<<"enter data";
		cin>>roll;
		cin>>name;
	}
};
int main()
{
	int choice;
	list<student> l;
	list<student>::iterator ptr;
	student s1;
	do
	{
		cout<<"enter choice";
		cin>>choice;
		switch(choice)
		{
			case 1://insert back
				s1.read();
				l.push_back(s1);
				break;
			case 2://searc
				cout<<"Enter rollno";
				cin>>s1.roll;
				ptr=find(l.begin(),l.end(),s1);
				if(ptr->roll==s1.roll)
					cout<<"found";
				else
					cout<<"not found";
				break;
			case 3://delete
				cout<<"Enter rollno";
				cin>>s1.roll;
				ptr=find(l.begin(),l.end(),s1);
				if(ptr->roll==s1.roll)
					cout<<"found";
				else
					cout<<"not found";
				l.remove(*ptr);
				
				break;
			case 4://sort
				l.sort();
				break;
			case 5://display
				for(ptr=l.begin();ptr!=l.end();ptr++)
					cout<<ptr->roll<<"\t"<<ptr->name<<"\n";;
				break;
		}
	}while(choice!=0);
}
bool operator==(student s1,student s2)
{
	return(s1.roll==s2.roll);
		
}
bool operator<(student s1,student s2)
{
	return(s1.roll<s2.roll);
}
