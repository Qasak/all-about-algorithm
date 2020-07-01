#include<iostream>
#include<cstring>
using namespace std;

int const MAXN=101;
int row[MAXN];
int main() {
    int mx=1<<31;
    int sum=0;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>row[i];
    }
    for (int i=0;i<n;i++)
    {
        sum=max(row[i], row[i]+sum);
        if(sum>mx)
        mx=sum;
    }
    cout<<mx;
    return 0;
}