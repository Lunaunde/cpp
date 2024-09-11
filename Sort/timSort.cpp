#include <iostream>
using namespace std;
int a[100000];
void timSort(int start, int end)
{
    int b[100000], c[100000], d, mid = (start + end) / 2;
    if (start + 16 < end)
    {
        timSort(start, mid);
        timSort(mid + 1, end);
        for (int i = start; i <= mid; i++)
        {
            b[i - start] = a[i];
        }
        for (int i = mid + 1; i <= end; i++)
        {
            c[i - mid - 1] = a[i];
        }
        int i = 0, j = 0, k = start;
        while (i < mid - start + 1 && j < end - mid)
        {
            if (b[i] <= c[j])
            {
                a[k] = b[i];
                i++;
            }
            else
            {
                a[k] = c[j];
                j++;
            }
            k++;
        }
        while (i < mid - start + 1)
        {
            a[k] = b[i];
            i++;
            k++;
        }
        while (j < end - mid)
        {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (a[i] <= a[j])
                {
                    d = a[i];
                    for (int k = i; k > j; k--)
                    {
                        a[k] = a[k - 1];
                    }
                    a[j] = d;
                    break;
                }
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    timSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}