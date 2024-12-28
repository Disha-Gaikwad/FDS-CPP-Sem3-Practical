//Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. 
//Order once placed cannot be cancelled. Write C++ program to simulate the system using circular queue using array.

#include<iostream> 
#include<cstdlib>
using namespace std;
class pizza
{
    int front,rear,q[5];
    public:
    pizza()
    {
        front=-1;
        rear=-1;
    }
    int isfull()
    { 
        if((front==0&&rear==4)||(front==rear==-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isempty()
    {
        if(front==-1&&rear==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void add()
    {
        if(isfull()==0)
        {
            cout<<"\n Enter the pizza ID:";
            if(front==-1&&rear==-1)
            {
                front=0;
                rear=0;
                cin>>q[rear];
                
            }
            else
            {
                rear=(rear+1)%5;
                cin>>q[rear];
            }
            
        
        
        char c;
        cout<<"Do you want to add another order ?";
        cin>>c;
        if(c=='y'||c=='Y')
        add();
        }
        else
        {
            cout<<"\nOrder are full";
        }
    }
    void serve()
    {
        if(isempty()==0)
        {
            if(front==rear)
            {
                cout<<"\nOrder Served is : "<<q[front];
                front=-1;
                rear=-1;
            }
            else
            {
                  cout<<"\nOrder Served is : "<<q[front];
                front=(front+1)%5;;
            }
        }
        else
        {
            cout<<"\nOrders are empty";
        }
    }
    void display()
    {
        if(isempty()==0)
        {
            for(int i=front;i!=rear;i=(i+1)%5)
            {
                cout<<q[i]<<" ";
            }
            cout<<q[rear];
            
        }
        else
        {
            cout<<"\nOrders are empty";
        }
    }
    void check()
    {
        int ch;
        cout<<"\n\n ****PIZZA PARLOUR****\n\n";
        cout<<"1.Add a pizza \n2.Display the order \n3. Serve a pizza \n4.Exit\n\n Enter your Choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            add();
            break;
            
            case 2:
            display();
            break;
            
            case 3:
            serve();
            break;
            
            case 4:
            exit(0);
            
            default:
            cout<<"Invalid Choice";
            
            check();
            
        }
        char ch1;
        cout<<"\nDo you want to continue ?";
        cin>>ch1;
        if(ch1=='y'||ch1=='Y')
        check();
    }
};
int main()
{
    pizza p1;
    p1.check();
    return 0;
}




