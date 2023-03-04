#include <iostream>
#include <math.h>

using namespace std;
struct node
{
    int grade, coef;
    node *next;
};
void citire(int &n, int x[])
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
}
node* inserare(node *head, int x, int i)
{
    node *q,*last, *oldlast;
    q=new node;
    q->grade=i;
    q->coef=x;
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
void creare(int &n, int x[], node* &head)
{
    head=NULL;
    for(int i=0; i<n; i++)
        head=inserare(head,x[i],i);
}
void afis(node * q)
{
    while(q)
    {
        cout<<q->grade<<" "<<q->coef<<endl;
        q=q->next;
    }
}
void inmultireScalar(node* &head)
{
    int s;
    cout<<"\nTastati scalarul: "<<endl;
    cin>>s;
    node *q;
    q=head;
    while(q)
    {
        q->coef = q->coef * s;
        q=q->next;
    }
}
int calculPunct(node *head)
{
    int x0;
    cout<<"\nTastati punctul x0: "<<endl;
    cin>>x0;
    int res=0;
    while(head)
    {
        res+= head->coef * pow(x0,head->grade);
        head=head->next;
    }
    cout<<"\nPolinomul in punctul "<<x0<<" este: ";
    return res;
}
void calculSuma(node* head, node * head1, node * &head2)
{
    node *q;
    int coeficient, grad;
    head2=NULL;
    while(head && head1 )
    {
        coeficient = head->coef+head1->coef;
        grad= head->grade;
        head2=inserare(head2, coeficient, grad);
        head=head->next;
        head1=head1->next;
    }
    while(head)
    {
        coeficient=head->coef;
        grad=head->grade;
        head2=inserare(head2, coeficient, grad);
        head=head->next;
    }
    while(head1)
    {
        coeficient=head1->coef;
        grad=head1->grade;
        head2=inserare(head2, coeficient, grad);
        head1=head1->next;
    }
}
int main()
{
    int P[100],Q[100],n,m;
    node *head , *head1, *head2;
    citire(n,P);
    citire(m,Q);
    creare(n,P,head);
    creare(m,Q,head1);
    cout<<"\nPolinoamele au fost create: "<<endl;
    afis(head);
    afis(head1);
    inmultireScalar(head);
    cout<<"\nDupa inmultire: "<<endl;
    afis(head);
    cout<<calculPunct(head);
    calculSuma(head,head1,head2);
    cout<<"\nSuma polinoamelor este: "<<endl;
    afis(head2);
    return 0;
}
