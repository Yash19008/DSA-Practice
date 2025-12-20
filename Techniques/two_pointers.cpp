#include <iostream>

using namespace std;

int isPalindrome(char *arr, int n)
{
    int l = 0, r = n - 2; // Ignore Null Char...

    while (l <= r)
    {
        if (arr[l] != arr[r])
        {
            return 0;
        }
        l++;
        r--;
    }

    return 1;
}

int main()
{
    char arr[] = "madam";
    int size = sizeof(arr) / sizeof(arr[0]);

    int isPalin = isPalindrome(arr, size);

    cout << ((isPalin == 1) ? "Palindrome!" : "Not Palindrome!") << endl;
}