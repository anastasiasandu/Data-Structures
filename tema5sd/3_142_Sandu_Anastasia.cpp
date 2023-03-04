#include <iostream>

using namespace std;

struct Tree
{
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
        else if(R->Data > x)
            Push(R->Left, x);
        else
            Push(R->Right, x);
    }
    else
    {
        R = new Tree;
        R->Data = x;
        R->Left = NULL;
        R->Right = NULL;
    }
}
void AfisareSRD(Tree * R, int k1, int k2)
{
    if(R != NULL)
    {
        AfisareSRD(R->Left,k1,k2);
        if(k1 <= R->Data && R->Data <= k2)
            cout << R->Data << " ";
        AfisareSRD(R->Right,k1,k2);
    }
}
int main()
{
    int n,x,k1,k2;
    cin>>n;
    Tree* R=new Tree;
    R=NULL;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        Push(R,x);
    }
    cin>>k1>>k2;
    AfisareSRD(R, k1, k2);
    return 0;
}

