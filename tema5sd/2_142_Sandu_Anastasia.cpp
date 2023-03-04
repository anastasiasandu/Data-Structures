#include <iostream>

using namespace std;

struct Tree {
int Data;
Tree *Left;
Tree *Right;
};
void pop(Tree * & p, Tree * & R)
{
    if(p->Right)
        pop(p -> Right , R);
    else
    {
        R->Data = p->Data;
        Tree * temp = p;
        p = p->Left;
        delete temp;
    }
}
void Pop(Tree * & R , int x)
{
    if(R != NULL)
    {
        if(R->Data == x)
        {
            // nodul trebuie șters
            if(R->Left == NULL && R->Right == NULL)
            {
                delete R;
                R = NULL;
            }
            else
                if(R->Right == NULL)
                {
                    Tree * temp = R;
                    R = R->Left;
                    delete temp;
                }
                else
                    if(R->Left == NULL)
                    {
                        Tree * temp = R;
                        R = R->Right;
                        delete temp;
                    }
                    else
                        pop(R->Left, R);
        }
        else
            if(R->Data > x)
                Pop(R->Left , x);
            else
                Pop(R->Right , x);
    }
    else
        return;
}
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
    cin>>x;
    Pop(R,x);
    AfisareSRD(R);
    return 0;
}
