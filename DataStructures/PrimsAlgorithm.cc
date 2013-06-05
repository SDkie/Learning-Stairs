#include<iostream>
#define SIZE 10
using namespace std;
class Matrix
{
	int nodes[SIZE][SIZE];
	int visited[SIZE];
	int vertices;  
	int edges;
	public:
		Matrix()
		{
			int i,j;
			for(i=0;i<SIZE;i++)
			{
				for(j=0;j<SIZE;j++)
				{
					nodes[i][j]=0;
				}
			}
		}
		void read();
		void prims();
};
void Matrix::prims()
{
	Matrix a;
	cout<<"Enter starting vertices";
	int v,j,i,p;
	cin>>v;
	cout<<v;
	for(i=0;i<vertices;i++)//clear visited
		visited[i]=0;
		
		visited[v]=1;
		cout<<v;
		int source=v,dest;
		unsigned  w;
	for(p=1;p<vertices;p++)//count
	{
		w=65535;
		for(i=0;i<vertices;i++)
		{
			if(visited[i]==0)//important condition
				continue;
			for(j=0;j<vertices;j++)
			{ 
				if(nodes[i][j]==0)
					continue;
				if(nodes[i][j]>w)
					continue;
				if(visited[i]==1&&visited[j]==1)
					continue;
				
				w=nodes[i][j];
				source=i;
				dest=j;
			}
		}
		visited[source]=1;
		visited[dest]=1;
		cout<<source<<"->"<<dest<<"{"<<w<<"}";
	}
}
void Matrix::read()
{
	cout<<"Enter vertices";
	cin>>vertices;
	cout<<"Enter edges";
	cin>>edges;
	int i,j;
	int w,source,dest;
	for(i=0;i<edges;i++)
	{
		cout<<"Enter source";
		cin>>source;
		cout<<"Enter desti";
		cin>>dest;
		if(source>=vertices||dest>=vertices)
		{
			cout<<"error";
			i--;
			continue;
		}
		cout<<"Enter weight";
		cin>>w;
		nodes[source][dest]=w;
		nodes[dest][source]=w;
	}
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			cout<<nodes[i][j]<<"\t";;
		}
		cout<<"\n";
	}
}
int main()
{
	Matrix m;
	m.read();
	m.prims();
	return 0;
}
