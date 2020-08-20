#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int const MAXN = 1<<17;
int n, dat[2*MAXN - 1];

void init(int k) {
    n=1;
    while(n<k) n=n*2;
    for(int i=0;i<2*MAXN -1;i++) dat[i]=0;
}
void Set(int idx, int v) {
    idx += n-1;
    dat[idx]=v;
    // 向上更新
    while(idx>0) {
        idx=(idx-1)/2;
        dat[idx] = dat[idx*2+1]+dat[idx*2+2];
    }
}

int Sum(int k, int sum=0) {
    if(k==0) return sum;
    else {
        if(k%2) {sum=dat[k]+Sum((k-2)/2,sum);}
        else sum+=Sum((k-1)/2,sum);
    }
    return sum;
}


int main()                                
{
    int k=10;
    vector<int> L={9,1,-8,1,2,4,7,9,6,4};
    init(k);
    for(int i=0; i<k;i++) {
        Set(i,L[i]);
    }
    for(int i=0; i<2*n-1;i++) {
        printf("%d ", dat[i]);
    }
    printf("\n%d", Sum(1));
    return 0;                         
}     