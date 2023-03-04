#include <iostream>
using namespace std;

void interclasare(int x[], int left, int middle, int right )
{

    int n1 = middle - left + 1;
    int n2 = right - middle;
    int A[n1], B[n2];

    for (int i = 0; i < n1; i++)
        A[i] = x[left + i];
    for (int j = 0; j < n2; j++)
        B[j] = x[middle + 1 + j];

    int i=0, j=0, k=left;
    while (i < n1 && j < n2)
    {
        if (A[i] <= B[j])
        {
            x[k] = A[i];
            i++;
        }
        else
        {
            x[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        x[k] = A[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        x[k] = B[j];
        j++;
        k++;
    }
}
void mergeSort(int x[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(x, left, middle);
        mergeSort(x, middle + 1, right);

        interclasare(x, left, middle, right);
    }
}

int main()
{
    int n, x[100];
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    mergeSort(x, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
