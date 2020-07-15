#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5120;
int dp[MAXN][MAXN];

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}


int main() {
    string a;
    int n;
    cin>>n;
    cin>>a;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i-1]==a[n-j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<n-dp[n][n];
    return 0;
}