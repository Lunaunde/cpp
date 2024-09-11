#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, a[20], x_d, y_d, z;
    long long x, y;//乐，用int会溢出
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            x = a[j];
            y = a[j + 1];
            x_d = 1; y_d = 1;
            while (x >= 10)
            {
                x /= 10;
                x_d++;
            }
            while (y >= 10)
            {
                y /= 10;
                y_d++;
            }
            x = a[j]*pow(10,(y_d))+a[j+1];
            y = a[j + 1] * pow(10, (x_d)) + a[j];
            if (x < y)
            {
                z = a[j];
                a[j] = a[j + 1];
                a[j + 1] = z;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}