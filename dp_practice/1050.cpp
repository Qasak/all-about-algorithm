#include<iostream>
#include<cstring>

using namespace std;

int const MAXN=103;
int a[MAXN][MAXN];
int tmp[MAXN];


int main() {
    freopen("to_max.txt","r",stdin);
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    int mx=1<<31;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>a[i][j];
    }
    for (int i = 0; i < n; i++) {//i for starting rows
        memset(tmp,0,sizeof(tmp));
        
        // compass rows:
        for (int row = i; row < n; row++) {
            int sum=0;
            for (int col = 0; col < n; col++) {
                tmp[col]+=a[row][col];
            }
            for (int p = 0; p < n; p++) {
                // sum=sum>0?sum+tmp[p]:tmp[p];
                sum=max(sum+tmp[p],tmp[p]);
                if(mx<sum)
                mx=sum;
            }
        }
    }
    cout<<mx;
    return 0;
}