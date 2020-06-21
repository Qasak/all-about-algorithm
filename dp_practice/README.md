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
  
  ```

+ 当只选一个点做邮局时，中点(V/2)与其余点距离和一定最小
+ 如果要建P个，假设k个村子已经建了P-1个，在k~n之间建一个就行，这一个正建在中点
+ 定义$w(i,j)$为村子$[i,j]$之间放一个邮局的最短距离和
+ 定义$dp[i][j]$为前$i$个村子放$j$个邮局的最短距离和
+ 递推：$dp[i][j]=\min(dp[k][j-1]+w(k+1,i),dp[i][j]),k \in [j,i]$

```c++
#include <cstring>
#include <iostream>
using namespace std;

int vill[301];
int dp[301][31];
int w[301][301];


int abs(int a) {
    if(a<0) return -a;
    else return a;
}

int mid_sum(int a[], int l, int r) {
    int sum=0;
    int mid=l+(r-l)/2;
    for (int i = l; i <= r; i++)
    {
        int abs_dist=abs(a[i]-a[mid]);
        sum+=abs_dist;
    }
    return sum;
}

void input_vill(int V) {
    for (int i = 1; i <= V; i++)
    {
        cin>>vill[i];    
    }
}

int min(int a, int b) {
    if(a<b)
    return a;
    else
    return b;
}


void init_w(int V) {
    for (int i = 1; i <= V; i++)
    {
        for (int j = i; j <= V; j++)
        {
            w[i][j]=mid_sum(vill,i,j);
        }
    }
}

int run(int V, int P) {
    for (int i = 1; i<=V; i++)
    {
        for (int j = 1; j <= P && j <= i; j++)
        {
            for (int k = j-1; k <=i; k++)
            {
                dp[i][j]=min(dp[k][j-1]+w[k+1][i],dp[i][j]);
            }
        }
    }
    return dp[V][P];
}

int main() {
    int V,P;
    while(cin>>V>>P) {
        memset(dp,0x3f,sizeof(dp));
        memset(vill,0,sizeof(vill));
        memset(w,0,sizeof(w));
        input_vill(V); 
        dp[0][0]=0;
        init_w(V);
        cout<<run(V,P);
    }
    return 0;
}

```





## 2033Alphacode

+ 描述：爱丽丝和鲍勃需要互相发送秘密消息，并正在讨论如何对他们的消息进行编码：

  爱丽丝：“让我们使用一个非常简单的代码：我们将把代码单词'A'用1表示，'B'用2表示，'Z'用26表示”

  鲍勃：“这是个愚蠢的密码，爱丽丝。假设我把编码为25114的“BEAN”这个词发给你。你可以用很多不同的方法来解码它！”

  爱丽丝：“当然可以，但是你会得到什么单词？除了“BEAN”，你会得到“BEAAD”，“YAAD”，“YAN”，“YKD”，“BEKD”。我想你能解码出正确的单词。你为什么要给我发“BEAN”这个词？”

  鲍勃：“好吧，也许这是个糟糕的例子，但我敢打赌，如果你有一个长度为500的字符串，将有非常多不同的解码方式，有这么多，你会发现至少两个不同的，将是有意义的。”

  爱丽丝：“有多少种不同的解码方式？”

  鲍勃：“Jillions！”

+ 输入：输入将由多个输入集组成。每组由一行数字组成，表示合法的加密（例如，没有一行以0开头）。数字之间不会有空格。“0”的输入行将终止输入，不应进行处理

+ 输出：对于每个输入集，输出输入字符串可能的编码数。所有答案都在一个long 变量的范围内。

+ 样例：

  ```
  Input:
  25114
  1111111111
  3333333333
  0
  
  Output:
  6
  89
  1
  
  
  1		//1
  11		//2
  111		//3
  1111	//5
  11111	//8
  
  1111111111	//89
  Fibonacci：1 1 2 3 5 8 13 21 34 55 89
  
  
  seg:
  1	+1
  2	+3
  3	+6
  4	+
  ```

  写拼凑式的程序一般都没法一次性写对

+ 

```c++
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
```

解法二：

```c++
// AlphaCode problem
// ECNA ACM Regional 2004
// t feil

#include <iostream>
using namespace std;

void printit(char c){
   cout<<c<<endl;
}

int main(){
  char c,c1,c2;
  int last, last1, last2;

  cin>>c1;
  while(c1!='0'){
    last=1; 
    if(cin.peek() != '\n'){
      cin>>c2; 
      last2=1;
      if((c1=='1' || (c1=='2' && c2<'7')) && c2!='0') last=last1=2;
      else last=last1=1;
      while(cin.peek() != '\n'){
        cin>>c;
        if(c!='0') last=last1; else last=0;
        if(c2=='1' || (c2=='2' && c<'7'))
          last += last2;
        c2=c; last2=last1; last1=last;
      }
    }
    cout<<last<<endl;
    cin>>c1;
  }
return 0;
}
```





## 1159Palindrome

令$D_{ij}$为使$x_{i...j}$成为回文串的最小需要插入字符个数
$$
D_{ij}=
\left\{
\begin{matrix} 
1+min\{D_{i+1,j},D_{i,j-1}\}  &x_i\neq x_j\\
D_{i+1,j-1} & x = x_j 
\end{matrix}
\right.
$$


```c++
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5120;
int D[MAXN][MAXN];

int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

int dp_palindrome(string a, int n) {
    for(int t=1;t<n;t++) {
        for(int i=0,j=t;j<n;i++,j++) {
            if(a[i]==a[j]) D[i][j]=D[i+1][j-1];
            else D[i][j]=1+min(D[i+1][j],D[i][j-1]);
        }
    }
    return D[0][n-1];
}
int main() {
    int n;
    cin>>n;
    string a;
    while(cin>>a){
        cout<<dp_palindrome(a, n)<<endl;
    }
}
```

解法二：

+ 反转$x$得到$x^R$
+ 答案是$n-L$,L是$x,x^R$的LCS的长度
+ why？
  + “leetcode" "edocteel"反转后直接加在后面一定回文，此时相当于插入n个字符
  + "leetcodocteel" n-LCS=最短回文串需要插入的字符个数

## 1050 To the Max

+ 描述：给定由正整数和负整数组成的二维数组，子矩形是指位于整个数组中的大小为1×1或更大的任何相邻子数组。矩形的和是该矩形中所有元素的和。在这个问题中，总和最大的子矩形称为最大子矩形。

  例如，数组的最大子矩形：

+ ```
  0 -2 -7 0
  9 2 -6 2
  -4 1 -4 1
  -1 8 0 -2
  
  9 2
  -4 1
  -1 8
  and has a sum of 15.
  
  ```

+ 输入输出样例

  输入由N*N个整数数组组成。输入从一行上的单个正整数N开始，表示二维正方形数组的大小。后面是N^2个整数，用空格（空格和换行符）分隔。这些是数组的N^2个整数，按行主顺序显示。也就是说，第一行中的所有数字，从左到右，然后第二行中的所有数字，从左到右，等等。N最大100。数组中的数字将在[-127，127]范围内。

  输出最大子矩形的和。

  ```
  
  Sample Input
  4
  0 -2 -7 0 9 2 -6 2
  -4 1 -4  1 -1
  
  8  0 -2
  Sample Output
  
  15
  ```

  

## 2127





## 1655





## 2292





## 2430



## 2066



## 1038

















