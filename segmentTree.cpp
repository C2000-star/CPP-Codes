#include <iostream>
using namespace std;
int createSegmentTree(int A[], int l, int r, int i, int sT[])
{
    if (l == r)
    {
        sT[i] = A[l];
        return sT[i];
    }
    int mid = (l + r) / 2;
    sT[i] = createSegmentTree(A, l, mid, 2 * i + 1, sT) + createSegmentTree(A, mid + 1, r, 2 * i + 2, sT);
    return sT[i];
}
int querySegmentTree(int A[], int l, int r, int ql, int qr, int i, int sT[])
{
    if (ql <= l && qr >= r)
    {
        return sT[i];
    }
    if (qr < l || ql > r)
    {
        return 0;
    }
    int mid = (l + r) / 2;
    return querySegmentTree(A, l, mid, ql, qr, 2 * i + 1, sT) + querySegmentTree(A, mid + 1, r, ql, qr, 2 * i + 2, sT);
}
void updateSegmentTree(int A[], int l, int r, int pos, int i, int diff, int sT[])
{
    if (pos < l || pos > r)
        return;
    sT[i] += diff;
    if (l != r)
    {
        int mid = (l + r) / 2;
        updateSegmentTree(A, l, mid, pos, 2 * i + 1, diff, sT);
        updateSegmentTree(A, mid + 1, r, pos, 2 * i + 2, diff, sT);
    }
}
int main()
{
    int n = 8;
    int A[] = {3, 1, 5, 11, 4, 6, 8, 11};
    int sT[2 * n - 1];
    sT[0] = createSegmentTree(A, 0, n - 1, 0, sT);
    std::cout << querySegmentTree(A, 0, n - 1, 1, 7, 0, sT) << std::endl;
    int newVal = 23;
    int diff = newVal - A[3];
    A[3] = 23;
    updateSegmentTree(A, 0, n - 1, 3, 0, diff, sT);
    std::cout << querySegmentTree(A, 0, n - 1, 1, 7, 0, sT);
}