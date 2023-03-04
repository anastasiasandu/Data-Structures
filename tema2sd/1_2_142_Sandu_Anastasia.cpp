 #include <iostream>
using namespace std;

int index(int x[], int left, int right)
{

    int pivot = x[left], nr = 0;
    for (int i = left + 1; i <= right; i++)
        if (x[i] >= pivot)
            nr++;

    int pivotIndex = left + nr;
    swap(x[pivotIndex], x[left]);
    int i = left, j = right;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (x[i] >= pivot)
            i++;
        while (x[j] < pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(x[i++], x[j--]);
    }
    return pivotIndex;
}
void qSort(int x[], int left, int right)
{
    if (left >= right)
        return ;
    int pivotIndex = index(x, left, right);
    qSort(x, left, pivotIndex - 1);
    qSort(x, pivotIndex + 1, right);
}
int main()
{
    int x[100],n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    qSort(x, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout<<x[i]<<" ";
    return 0;
}
