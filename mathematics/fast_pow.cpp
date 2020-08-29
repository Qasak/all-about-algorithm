#include<bits/stdc++.h>
using namespace std;

float fast_pow(float  m, int n) {
    float result=1;
    while(n) {
        if(n & 1)
            result = m * result;
        m = m * m;
        n >>= 1;
    }
    return result;
}


int main() {
    cout<<pow(2.2,10)<<endl;
    cout<<fast_pow(2.2, 10);
    return 0;
}