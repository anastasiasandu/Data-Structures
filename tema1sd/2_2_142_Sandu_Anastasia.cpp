#include <iostream>

using namespace std;
int x[10000],n,a;
int CB(int i, int j, int a)
{
    if(i > j)
        return -1;
    else
    {
        int m =(i+j)/2;
        if(a == x[m])
            return m;
        if(a < x[m])
            return CB(i, m-1, a);
        else
            return CB(m+1, j, a);
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    cin>>a;
    cout<<CB(0,n-1,a);
    return 0;
}
