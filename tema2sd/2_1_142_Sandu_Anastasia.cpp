#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int x[], int n, int i)
{
    int maxx = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && x[left] > x[maxx])
        maxx = left;

    // If right child is larger than largest so far
    if (right < n && x[right] > x[maxx])
        maxx = right;

    // If largest is not root
    if (maxx != i)
    {
        swap(x[i], x[maxx]);

        // Recursively heapify the affected sub-tree
        heapify(x, n, maxx);
    }
}

// main function to do heap sort
void heapSort(int x[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(x, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(x[0], x[i]);

        // call max heapify on the reduced heap
        heapify(x, i, 0);
    }
}
int main()
{
    int x[100],n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>x[i];
    heapSort(x, n);
    for(int i=0; i<n; i++)
        cout<<x[i]<<" ";
    return 0;
}
