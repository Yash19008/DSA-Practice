#include <iostream>
#include <algorithm>

using namespace std;

int findMaxSum(int *arr, int size, int k)
{
    int window_sum = 0;

    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    int max_sum = window_sum;

    for (int i = k; i < size; i++)
    {
        window_sum += arr[i];
        window_sum -= arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    int arr[] = {5, -1, 7, -2, 10, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3, maxSum = 0;

    maxSum = findMaxSum(arr, size, k);
    cout << maxSum << endl;
}