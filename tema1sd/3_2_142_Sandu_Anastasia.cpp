#include <iostream>

using namespace std;
void interschimbare(int &a, int &b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}
int main()
{
    int n, i, h[1000],w[1000],l,lmax,imax;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>h[i];
        cin>>w[i];
    }
    bool ok;
    int m = n;
    do
    {
        ok = 1;
        int p = m;
        for(int i = 0 ; i < p - 1 ; i++)
            if(h[i] < h[i+1] && w[i] <= w[i+1])
            {
                interschimbare(h[i],h[i+1]);
                interschimbare(w[i],w[i+1]);
                ok = 0;
                m = i + 1;
            }
    }
    while(!ok);
    l=1;
    lmax=1;
    for(i=1; i<n; i++)
    {
        if(h[i] <= h[i-1] && w[i] <= w[i-1])
            l++;
        else
        {
            if(lmax<l)
            {
                lmax=l;
                imax=i;
            }
            l=1;
        }
    }
    if (lmax<l) {
        lmax=l;
        imax=i;
    }
    for(i=imax-lmax; i<imax; i++)
        cout<<h[i]<<" "<<w[i]<<endl;
    cout<<endl;
    return 0;
}
