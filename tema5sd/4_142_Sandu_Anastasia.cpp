#include <iostream>

using namespace std;

struct Tree
{
    string Data;
    Tree *Left;
    Tree *Right;
};
void Push(Tree * & R, string x)
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
        AfisareSRD(R->Right);
        cout << R->Data << " ";
        AfisareSRD(R->Left);
    }
}
int main()
{
    int n;
    string x;
    cin>>n;
    Tree* R=new Tree;
    R=NULL;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        Push(R,x);
    }
    AfisareSRD(R);
    return 0;
}
