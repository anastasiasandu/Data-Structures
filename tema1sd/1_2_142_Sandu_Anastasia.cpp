#include <iostream>

using namespace std;

int main()
{
    int n, x[10000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    for(int i = 1 ; i < n ; i ++)
    {
        int a = x[i];
        int p = i - 1;
        while(p >= 0 && x[p] > a)
        {
            x[p + 1] = x[p];
            p--;
        }
        x[p + 1] = a;
    }
    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
