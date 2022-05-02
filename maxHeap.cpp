#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
class maxHeap
{
private:
    int _size{};
    vector<int> v = {-1};
    int p(int i) { return i >> 1; }
    int l(int i) { return i << 1; }
    int r(int i) { return (i << 1) + 1; }

public:
    bool isEmpty() const { return _size == 0; }
    int getMax() const { return v[1]; }
    void insert(int data);
    void shiftUp(int i);
    int extractMax();
    void shiftDown(int i);
};
void maxHeap::shiftUp(int i)
{
    if (i > _size)
        return;
    if (i == 1)
        return;
    if (v[i] > v[p(i)])
    {
        std::swap(v[p(i)], v[i]);
    }
    shiftUp(p(i));
}
void maxHeap::insert(int data)
{
    if (_size + 1 >= v.size())
    {
        v.push_back(0);
    }
    v[++_size] = data;
    shiftUp(_size);
    return;
}
void maxHeap::shiftDown(int i)
{
    if (i > _size)
        return;
    int swapId = i;
    if (l(i) <= _size && v[i] < v[l(i)])
    {
        swapId = l(i);
    }
    if (r(i) <= _size && v[swapId] < v[r(i)])
    {
        swapId = r(i);
    }
    if (swapId != i)
    {
        std::swap(v[i], v[swapId]);
        shiftDown(swapId);
    }
    return;
}
int maxHeap::extractMax()
{
    int max = v[1];
    std::swap(v[1], v[_size--]);
    shiftDown(1);
    return max;
}
int main()
{
    maxHeap *heap = new maxHeap();
    int x, value, max;
    while (1)
    {
        cout << "1.Build Heap\n2.Extract maximum\n3.Get maximum\n4.Check if heap is empty\nEnter choice: ";
        cin >> x;
        if (x == 1)
        {
            cout << "\nEnter data: ";
            cin >> value;
            heap->insert(value);
        }
        else if (x == 2)
        {
            max = heap->extractMax();
            cout << "\nExtracted element is: " << max;
        }
        else if (x == 3)
        {
            cout << "\nThe maximum element is: " << heap->getMax();
        }
        else if (x == 4)
        {
            if (heap->isEmpty())
            {
                cout << "\nYes heap is empty";
            }
            else
            {
                cout << "\nHeap is not empty";
            }
        }
        else
        {
            exit(1);
        }
    }
    return 1;
}