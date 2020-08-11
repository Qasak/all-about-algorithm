#include<iostream>
#include<cstring>

using namespace std;
int const MAXN=101;
long bc[MAXN][MAXN];

long binomial_coefficient(int n, int m) {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            bc[i][j]=bc[i-1][j-1]+bc[i-1][j];
        }
    }
    return bc[n][m];
}

int main() {
    int n,m;
    cin>>n>>m;
    for (int i = 0; i <= n; i++) 
        bc[i][0]=1;
    for (int i = 0; i <= n; i++) 
        bc[i][i]=1;
    cout<<binomial_coefficient(n,m);
    return 0;
}