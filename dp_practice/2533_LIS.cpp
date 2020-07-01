#include<iostream>
#include<cstring>

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
    for (int i = 1; i < n; i++) {
        int mx=1;
        for (int j = 0; j < i; j++) {
            if(s[j]<s[i]) {
                if(mx < dp[j] + 1) {
                    mx=dp[j] + 1;
                }
            } 
        }
        dp[i]=mx;
    }
    int mx=0;
    for (int i = 0; i < n; i++) {
        if(mx<dp[i])
        mx=dp[i];
    }
    cout<<mx;
    return 0;
}