#include <iostream>

using namespace std;

int pozitie(int x[], int left, int right)
{
    int a=1,aux;
    while(left<right)
    {
        if(x[left]>x[right])
        {
            aux=x[left];
            x[left]=x[right];
            x[right]=aux;
            a=1-a;
        }
        if(a==0)
            right--;
        else left++;
    }
    return left;
}
void insertie(int x[], int left, int right)
{
  for(int i=left+1; i<right+1; i++)
  {
             int element = x[i] ;
             int j = i ;
             while (j>left && x[j-1]> element)
             {
                 x[j]= x[j-1] ;
                 j-= 1;
             }
             x[j]= element ;
  }
}
void hibridqsort(int x[], int left, int right)
{
    while (left < right)
    {
        if (right-left  <= 11)
        {
            insertie(x, left, right);
            break;
        }
        else
        {
            int pivot = pozitie(x, left, right) ;
            if (pivot-left<right-pivot)
            {
                hibridqsort(x, left, pivot - 1);
                left = pivot + 1;
            }
            else
            {
                hibridqsort(x, pivot + 1, right);
                right = pivot-1;
            }
        }
    }
}
int main()
{
    int n, x[100];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    hibridqsort(x, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
