#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
node* inserare(node *head, int x)
{
    node *q,*last, *oldlast;
    q=new node;
    q->data=x;
    q->next=NULL;
    if(head==NULL)
        {
            head=q;
        }
    else
    {
        oldlast=NULL;
        last=head;
        while(last)
        {
            oldlast=last;
            last=last->next;
        }
        if(oldlast)
            oldlast->next=q;
        else
        {
            oldlast=q;
            head->next=oldlast;
        }
    }
    return head;
}
void creareLista(node* &head, int a)
{
    head=NULL;
    while(a)
    {
        head=inserare(head,a%10);
        a/=10;
    }
}
void afis(node * q)
{
    while(q)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
}
int rezultat(node* head, node* head1)
{
    int res=0, p=1;
    while( head && head1)
    {
        res+= p* head->data + p* head1->data;
        p*=10;
        head=head->next;
        head1=head1->next;
    }
    while(head)
    {
        res+= p* head->data;
        p*=10;
        head=head->next;
    }
    while(head1)
    {
        res+= p* head1->data;
        p*=10;
        head1=head1->next;
    }
    return res;
}
int main()
{
    int a,b;
    cin>>a>>b;
    node* head=new node;
    creareLista(head,a);
    node* head1=new node;
    creareLista(head1,b);
    cout<<rezultat(head, head1);
    return 0;
}
