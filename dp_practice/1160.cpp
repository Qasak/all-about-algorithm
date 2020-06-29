#include <cstring>
#include <iostream>
using namespace std;

int vill[301];
int dp[301][31];
int w[301][301];


int abs(int a) {
    if(a<0) return -a;
    else return a;
}

int mid_sum(int a[], int l, int r) {
    int sum=0;
    int mid=l+(r-l)/2;
    for (int i = l; i <= r; i++)
    {
        int abs_dist=abs(a[i]-a[mid]);
        sum+=abs_dist;
    }
    return sum;
}

void input_vill(int V) {
    for (int i = 1; i <= V; i++)
    {
        cin>>vill[i];    
    }
}

int min(int a, int b) {
    if(a<b)
    return a;
    else
    return b;
}


void init_w(int V) {
    for (int i = 1; i <= V; i++)
    {
        for (int j = i; j <= V; j++)
        {
            w[i][j]=mid_sum(vill,i,j);
        }
    }
}

int run(int V, int P) {
    for (int i = 1; i<=V; i++)
    {
        for (int j = 1; j <= P && j <= i; j++)
        {
            for (int k = j-1; k <=i; k++)
            {
                dp[i][j]=min(dp[k][j-1]+w[k+1][i],dp[i][j]);
            }
        }
    }
    return dp[V][P];
}

int main() {
    int V,P;
    while(cin>>V>>P) {
        memset(dp,0x3f,sizeof(dp));
        memset(vill,0,sizeof(vill));
        memset(w,0,sizeof(w));
        input_vill(V); 
        dp[0][0]=0;
        init_w(V);
        cout<<run(V,P);
    }
    return 0;
}
