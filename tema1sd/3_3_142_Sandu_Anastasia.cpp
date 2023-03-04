#include <iostream>

using namespace std;
int x[10000],n,a;
int CB(int i, int j)
{
    if(i > j)
        return -1;
    else
    {
        int m =(i+j)/2;
        if(x[m]>x[m+1])
            return m+1;
        if(x[m]<x[m-1])
            return m;
        if (x[i]>x[m])
            return CB(i, m-1);
        return CB(m+1, j);
    }
}
int cb(int i, int j, int a)
{
    if(i > j)
        return -1;
    else
    {
        int m =(i+j)/2;
        if(a == x[m])
            return m;
        if(a < x[m])
            return cb(i, m-1, a);
        else
            return cb(m+1, j, a);
    }
}
int main()
{
    cin>>n;
    int i;
    for(i=0; i<n; i++)
        cin>>x[i];
    cin>>a;
    int index=CB(0,n-1);
    if(a<=x[n-1] && a>=x[index+1])
        cout<<cb(index+1,n-1,a);
    else cout<<cb(0,index,a);
    return 0;
}
