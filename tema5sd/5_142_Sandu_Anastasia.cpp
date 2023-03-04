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
void AfisareSRD(Tree * R)
{
    if(R != NULL)
    {
        AfisareSRD(R->Left);
        cout << R->Data << " ";
        AfisareSRD(R->Right);
    }
}
Tree *LCA(Tree* R, int p, int q)
{
    if (R == NULL)
        return NULL;
    if (R->Data > p && R->Data > q)
        return LCA(R->Left, p, q);
    if (R->Data < p && R->Data < q)
        return LCA(R->Right, p, q);
    return R;
}
int main()
{
    int n,x,p,q;
    cin>>n;
    Tree* R=new Tree;
    R=NULL;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        Push(R,x);
    }
    cin>>p>>q;
    Tree* lca=LCA(R,p,q);
    cout<<lca->Data;
    return 0;
}

