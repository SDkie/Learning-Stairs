//working fine

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
		void krus();
};
void Matrix::krus()
{
	int k[20][3];
	int i,j;
	int father[vertices];
	for(i=0;i<vertices;i++)
		father[i]=i;
	int count=0;
	for(i=0;i<vertices;i++)//i<<<j every time  inside array
	{
		for(j=i+1;j<vertices;j++)
		{
			if(nodes[i][j])
			{
				k[count][0]=i;
				k[count][1]=j;
				k[count][2]=nodes[i][j];
				count++;
			}
		}
	}
	int temp;
	for(i=0;i<count;i++)  //sort
	{
		for(j=i+1;j<count;j++)
		{
			if(k[i][2]>k[j][2])//swap
			{
				temp=k[i][2];
				k[i][2]=k[j][2];
				k[j][2]=temp;
				
				temp=k[i][1];
				k[i][1]=k[j][1];
				k[j][1]=temp;
				
				temp=k[i][0];
				k[i][0]=k[j][0];
				k[j][0]=temp;
			}
		}
	}
	int p=0,l,m;
	for(i=0;i<vertices-1;p++)   //we have vertices-1 number of edges
	{
		if(father[k[p][0]]!=father[k[p][1]])
		{
			cout<<"\n"<<k[p][0]<<"--->"<<k[p][1]<<"("<<k[p][2]<<")"<<"\n";
			i++;//found
			//now father for all k[p][1] is k[p][0]
				int replace=father[k[p][1]];
			for(l=0;l<vertices;l++)
			{
				if(father[l]==replace)
					father[l]=father[k[p][0]];
			}
			for(m=0;m<vertices;m++)
			{
				cout<<father[m]<<"\t";
			}
		}
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
	m.krus();
	return 0;
}
//7 9 0 1 9 0 2 3 3 2 1 1 5 3 3 5 7 3 4 4 4 6 14 5 6 8 2 6 11
