#include <iostream>
using namespace std;
int main()
{
    char ch = ' ', chs[100];
    int s = -1;
    while (ch != ']')
    {
        cin >> ch;
        if (ch >= 65 && ch <= 90)
            chs[++s] = ch;
    }
    cout << "/";
    for (int i = 0; i <= s; i++)
    {
        chs[i]+=32;
        cout << chs[i];
    }
    return 0;
}