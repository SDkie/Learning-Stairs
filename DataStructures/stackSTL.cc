#include<stack>
#include<iostream>
using namespace std;
int main()
{
	int i;
	stack<int> a;
	for(i=0;i<10;i++)
	{
		a.push(i);
	}
	int j;
	for(j=0;j<10;j++)
	{
		cout<<a.top();
		a.pop();
	}
}
