#include<stdio.h>
#include<conio.h>
#include<queue.h>
#include<iostream>
using namespace std;

int a[10][10],visited[10],n,cost=0;
int start,end,mincost=-1;

class Nodes
{
      public:
      int node;
      int cost;
      
             Nodes(int n,int c)
             {
                 node=n;
                 cost=c;
             }       
             const bool operator <(const Nodes& pW) const
             {
                return (cost > pW.cost);
             }
};
std::priority_queue<Nodes> nodes;
int expand();
void UCS();
void get()
{
    int i,j;
    printf("Enter No. of Nodes: ");
    scanf("%d",&n);
    printf("\nEnter Cost Matrix: \n");
    for( i=0;i<n;i++)
    {
        printf("\n Enter Elements of Row # : %d\n",i+1);
        for( j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        visited[i]=0;
    }
    printf("\n\nThe cost list is:\n\n");
    for( i=0;i<n;i++)
    {
        printf("\n\n");
        for( j=0;j<n;j++)
        printf("\t%d",a[i][j]);
    }
    cout<<"enter start and end";
    cin>>start>>end;
}

void UCS()
{
     int check=0;
     nodes.push(Nodes(start,0));
     visited[start]=0;
     cout<<nodes.size();
     while(check==0) 
     check=expand();
}
int expand()
{
    Nodes node= nodes.top();
    getch();
    if(nodes.size()==0)
    {
             cout<<"error";
             getch();
             return 0;
    }                  
    nodes.pop();
    if(visited[node.node]==1)
         return 0;
    else 
         visited[node.node]=1;
         
    if(node.node==end)
    {
       cout<<"finalcost"<<node.cost;
       return 1;
    }
    else
    {
        for(int j=0;j<n;j++)
        {
           if(a[j][node.node]!=0)
           {
                nodes.push(Nodes(j,node.cost+a[j][node.node]));
           }
        }    
        
    }
   return 0;
}
main()
{
    get();
    UCS();
    getch();
}

/*
Enter No. of Nodes: 4

Enter Cost Matrix:

 Enter Elements of Row # : 1
0 1 3 12

 Enter Elements of Row # : 2
1 0 0 5

 Enter Elements of Row # : 3
3 0 0 6

 Enter Elements of Row # : 4
12 5 6 0

The cost list is:



        0       1       3       12

        1       0       0       5

        3       0       0       6

        12      5       6       0

enter start and end :0 3

finalcost-6
*/
