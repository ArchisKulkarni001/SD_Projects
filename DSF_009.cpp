#include<iostream>
using namespace std;
struct node
{
    int key=0,value=0;
    node *next=NULL;
};
class table_main
{
    public:
    node **a;
    int size=10;
    table_main()
    {
        int i;
        a=new (node*[10]);
        for(i=0;i<10;i++)
        {
            a[i]=new(node);
        }
    }
    void insert_variable(int numbers)
    {

        int counter=0;
        int index=numbers%10;
        if(a[index]->next==NULL)
            {
                node *nnode;
                nnode=new(node);
                nnode->value=numbers;
                nnode->key=index;
                a[index]->next=nnode;
            }
        else
        {
            node *temp;
            temp=a[index];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node *nnode;
            nnode=new(node);
            nnode->value=numbers;
            nnode->key=index;
            temp->next=nnode;
        }
    }
    void delete_data()
    {
        int key,m,value;
        cout<<"\nEnter key and value to be deleted:";
        cin>>key>>value;
        node *temp=a[key],*prev=NULL;
        while(temp->value!=value)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
    }
    void display()
    {
        int i;
        node *temp;
        for(i=0;i<size;i++)
        {
            if(a[i]->next!=NULL)
            {
                temp=a[i]->next;
                while(temp!=NULL)
                {
                    cout<<"\n"<<temp->key<<". "<<temp->value;
                    temp=temp->next;
                }
            }

        }
    }
    void search_value()
    {
        int m=1,value,i=0;
        cout<<"\nEnter value to be searched:";
        cin>>value;
        node *temp=a[value%10]->next;
        while(temp!=NULL)
        {
            if(temp->value==value){i=1;break;}
            m++;
            temp=temp->next;
        }
        if(i==1)
        cout<<"Element found at:\nKey:"<<value%10<<"\nLocation:"<<m;
        else{cout<<"\nNot found!";}
    }

};
int main()
{
    table_main m;
    int choice,fla=0,v;
    while(fla==0)
    {
        cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nEnter value:";
                    cin>>v;
                    m.insert_variable(v);
                    break;
            case 2:m.search_value();break;
            case 3:m.delete_data();break;
            case 4:m.display();break;
            default:fla=1;break;
        }
    }
}


