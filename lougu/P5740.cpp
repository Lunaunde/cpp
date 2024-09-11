#include<iostream>
#include <string>
using namespace std;
struct info
{
    string name;
    int math,eng,chinese,sum;
};
int main()
{
    int n,max=1;
    char ch;
    info a[1000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].name>>a[i].math>>a[i].eng>>a[i].chinese;
        a[i].sum=a[i].math+a[i].eng+a[i].chinese;
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i].sum>a[max].sum)
        {
            max=i;
        }
    }
    cout<<a[max].name<<' '<<a[max].math<<' '<<a[max].eng<<' '<<a[max].chinese;
}