# Dynamic Programming

## What is DP

+ 维基百科定义：“通过将复杂问题分解为更简单的子问题来解决复杂问题的方法”
+ 一旦我们看到一些例子，这个定义就会有意义

## Steps for Solving DP Problems

1. 定义子问题
2. 写下与子问题相关的重复(recurrence)
3. 识别并解决基础case

## 1-dimensional DP

+ Problem：给定n，找到用1，3，4的和表示n的方法数
+ Example: n=5,答案是6

```
5	=	1+1+1+1+1
	=	1+1+3
	=	1+3+1
	=	3+1+1
	=	1+4
	=	4+1
```

+ 定义子问题
  + 定义Dn是将n写作1，3，4的方法数
+ 递推关系(Find the recurrence)
  + 考虑一个可行解$n=x_1+x_2+...+x_m$
  + 如果$x_m=1$,剩余部分和一定为$n-1$
  + 因此，以$x_m=1$结尾的和的方法数等于$D_n-1$
  + 考虑其他cases($x_m=3,x_m=4$)
+ Recurrence is then

$$
D_n=D_{n-1}+D_{n-3}+D_{n-4}
$$

+ 解决基础cases（Solve the base cases）
  + $D_0=1$
  + $D_n=0$对于所有的负数$n$
  + 换句话说，can set:$D_0=D_1=D_2=1$以及$D_3=2$

### 实现

```c++
D[0]=D[1]=D[2]=1;D[3]=2;
for(int i=4;i<=n;i++) 
    D[i]=D[i-1]+D[i-3]+D[i-4];
```

+ 扩展：当$n\approx10^{12}$($2^{10}\approx10^3,10^{12}=(10^{3})^{4}\approx(2^{10})^4=2^{40}$)
  + 重复调用[斐波那契数的矩阵形式](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/README.md)

### POJ2663:

+ 砖块1*2大小，给定n，找到铺满3xn的板子的方法数
+ eg：n=12时的一个可行解

![poj2663](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/dynamic_programming/poj2663.png)

$D_n=0 \ if\ n\ is\ odd $

结尾处必须形如

![poj2663](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/dynamic_programming/end.png)

头两种情况是等价的

第三种：方法数=$D_{n-2}$

第一/二种：

+ 空白处可以填两个横向或一个竖向
  + 两个横向：方法数=$D_{n-4}+D_{n-6}...+D_0$
  + 一个竖向：方法数=$D_{n-2}$



+ 定义子问题
  + 定义Dn是填满3xn板子的方法数
+ 递推关系
  + $D_n=D_{n-2}+2*(D_{n-2}+D_{n-4}+D_{n-6}...+D_0)$

```c++
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

ll D[31];


ll sum(ll D[], int n) {
    ll sum=0;
    if(n<0) return 0;
    for(int i=0;i<=n;i+=2) {
        sum+=D[i];
    }
    return sum;

}
ll func(int n) {
    if(n&1) return 0;
    D[0]=1;
    for(int i=2;i<=n;i++) {
        D[i]=3*D[i-2]+2*(sum(D,i-4));
    }
    
    return D[n];
}

int main() {
    int n;
    while(1) {
        memset(D,0,sizeof(D));
        cin>>n;
        if(n==-1) break;
        cout<<func(n)<<endl;
    }
        
    return 0;
}
```



## 2-dimensional DP Example

+ 问题：给定两个string,x和y，找到最长公共子序列(LCS)并打印出长度
+ eg：
  + x A **B** **C** B D **A B**
  + y:**B** D **C A B** C
  + "BCAB"是最长公共子序列，答案4

+ 定义子问题
  + 令$D_{ij}$为字符串$x_{1...i},y_{1...j}$的LCS的长度

```c++
#include<bits/stdc++.h>
using namespace std;
int const MAXN=129;
int dp[MAXN][MAXN];

int max(int a, int b) {
    if(a>b) {
        return a;
    } else {
        return b;
    }
}

int func(string& a,string& b) {
    for(int i=1;i<=a.size();i++) {
        for(int j=1;j<=b.size();j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    return dp[a.size()][b.size()];
}
int main() {
    string a,b;
    cin>>a>>b;
    cout<<func(a,b)<<endl;
    return 0;
}
```

## 区间DP

+ 问题：给定字符串$x=x_{1...n}$,找到使其成为回文串的最小需要插入字符个数
+ eg：x="Ab3bd"
+ "dAb3bAd"or"Adb3bdA":插入两个字符（一个'd',一个'A'）
  + "Ab3bd"->"Ab3bdA"->"Adb3bdA"
  + "Ab3bd"->"dAb3bd"->"dAb3bAd"



+ 定义子问题

  + 令$D_{ij}$为使$x_{i...j}$成为回文串的最小需要插入字符个数

+ 递推关系

  + 考虑一个包含$x_{i...j}$的最短回文串$y_{1...k}$(why?)
  + Either $y_1=x_i\ or\ y_k=x_j$
    + "abc"->"a bc a"->"ac b ca"
    + "leetcode"->"l eetcode l"->"le etcode el"->"leet cod teel"->"leetc od cteel"     - >        "leetc odo cteel"
    + "leetcode"->"e leetcod e"->"ed leetco de"->"edo leetc ode"->"edoc leet code"->"edoct lee tcode"->"edocte le etcode"->"edoctee l eetcode"
  + 最后一个case是$y_1=y_k=x_i=x_j$

+ $$
  D_{ij}=
  \left\{
  \begin{matrix} 
  1+min\{D_{i+1,j},D_{i,j-1}\}  &x_i\neq x_j\\
  D_{i+1,j-1} & x = x_j 
  \end{matrix}
  \right.
  $$

+ 解决基本case:$D_{ii}=D_{i,i-1}=0$,对于所有的$i$

```c++
#include<bits/stdc++.h>
using namespace std;
const int MAXN=129;
int D[MAXN][MAXN];

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

int dp_palindrome(string a) {
    int n=a.size();
    for(int t=1;t<n;t++) {
        for(int i=0,j=t;j<n;i++,j++) {
            if(a[i]==a[j]) D[i][j]=D[i+1][j-1];
            else D[i][j]=1+min(D[i+1][j],D[i][j-1]);
        }
    }
    return D[0][n-1];
}
int main() {
    string a;
    while(cin>>a){
        cout<<dp_palindrome(a)<<endl;
    }
}
```











