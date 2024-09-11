#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct info
{
    string name;
    int year,month,day,time;
};
bool compareByTime(info &a,info &b) {
    return a.time < b.time;
}
int main()
{
    int n;
    info a[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
        a[i].time=a[i].year*10000+a[i].month*100+a[i].day;        
    }
    sort(a,a+n,compareByTime);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<endl;
    }
}