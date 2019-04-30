#include<iostream>
using namespace std;
struct node
{
char e;
node *l=NULL,*r=NULL;
};
class bst
{public:
node *root=NULL,*in=NULL;
node *stack[10];
int t=-1;
void push(node *a)
{
t++;
stack[t]=a;
}
node *pop()
{
t--;
return(stack[t+1]);
}
void create(char m[],int size)
{int i,c;
char b;
node *temp1;
for(i=0;i<size;i++)
{
b=m[i];
c=check(b);
if(c==2)
{
node *n;n=new(node);n->e=b;push(n);temp1=n;
}
else
{
node *n;n=new(node);n->e=b;n->r=pop();n->l=pop();push(n);temp1=n;
}
}
root=temp1;
}

int check(char a)
{
if(a=='+'||a=='-'||a=='*'||a=='/'){return 1;}
else{return 2;}
}

void display()
{
cout<<"\nRoot is:"<<root->e;
}
void inorder(node *temp)
{
    if(temp==NULL){return;}
    inorder(temp->l);
    cout<<temp->e;
    inorder(temp->r);
}
void preorder(node *temp)
{
    if(temp==NULL){return;}
    cout<<temp->e;
    preorder(temp->l);
    preorder(temp->r);
}
};

int main()
{
 bst a;
int size,i;
char m[20];
cout<<"\nEnter the size of expression:";
cin>>size;
for(i=0;i<size;i++)
{
cout<<"\nEnter the value:";
cin>>m[i];
}
a.create(m,size);
a.display();
cout<<"\nInorder is:";
a.inorder(a.root);
cout<<"\nPreorder is:";
a.preorder(a.root);
return 0;
}



