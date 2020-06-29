#include <cstring>
#include <iostream>
using namespace std;

const int MAXN=1<<13;
int a[MAXN];
int sum[MAXN];

int max(int a, int b) {
    if(a<b) {
        return b;
    }
    else{
        return a;
    }
}

int dfs(int l, int idx, int n) {
    if(l>n) return 0;
    if(sum[idx]!=0) return sum[idx];
    return sum[idx]=a[idx]+max(dfs(l+1,idx+l,n),dfs(l+1,idx+l+1,n));
}
int main()                                
{
    // freopen("in_1163.txt","r",stdin);
    memset(sum,0,sizeof(sum));
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            cin>>a[i*(i-1)/2+j];
        }
    }
    int mx;
    mx=dfs(1,0,n);
    cout<<mx<<endl;
    return 0;
}
