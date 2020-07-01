## 缓存vs计算

### 递归的Fibonacci

```c
long fib_r(int n)
{
    if (n == 0) return(0);
    if (n == 1) return(1);
    return(fib_r(n-1) + fib_r(n-2));
}
```



### 缓存的Fibonacci

```c
#define MAXN 45 /* largest interesting n */
#define UNKNOWN -1 /* contents denote an empty cell */
long f[MAXN+1]; /* array for caching computed fib values */
long fib_c(int n)
{
    if (f[n] == UNKNOWN)
    f[n] = fib_c(n-1) + fib_c(n-2);
    return(f[n]);
}
long fib_c_driver(int n)
{
    int i; /* counter */
    f[0] = 0;
    f[1] = 1;
    for (i=2; i<=n; i++) f[i] = UNKNOWN;
    return(fib_c(n));
}

```

### 动态规划的Fibonacci

```c
long fib_dp(int n)
{
    int i; /* counter */
    long f[MAXN+1]; /* array to cache computed fib values */
    f[0] = 0;
    f[1] = 1;
    for (i=2; i<=n; i++) f[i] = f[i-1]+f[i-2];
    return(f[n]);
}
```

### 最终优化版

```c
long fib_ultimate(int n)
{
    int i; /* counter */
    long back2=0, back1=1; /* last two values of f[n] */
    long next; /* placeholder for sum */
    if (n == 0) return (0);
    for (i=2; i<n; i++) {
        next = back1+back2;
        back2 = back1;
        back1 = next;
    }
    return(back1+back2);
}
```

### 二项式系数

$\C_n^k=\frac{n!}{(n-k)!k!}$

用阶乘算容易溢出，更好的办法是利用隐藏在Pascal三角中的递推关系(recurrence relation)

```c
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
  1 5 10 10 5 1
```

$\C_n^k=\C_{n-1}^{k-1}+\C_{n-1}^k$

考虑第n个元素是否出现在n中取k个元素集合的子集中（这种集合有$\C_n^k$个）

如果在，我们可以通过从其他n-1中选择k-1其他项来完成子集（$\C_{n-1}^{k-1}$）

如果不在，我们必须从剩余的n-1中选择所有k个（$\C_{n-1}^k$）

递推离不开基础问题，加号左边一直往下，有$\C_{n-k}^0=1$

另外，$\C_{m}^1=m$

以上两种情况都可以作为基础情形

加号右边的项可提升到$\C_{k}^k=1$

下面是求值时的正确次序，已初始化的单元标记为A-K

![image-20200630110626968](C:\Users\qasak\AppData\Roaming\Typora\typora-user-images\Evaluation order for binomial coefficient.png)

```c
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
```



## 近似字符串匹配

> [How to Write a Spelling Corrector](https://norvig.com/spell-correct.html)

需要定义一个费用函数告诉我们两个字符串之间离得多远:

一个合理的距离度量要反映一个字符串转为另一个字符串所必须的*变动次数*

+ 替换
+ 插入
+ 删除

### 用递归计算编辑距离









## 最长上升子序列

最大上升串节(run)：元素必须物理上相邻

```c++
int main() {
    int s[9]={2, 4, 5,5,1, 2, 6, 9, 18};
    int l=0; // current left
    int r=0; // current right
    int ll=0;// longest left
    int rr=0;// longest right
    int n=9;
    for (int i = 1; i < n; i++) {
        if(s[i]>s[i-1]) { // 'run' can be extended,right+1
            r=i;
            if(r-l>rr-ll) { // current length > max length, update max length.
                ll=l;
                rr=r;
            }
        } else { // start a new 'run'
            l=r=i;
        }
    }
    cout<<ll<<" "<<rr<<endl;
    return 0;
}
```









## 战争故事：龙虾的进化



## 划分问题



## 解析上下文无关(Context-Free)语法



## 带限制的DP：TSP



## 战争故事：What's Past is Prolog



## 战争故事：条形码 文本压缩



## 练习



