#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
struct info
{
    string name;
    int score;
    int level;
};
bool compareByscore(info &a,info &b) {
    return a.score > b.score;
}
int main()
{
    int n;
    info a[10000];
    string name2[10000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name>>name2[i]>>a[i].score>>a[i].level;
    }
    sort(a,a+n,compareByscore);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].name<<" "<<name2[i]<<" "<<a[i].level<<endl;
    }
    return 0;
}