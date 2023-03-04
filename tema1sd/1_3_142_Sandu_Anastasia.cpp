#include <iostream>

using namespace std;

int main()
{
    int n, x[10000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    for(int i = 0 ; i < n - 1 ; i ++)
    {
        int p = i;
        for(int j = i + 1 ; j < n ; j ++)
            if(x[j] > x[p])
                p= j;
        int aux = x[i];
        x[i] = x[p];
        x[p] = aux;
    }
    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
