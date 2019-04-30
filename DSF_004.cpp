#include<iostream>
using namespace std;
class node
{
    public:
int e;
node *l=NULL,*r=NULL;
};
class bst
{public:
int m[20];
int size;
node *root=NULL;
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
node* insert(node *temp,int data)
{
    if(temp==NULL){temp=new(node);temp->e=data;root=temp;}
    else
    {
        if(data<temp->e){temp->l=insert(temp->l,data);}
        else{temp->r=insert(temp->r,data);}
    }
    return temp;
}


void create()
{
    int i;
    for(i=0;i<size;i++)
    {
        root=insert(root,m[i]);
    }
}


void display()
{
cout<<"\nRoot is:"<<root->e;
}
void inorder(node *temp)
{
    if(temp==NULL){return;}
    inorder(temp->l);
    cout<<"\n"<<temp->e;
    inorder(temp->r);
}
void preorder(node *temp)
{
    if(temp==NULL){return;}
    cout<<"\n"<<temp->e;
    preorder(temp->l);
    preorder(temp->r);
}
/*node* swap_node(node *temp)
{
    if(temp!=NULL)
    {
        node *t;
        t=temp->l;
        temp->l=swap_node(temp->r);
        temp->r=swap_node(t);
    }
    return temp;

}*/

//My version
void swap_node(node *temp)
{
    if(temp!=NULL)
    {
        node *t;
        t=temp->l;
        temp->l=temp->r;
        temp->r=t;
        swap_node(temp->l);
        swap_node(temp->r);
    }
    return;
}
};

int main()
{
 bst a;
int i;
cout<<"\nEnter the number of entries:";
cin>>a.size;
for(i=0;i<a.size;i++)
{
cout<<"\nEnter the value:";
cin>>a.m[i];
}
a.create();
a.display();
cout<<"\nInorder is:";
a.inorder(a.root);
cout<<"\nPreorder is:";
a.preorder(a.root);
cout<<"\nSwapping:";
a.swap_node(a.root);
cout<<"\nInorder is:";
a.inorder(a.root);
cout<<"\nPreorder is:";
a.preorder(a.root);
return 0;
}



