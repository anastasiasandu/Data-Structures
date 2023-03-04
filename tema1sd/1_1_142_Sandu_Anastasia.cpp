#include <iostream>

using namespace std;

int main()
{
    int n, x[10000];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    bool ok;
    int m = n;
    do
    {
        ok = 1;
        int p = m;
        for(int i = 0 ; i < p - 1 ; i++)
            if(x[i] > x[i+1])
            {
                int aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
                ok = 0;
                m = i + 1;
            }
    }while(!ok);
    for (int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
