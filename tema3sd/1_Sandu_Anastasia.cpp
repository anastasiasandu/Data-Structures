#include <iostream>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    node *next;
};
void citire(int &n, int x[])
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
}
node* inserare(node *head, int x)
{
    node *q, *oldq, *nextq;
    q=new node;
    q->data=x;
    q->next=NULL;
    if(head==NULL)
    {
        head=q;
    }
    else
    {
        oldq=NULL;
        nextq=head;
        while(nextq && x>=nextq->data)
        {
            oldq=nextq;
            nextq=nextq->next;
        }
        if(nextq==NULL)
            oldq->next=q;
        else
        {
            if(oldq)
            {
                q->next=oldq->next;
                oldq->next=q;
            }
            else
            {
                q->next=head;
                head=q;
            }
        }

    }
    return head;
}
void creare(int &n, int x[], node* &head)
{
    head=NULL;
    for(int i=0; i<n; i++)
        head=inserare(head,x[i]);
}
void stergereToataLista(node* &head)
{
    while(head)
    {
        node *q;
        q=head;
        head = head->next;
        delete q;
    }
}
void stergereElement(node* &head, int &a)
{
    cout<<"\nIntroduceti elementul care doriti sa fie sters: "<<endl;
    cin>>a;
    node *p;
    p=head;
    node *oldp;
    if(head->data == a)
    {
        node *q;
        q=head;
        head = head->next;
        delete q;
    }
    else
    {
        while (p && a != p -> data)
        {
            oldp=p;
            p = p -> next;
        }
        if (p == NULL)
            cout<<"\nElementul nu exista in lista"<<endl;
        else
        {
            node *q=p;
            oldp->next=p->next;
            delete q;
        }
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
int main()
{
    int n,x[100],a;
    node* head=new node;
    citire(n,x);
    creare(n,x,head);
    cout<<"Dupa ce a fost creata lista: "<<endl;
    afis(head);
    stergereElement(head,a);
    afis(head);
    stergereToataLista(head);
    cout<<"\nAu fost sterse toate elementele listei";
    return 0;
}
