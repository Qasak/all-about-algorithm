#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

struct Matrix {
    ll a0;
    ll a1;
    ll b0;
    ll b1;
    Matrix(ll a0=1,ll a1=1, ll b0=1,ll b1=0): a0(a0),a1(a1),b0(b0),b1(b1) { }
    Matrix operator*(const Matrix & op2) {
        return Matrix(a0*op2.a0+a1*op2.b0, a0*op2.a1+a1*op2.b1, 
        b0*op2.a0+b1*op2.b0,b0*op2.a1+b1*op2.b1);
    }
};

Matrix fast_pow(Matrix & a, ll n) {
    if(n==0) return Matrix(1,0,0,1);
    if(n==1) return a;
    Matrix t=fast_pow(a,n/2);
    return t*t*(n%2?a:Matrix(1,0,0,1));
}


string s;
int main() {//1 2 3 5 8 13 21 34 55 89
    while(cin>>s) {
        if(s=="0")
        break;
        ll cnt=0;
        ll sum=1;
        for (int i = 0; i < s.size(); i++)
        {
            Matrix m1(1,1,1,0);
            Matrix m2(0,0,0,0);
            if('1' <= s[i] && s[i] <= '2' && s[i+1]!='0') {
                cnt++;
                if(i==s.size()-1) {
                    m2=fast_pow(m1, cnt);
                    sum*=m2.a0;
                }
            }
            else {//s[i]=='3'~'9'||s[i+1]=='0'
                if(cnt) {
                    if(s[i+1]=='0') {
                        m2=fast_pow(m1, cnt);
                        sum*=m2.a0;
                    }
                    else {
                        m2=fast_pow(m1, cnt+1);
                        sum*=m2.a0;
                    }
                }
                cnt=0;
            }

        }
        cout<<sum<<endl;
    }
    return 0;
}