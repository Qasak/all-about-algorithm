#include<iostream>
#include<cstring>

using namespace std;
int const MAXN=101;
int dp[101][101];

int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j]=dp[i][j-1]+dp[i-1][j];
        }        
    }
    cout<<dp[n-1][m];
    return 0;
}