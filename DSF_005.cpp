#include<iostream>
using namespace std;
/*
The Graph taken as input in this program is like this

            0 - 4 - 1
                |
                3
                |
                2

*/
class graph
{
public:
    int a[5][5],i,j;
    int vis[5],points[5]={0,1,2,3,4};

    graph()
    {

        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                a[i][j]=0;
            }
        }
        a[0][4]=a[1][4]=a[2][3]=a[1][2]=a[4][3]=1;
        a[4][0]=a[4][1]=a[3][2]=a[2][1]=a[3][4]=1;
        for(j=0;j<4;j++)
            {
                vis[j]=0;
            }
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
    void DFS()
    {
        push(points[0]);
        //t=-1;
        while(t!=-1)
        {
            int v=pop();
            if(vis[v]==0)
            {
                cout<<" "<<v;
                vis[v]=1;
                int i;
                for(i=0;i<5;i++)
                {
                    if(vis[i]==0 && a[v][i]==1){push(i);}
                }
            }
        }
    }
};
int main()
{
 graph a;
 cout<<"\nElements are:0 1 2 3 4";
 cout<<"\nDepth first search is:\n";
a.DFS();

return 0;
}
