#include <iostream>

using namespace std;
void inserare(int a[], int &n, int k, int i)
{
    int j;
    for(j=n; j>i; j--)
        a[j]=a[j-1];
    a[i]=k;
    n++;
}
int main()
{
    int n,a[100],k,i,j,b[100],m;;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>a[i];
    cin>>m;
    for(i=0; i<m; i++)
        cin>>b[i];
    i=0; j=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
            i++;
        else inserare(a,n,b[j++],i++);
    }
    while(j<m)
        inserare(a,n,b[j++],i++);
    for(i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
