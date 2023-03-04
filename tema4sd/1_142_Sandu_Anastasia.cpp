#include <iostream>

using namespace std;
struct node
{
    int data;
    int priority;
    node *next;
};
void afis(node * p)
{
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
node* Front=NULL;
node* rear=NULL;
void pop ()
{
    if (Front == NULL)
        cout<<"Underflow";
    else
    {
        int val = Front -> data;
        node *temp = Front;
        Front = Front -> next;
        delete temp;
        if (Front == NULL)
            rear = NULL;
    }
}
void push (int dat, int pri)
{
    node *p = new node ;
    if (p == NULL)
        cout<<"Overflow";
    else
    {
        p -> data = dat;
        p->priority=pri;
        p -> next = NULL;
        if (rear == NULL)
            Front = p;
        else
        {
            if(Front->priority>pri || Front==NULL)
            {
                p->next=Front;
                Front=p;
            }
            else
            {
                node* q=Front;
                while(q->next!=NULL && q->next->priority<=pri)
                    q=q->next;
                p->next=q->next;
                q->next=p;
            }
        }
        rear = p ;
    }
}
int main()
{
    push(6,2);
    push(15, 3);
    push(27, 1);
    push(31, 0);
    push(1098,0);
    afis(Front);
    cout<<endl;
    pop();
    afis(Front);
    return 0;
}
