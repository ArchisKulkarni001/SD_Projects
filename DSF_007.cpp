
#include<iostream>
using namespace std;

class graph
{
public:
    int matrix[10][10],i,j;
    int vis[10],in[10],out[10],cost[10],edge,vertex,source,destination;

    graph()
    {

        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                matrix[i][j]=0;

            }
            vis[i]=0;
        }
    }
    void input()
    {
        int i;
        cout<<"\nEnter number of vertices and edges:";
        cin>>vertex>>edge;
        cout<<"\nEnter source and destination:";
        cin>>source>>destination;
        for(i=0;i<edge;i++)
        {
            cout<<"\nEnter data:";
            cin>>in[i]>>out[i]>>cost[i];
        }
        init_matrix();
    }
    void init_matrix()
    {
        for(i=0;i<edge;i++)
        {
            matrix[in[i]][out[i]]=cost[i];
            matrix[out[i]][in[i]]=cost[i];
        }

    }
    void path(int src,int dest)
    {
        for (i = 0; i < 10; i++)
            {cost[i] = 999;}
        cost[src]=0;
        int flag=0;
        while(flag==0)
     {

       int u;
       int min = 999;

        for (int v = 0; v < vertex; v++)
            {if (vis[v] == 0 && cost[v] <= min)
            {min = cost[v], u = v;} }
       vis[u] = 1;
       for (j= 0; j<vertex; j++)
       {
           if (vis[j]==0 && matrix[u][j]!=0 && cost[u]+matrix[u][j] < cost[j])
            {cost[j] = cost[u] + matrix[u][j];}
       }
       if(u==dest){flag=1;}

     }
     display(dest);
    }
    int stack[10];
    int t=-1;

    void push(int a)
    {
        t++;
        stack[t]=a;
    }
    int pop()
    {
        t--;
        return(stack[t+1]);
    }
 void display(int dest)
    {
        int i;
        for(i=0;i<10;i++)
        {
            if(cost[i]!=999 && vis[i]==1)
            {
                cout<<"\n"<<i<<". "<<cost[i];
            }

        }
        cout<<"\nTotal shortest distance:"<<cost[dest];
    }

};
int main()
{
graph m;
m.input();
m.path(m.source,m.destination);
return 0;
}

