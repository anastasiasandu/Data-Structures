#include <iostream>

using namespace std;

int main()
{
    int x[1000],n,a,i;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>x[i];
    cin>>a;
    int ok=0;
    for(i=0; i<n; i++)
        if(x[i]==a)
        {
            ok=1;
            break;
        }
    if(ok)
        cout<<"Elementul se afla pe pozitia "<<i;
    else cout<<"Nu exista";
    return 0;
}
