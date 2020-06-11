# Mathematics

> github README.md存在显示格式问题，可能需要在[typora](https://typora.io/)中打开

## 幂和

平方和与立方和

$$
\begin{align*}
&\sum^n_{k=1}k^2=\frac{1}{6}n(n+1)(2n+1) \\

&\sum k^3=(\sum k)^{2}=\left((\frac{1}{2}n(n+1))\right)^2
\end{align*}
$$

简易证明：

> Proofs without Words: Exercises in Visual Thinking

<img src="https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/sum_of_squares.jpg" style="zoom:50%" />

<img src="https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/proof_sos1.png" style="zoom:10%" />

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/proof_sos2.png)

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/proof_sos3.png)

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/mathematics/proof_sos4.png)

$\sum k=\frac{n(n+1)}{2}$

$\frac{\sum k^2}{\sum k}=\frac{2n+1}{3}$

$\sum k^2=\frac{1}{6}(n)(n+1)(2n+1)$

## 快速幂

递归计算$a^n$:
$$
a^n=

\left\{
\begin{matrix}
1 &&&& n=0\\
a &&&& n=1\\
(a^{\frac{n}{2}})^2 &&&& n\ is\ even\\
a(a^{\frac{n-1}{2}})^2 &&&& n\ is\ odd \\
\end{matrix}
\right.
$$
实现

```c++
double pow(double a, int n) {
	if(n==0) return 1;
	if(n==1) return a;
    double t=pow(a,n/2);
    return t*t*(n&1?a:1);
}
```

+ 运行时间：$O(log n)$
+ 





## 斐波那契序列

+ 定义
  + $F_0=0,F_1=1$
  + $F_n=F_{n-1}+F_{n-2},n\ge2$

### 封闭形式

+ $$
  F_n=(1/\sqrt5)(\phi^n-\bar{\phi}^n)\\ \phi=(1+\sqrt5)/2\\ \bar{\phi}=(1+\sqrt5)/2\\
  $$

  

+ 不好：因为$\phi$和$\sqrt5$是无理数

+ 对于很大的$n$,不能计算$F_n$的准确值

+ 这里给一个更稳定的方法计算$F_n$

  + ...以及别的相似的递推形式(and any other recurrence of a similar form)

### 更好的“封闭”形式

$$
\left[
\begin{matrix}
F_{n+1} \\ F_n
\end{matrix}
\right] 

=

\left[
\begin{matrix}
1&1\\
1&0
\end{matrix}
\right]

\left[
\begin{matrix}
F_{n} \\ F_{n-1}
\end{matrix}
\right] 

=
\left[
\begin{matrix}
1&1\\
1&0
\end{matrix}
\right]^{n}

\left[
\begin{matrix}
F_{1} \\ F_{0}
\end{matrix}
\right] 



\tag{1}
$$

+ 用快速幂计算矩阵幂
+ 可扩展以支持具有常数系数的任何线性递推

```c++
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
```

