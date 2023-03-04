#include <iostream>

using namespace std;

struct Tree {
int Data;
Tree *Left;
Tree *Right;
};
void Push(Tree * & R, int x)
{
    if(R != NULL)
    {
        if(R->Data == x)
            return;
        else
            if(R->Data > x)
                Push(R->Left , x);
            else
                Push(R->Right , x);
    }
    else
    {
        R = new Tree;
        R->Data = x;
        R->Left = NULL;
        R->Right = NULL;
    }
}
void AfisareSRD(Tree * R)
{
    if(R != NULL)
    {
        AfisareSRD(R->Left);
        cout << R->Data << " ";
        AfisareSRD(R->Right);
    }
}
void AfisareRSD(Tree * R)
{
    if(R != NULL)
    {
        cout << R->Data << " ";
        AfisareRSD(R->Left);
        AfisareRSD(R->Right);
    }
}
void AfisareSDR (Tree * R)
{
    if(R != NULL)
    {
        AfisareSDR (R->Left);
        AfisareSDR (R->Right);
        cout << R->Data << " ";
    }
}
int main()
{
    int n,x;
    cin>>n;
    Tree* R=new Tree;
    R=NULL;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        Push(R,x);
    }
    AfisareSRD(R);
    cout<<"\n";
    AfisareRSD(R);
    cout<<"\n";
    AfisareSDR(R);
    return 0;
}
