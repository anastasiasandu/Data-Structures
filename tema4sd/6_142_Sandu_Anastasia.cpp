#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
node* rear;
node* Front;
int pop ()
{
    if (Front == NULL)
        cout<<"Underflow";
    else
    {
        int x = Front -> data;
        node *temp = Front;
        Front = Front -> next;
        delete temp;
        if (Front == NULL)
            rear = NULL;
    }
}
void push (int dat)
{
    node *p = new node;
    if (p == NULL)
        cout<<"Overflow";
    else
    {
        p -> data = dat;
        p -> next = NULL;
        if (rear == NULL)
            Front = p;
        else
            rear -> next = p;
        rear = p;
    }
}
int main()
{
    int a,n,capacity=0,l1= 0, l2 = 0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        push(a);
    }
    while(Front!=rear)
    {
        if(Front->data < rear->data)
        {
            if(Front->data > l1)
                l1=Front->data;
            else
                capacity+=l1-Front->data;
            pop();
        }
        else
        {
            if(rear->data>l2)
                l2=rear->data;
            else
                capacity+=l2-rear->data;
            node* o;
            node* q=Front;
            while(q!=rear)
            {
                o=q;
                q=q->next;
            }
            rear=o;
        }
    }
    cout<<capacity;
    return 0;
}
