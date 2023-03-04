#include <iostream>
#include <string>

using namespace std;
string stringarray(string x)
{
    string y = "";
    for (char i = 'a'; i <= 'z'; i++)
    {
        int len = x.length();
        string a(1, i);
        if (x.find(a) < len)
        {
            int p = x.find(a);
            y.append(a);
            while (x.find(a, p + 1) < len)
            {
                int c = x.find(a, p + 1);
                y.append(a);
                p = c;
            }
        }
    }
    return y;
}
void interschimbare(string &a, string &b)
{
    string aux;
    aux=a;
    a=b;
    b=aux;
}
int main()
{
    string arr[100], y, x[100];
    int n;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, y);
        arr[i] = stringarray(y);
        x[i] = y;
    }
    bool ok;
    int m = n;
    do
    {
        ok = 1;
        int p = m;
        for (int i = 0; i < p - 1; i++)
            if (arr[i] > arr[i + 1])
            {
                interschimbare(x[i],x[i+1]);
                interschimbare(arr[i],arr[i+1]);
                ok = 0;
                m = i + 1;
            }
    } while (!ok);
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    return 0;
}
