#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[1001];
int s[1001];
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        dp[i]=1;
        cin>>s[i];
    }
    memset(dp,0x3f,sizeof(dp));
    for (int i = 0; i < n; i++) {
        *lower_bound(dp,dp+n,s[i])=s[i];
    }
    
    cout<<lower_bound(dp,dp+n,0x3f3f3f3f)-dp;
    return 0;
}