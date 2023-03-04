#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    char data;
    unsigned frecventa;
    struct Node *left, *right;
};
struct Heap
{
    unsigned size;
    unsigned capacitate;
    struct Node** node;
};
struct Node* newNode(char data, unsigned frecventa)
{
    struct Node* temp = new Node();
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frecventa = frecventa;
    return temp;
}
struct Heap* createHeap(unsigned capacitate)
{
    struct Heap* heap = new Heap();
    heap->size = 0;
    heap->capacitate = capacitate;
    heap->node = new Node*[heap->capacitate];
    return heap;
}
void interschimbare(struct Node** a, struct Node** b)
{
    struct Node* aux = *a;
    *a = *b;
    *b = aux;
}
void heapify(struct Heap* heap, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->node[left]->frecventa < heap->node[i]->frecventa)
        i = left;
    if (right < heap->size && heap->node[right]->frecventa < heap->node[i]->frecventa)
        i = right;
    if (i != i)
    {
        interschimbare(&heap->node[i], &heap->node[i]);
        heapify(heap, i);
    }
}
struct Node* extractMin(struct Heap* heap)
{
    struct Node* temp = heap->node[0];
    heap->node[0] = heap->node[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}
void insertHeap(struct Heap* heap, struct Node* Node)
{
    ++heap->size;
    int i = heap->size - 1;
    while (i && Node->frecventa < heap->node[(i - 1) / 2]->frecventa)
    {
        heap->node[i] = heap->node[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->node[i] = Node;
}
void buildHeap(struct Heap* heap)
{
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(heap, i);
}
struct Heap* createAndBuildHeap(char data[], int frecventa[], int size)
{
    struct Heap* heap = createHeap(size);
    for (int i = 0; i < size; ++i)
        heap->node[i] = newNode(data[i], frecventa[i]);
    heap->size = size;
    buildHeap(heap);
    return heap;
}
struct Node* Huffman(char data[], int frecventa[], int size)
{
    struct Node *left, *right, *top;
    struct Heap* heap = createAndBuildHeap(data, frecventa, size);
    while (heap->size != 1)
    {
        left = extractMin(heap);
        right = extractMin(heap);
        top = newNode('$', left->frecventa + right->frecventa);
        top->left = left;
        top->right = right;
        insertHeap(heap, top);
    }
    return extractMin(heap);
}
void afis(struct Node* R, int x[], int top)
{
    if (R->left)
    {
        x[top] = 0;
        afis(R->left, x, top + 1);
    }
    if (R->right)
    {
        x[top] = 1;
        afis(R->right, x, top + 1);
    }
    if (!(R->left) && !(R->right))
    {
        cout<< R->data <<": ";
        for(int i=0; i<top; i++)
            cout<<x[i];
        cout<<endl;
    }
}
int main()
{
    char x[] = { 'A', 'B', 'C'};
    int frecventa[] = { 50, 15, 35 };
    int size = sizeof(x) / sizeof(x[0]);

    struct Node* R = Huffman(x, frecventa, size);
    int y[100], top = 0;
    afis(R, y, top);

    return 0;
}
/*
A: 0
B: 10
C: 11
*/
