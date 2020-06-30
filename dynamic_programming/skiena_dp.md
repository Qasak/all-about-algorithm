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





## 近似字符串匹配

## 最长上升序列

## 战争故事：龙虾的进化

## 划分问题

## 解析上下文无关(Context-Free)语法

## 带限制的DP：TSP

## 战争故事：What's Past is Prolog

## 战争故事：Bar Codes 文本压缩

## 练习

