#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
node* Top=NULL;
void pop ()
{
    if (Top == NULL)
        cout<<"Underflow";
    else
    {
        int val = Top -> data;
        node *temp = Top;
        Top = Top -> next;
        delete temp;
    }
}
void push (int dat)
{
    node *p = new node ;
    if (p == NULL)
        cout<<"Overflow";
    else
    {
        p -> data = dat;
        p -> next = Top;
        Top=p;
    }
}
int main()
{
    int n,pereche[100];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>pereche[i];
        if(Top==NULL)
            push(pereche[i]);
        else
        {
            if(pereche[i]==Top->data)
                pop();
            else push(pereche[i]);
        }
    }
    if(Top==NULL)
        cout<<"Configuratie valida";
    else cout<<"Configuratie invalida";
    return 0;
}
