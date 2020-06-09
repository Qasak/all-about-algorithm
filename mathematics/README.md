# Mathematics

## 快速幂

### 幂和

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
