## 2663 拼瓷砖

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





## 1163数字三角

```
				7
			  3   8
			8   1   0
		  2   7   4   4
		4   5   2   6   5
```

+ 描述：数字三角形。编写一个程序，计算从顶部开始到底部某处的某条路线上经过的数字的最大和。每一步都可以向左斜下或向右斜下。

+ 输入：第一行包含一个整数N：三角形的行数。

  下面的N行描述了三角形的数据。

  三角形中的行数大于1但小于等于100。三角形中的所有整数都在0到99之间。

+ 输出：最大的和

+ 样例：Sample Input

  ```
  5
  7
  3 8
  8 1 0 
  2 7 4 4
  4 5 2 6 5
  ```

  Sample Output

  ```
  30
  ```



```c++
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN=1<<13;
int a[MAXN];
int sum[MAXN];

int max(int a, int b) {
    if(a<b) {
        return b;
    }
    else{
        return a;
    }
}

int dfs(int l, int idx, int n) {
    if(l>n) return 0;
    if(sum[idx]!=0) return sum[idx];
    return sum[idx]=a[idx]+max(dfs(l+1,idx+l,n),dfs(l+1,idx+l+1,n));
}
int main()                                
{
    // freopen("in_1163.txt","r",stdin);
    memset(sum,0,sizeof(sum));
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++){
            cin>>a[i*(i-1)/2+j];
        }
    }
    int mx;
    mx=dfs(1,0,n);
    cout<<mx<<endl;
    return 0;
}

```





## 1160 邮局

+ 描述：有一条笔直的公路，公路旁有村庄。公路以整数轴表示，每个村庄的位置用一个整数坐标表示。同一位置仅一个村。两个位置之间的距离是其整数坐标差的绝对值。

  邮局将建在一些村庄(不一定是所有的)。一个村子和里面的邮局有着同样的位置。在建设邮局时，应选择其位置，使每个村庄与其最近的邮局之间的所有距离之和最小。

  你要写一个程序，根据村庄的位置和邮局的数量，计算每个村庄与其最近的邮局之间所有距离的最小可能总和。

+ 输入：第一行包含两个整数：村庄数V，1<=V<=300；邮局数P，1<=P<=30，P<=V；

  第二行是按递增顺序包含V整数。这些V整数是村庄的位置。对于每个位置X，它保持1<=X<=10000。

+ 输出：第一行包含一个整数S，即每个村庄与其最近的邮局之间的所有距离之和。

+ 样例：

+ ```
  Input:
  10 5
  1 2 3 6 7 9 11 22 44 50
  Output:
  9
  
  
  analysis:
  1 2 3 6 7 9 11 22 44 50
    ↑       ↑    ↑  ↑  ↑
      
  1+1+3+2+2=9
  ```





## 2033



## 1159



## 1050



## 2127





## 1655





## 2292





## 2430



## 2066



## 1038

















