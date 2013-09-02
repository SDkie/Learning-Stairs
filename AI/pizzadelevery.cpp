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
    printf("Enter No. of Devices: ");
    scanf("%d",&n);
    printf("\nEnter Propogation delay: \n");
    for( i=0;i<n;i++)
    {
        printf("\n Enter Elements of Row # : %d\n",i+1);
        for( j=0;j<n;j++)
        scanf("%d",&a[i][j]);
        visited[i]=0;
    }
    printf("\n\nThe  list is:\n\n");
    for( i=0;i<n;i++)
    {
        printf("\n\n");
        for( j=0;j<n;j++)
        printf("\t%d",a[i][j]);
    }
    cout<<"\nEnter Source router and destination router:";
    cin>>start>>end;
    start--;
    end--;
}

void UCS()
{
     int check=0;
     nodes.push(Nodes(start,0));
     visited[start]=0;
     while(check==0) 
     check=expand();
}
int expand()
{
    Nodes node= nodes.top();
   
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
       cout<<"Minimum delay from source to destination device:"<<node.cost;
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
