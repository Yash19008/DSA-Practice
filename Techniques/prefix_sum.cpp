#include <iostream>
#include <vector>
using namespace std;

int prefixSum(int *arr, int n, int i, int j)
{
    vector<int> sums(n);
    sums[0] = arr[0];

    for (int k = 1; k < n; k++)
    {
        sums[k] = sums[k - 1] + arr[k];
    }

    if (i == 0)
        return sums[j];
    else
        return sums[j] - sums[i - 1];
}

int prefixSumInPlace(int *arr, int n, int i, int j)
{
    for (int k = 1; k < n; k++)
    {
        arr[k] = arr[k - 1] + arr[k];
    }
    if (i == 0)
        return arr[j];
    else
        return arr[j] - arr[i - 1];
}

int main()
{
    int arr[] = {5, 60, 4, 2, 3, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int i = 2, j = 5;
    int sumOfRange = prefixSum(arr, size, i, j);

    cout << sumOfRange << endl;
}