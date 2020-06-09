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
  + 如果xm=1,剩余部分和一定为$n-1$
  + 因此，以xm=1结尾的和等于$D_n-1$
  + 

