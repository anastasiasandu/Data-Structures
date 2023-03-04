#include <iostream>
#include <string>

using namespace std;
int bs(string arr[], int i, int j, string x)
{
    if (j >= i)
    {
        int m = i + (j - i) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] == "")
        {
            int res1 = bs(arr, i, m - 1, x);
            if (res1 != -1)
                return res1;
            return bs(arr, m + 1, j, x);
        }
        if (arr[m].compare(x) > 0)
            return bs(arr, i, m - 1, x);

        return bs(arr, m+ 1, j, x);
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    string arr[100],y;
    cin.get();
    for (int i = 0; i<n; i++)
    {
        getline(cin, y);
        arr[i] = y;
    }
    string x;
    getline(cin, x);
    int index = bs(arr, 0, n-1,x);
    if (index == -1)
        cout << -1;
    else
        cout << index;
    return 0;
}
