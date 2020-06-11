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
+ 找到重复(Find the recurrence)
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
+ eg：

![poj2663](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/dynamic_programming/poj2663.png)