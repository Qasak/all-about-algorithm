#include<bits/stdc++.h>
using namespace std;

struct Matrix {
    int a0;
    int a1;
    int b0;
    int b1;
    Matrix(int a0=1,int a1=1, int b0=1,int b1=0): a0(a0),a1(a1),b0(b0),b1(b1) { }
    Matrix operator*(const Matrix & op2) {
        return Matrix(a0*op2.a0+a1*op2.b0, a0*op2.a1+a1*op2.b1, 
        b0*op2.a0+b1*op2.b0,b0*op2.a1+b1*op2.b1);
    }
};

Matrix fast_pow(Matrix & a, int n) {
    if(n==0) return Matrix(1,0,0,1);
    if(n==1) return a;
    Matrix t=fast_pow(a,n/2);
    return t*t*(n%2?a:Matrix(1,0,0,1));
}

int main() {
    Matrix m1;
    Matrix m2;
    m2=fast_pow(m1,1<<5);
    printf("%d %d\n%d %d",m2.a0,m2.a1,m2.b0,m2.b1);
}