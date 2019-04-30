#include<iostream>
using namespace std;
struct node
{
    int key=0,value=0;
};
class table_main
{
    public:
    node a[10];
    int size=10;
    void insert_variable(int numbers)
    {
        int counter=0;
        int index=numbers%10;
        if(a[index].value==0){a[index].key=index;a[index].value=numbers;}
        else
        {
            while(a[index].value!=0)
                {
                    if(counter<size)
                    {
                        if(index>=size)
                            {index=0;}
                        else
                            {index++;counter++;}
                    }
                    else{break;}

                }
            if(counter<10){a[index].key=index;a[index].value=numbers;}
            else{cout<<"\nTable is full.";}
        }
        display();
    }
    void update()
    {
        int key,m;
        cout<<"\nEnter key to be updated and its value:";
        cin>>key>>m;
        a[key].key=key;
        a[key].value=m;
        display();
    }
    void delete_data()
    {
        int key,m;
        cout<<"\nEnter key to be deleted:";
        cin>>key;
        a[key].value=0;
        display();
    }
    void display()
    {
        int i;
        for(i=0;i<size;i++)
        {
            if(a[i].key!=0 && a[i].value!=0)
            cout<<"\n"<<a[i].key<<". "<<a[i].value;
        }
    }


};
int main()
{
    table_main m;
    int choice,fla=0,v;
    while(fla==0)
    {
        cout<<"\n1.Insert\n2.Update\n3.Delete\nEnter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\nEnter value:";
                    cin>>v;
                    m.insert_variable(v);
                    break;
            case 2:m.update();break;
            case 3:m.delete_data();break;
            default:fla=1;break;
        }
    }
}

