# All-about-Stanford-CS-97SI

 all solutions of CS-97-SI problems

## 数据结构

### 堆

#### 插入节点

节点编号从1开始![figure](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/heap1.png)

```c++
void InsertNode(int v) {
    H[++n] = v;
    for(int k = n; k > 1; k /=2) {
        if(H[k] > H[k / 2])
            swap(H, k, k / 2);
        else
            break;
    }
}

void swap(int a[], int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
}
```

#### 删除节点

1. Remove the root, and bring the last node (rightmost node in the last level) to the root 
2. If the root breaks the heap property, look at its children and swap it with the larger one – Swapping can introduce another conﬂict 
3. Repeat 2 until all conﬂicts are resolved

```c++
void DeleteNode() {
        int r = H[n--];
        H[1] = r;
        int idx;
        for(int k = 1; k < n / 2 + 1; ) {
                if(H[k] < H[k * 2] || H[k] < H[k * 2 + 1]) {
                        if(H[k * 2] > H[k * 2 + 1]) {
                                idx = k * 2;

                        } else {
                                idx = k * 2 + 1;
                        }
                        swap(H, idx, k);
                        k = idx;
                } else {
                        break;
                }
        }
}
```



### 并查集

```c++
int Find(int x) {
    while(x != L[x]) x=L[x];
    return x;
}

//递归写法
int Find(int x) {
    if(x != L[x]) x = Find(L[x]);
    return x;
}

void Union(int x, int y) {
    L[Find(x)] = Find(y);
}
```

### 路径压缩

+ 在坏的情况下，树变得很深
+ 路径压缩在每次`Find()`被调用时，使树变浅
+ 在根不变的情况下，我们不关心树长什么样
  + 每次`Find(x)`返回根后，回溯到x，重新路由所有的链接到根

```c++
int Find(int x) {
    if(x == L[x]) return x;
    int root = Find(L[x]);
    L[x] = root;
    return root;
}

int Find(int x) {
    return x == L[x] ? x : L[x] = Find(L[x]);
}
```



### 二叉搜索树（BST）

二叉搜索树有如下性质：对每个节点v

+ v>=v的左子树
+ v<=v的右子树

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/BST1.png)

#### BST能做什么

支持三种操作

+ Insert(x)插入一个值为x的节点
+ Delete(x)删除一个值为x的节点，如果存在的话
+ Find(x)返回一个值为x的节点，如果存在的话

很多扩展

+ Count(x)计数小于等于x值的节点个数
+ GetNext(x)返回最小的满足value>=x的节点

简单实现不能保证效率

+ 最坏情况，树的高度变成n
+ 保证O(log n )每次操作，需要树的平衡(难以实现)
+ 跳过实现细节

使用标准库的实现

+ set,map(C++)
+ TreeSet,TreeMap(Java)

### Fenwick Tree

是线段树的一种变形

支持非常有用的区间运算(interval operations)

+ Set(k, x):设置第k个元素值为x
+ Sum(k):计算1，。。。，k元素的和(前缀和)
  + note：i,...j的和=Sum(j)-Sum(i-1)
+ 两种操作都能在O(log n)时间完成，使用O(n)空间

### Fenwick Tree结构

至少有n个节点的完全二叉树

+ 例子中n=8
+ 第k个叶子节点保存了元素k的值
+ 每个区间保存儿子的值的和
  + e.g.,红色节点保存item[5]+item[6]

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/FenwickTree1.png)

### 对连续值求和

主要思想：选择求和得到所需值的最小节点集

我们观察到：

+ 每层最多选择1个节点，这样我们看到的节点总数为log2 n
+ 可以在O(logn)时间内完成

eg：

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/FenwickTree2.png)

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/FenwickTree3.png)

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/FenwickTree4.png)

![img](https://github.com/Qasak/all-about-stanford-cs-97si/blob/master/data_structure/FenwickTree5.png)



### 计算前前缀和

+ 也就是计算Sum(k)

+ 维护指针P，初始值向叶子节点k
+ 用以下过程爬树
  + 如果P是指向某节点的左儿子
    + 加上P的值
    + 让P指向P的左邻居的父节点
    + 如果P没有左邻居，终止
  + 否则
    + P指向P的父节点

### 更新值

+ 也就是Set(k,x) (设置叶子k的值为x)
+ 这部分更简单
+ 仅改变叶子k及其祖先

1. 从叶子k开始，改变它的值为x
2. 去到它的父亲，重新计算值
3. 重复2，直到根节点

### 扩展

+ 使Sum()函数在任意区间工作
  + 不仅是从 item 1开始
+ 用新的Sum()函数支持更多操作
  + Min(i,  j)区间i,...,j的最小值
  + Max(i,  j)区间i,...,j的最大值



### 线段树实现

```c++
#include<bits/stdc++.h>
#include<stdio.h>
int const MAXN = 1<<17;
int n, dat[2*MAXN - 1];

void init(int n_) {
    n=1;
    while(n<n_) n=n*2;
    for(int i=0;i<2*MAXN -1;i++) dat[i]=0;
}
void Set(int k, int a) {
    k += n-1;
    dat[k]=a;
    while(k>0) {
        k=(k-1)/2;
        dat[k] = dat[k*2+1]+dat[k*2+2];
    }
}

int Sum(int k, int sum=0) {
    if(k==0) return sum;
    else {
        if(k%2) {sum=dat[k]+Sum((k-2)/2,sum);}
        else sum+=Sum((k-1)/2,sum);
    }
    return sum;
}


int main()                                
{
    int k=10;
    int L[k]={9,1,-8,1,2,4,7,9,6,4};
    init(k);
    for(int i=0; i<k;i++) {
        Set(i,L[i]);
    }
    for(int i=0; i<2*n-1;i++) {
        printf("%d ", dat[i]);
    }
    printf("\n%d", Sum(3+n-2));
    return 0;                         
}     
```

### BIT实现

```

```







## 最低公共祖先（Lowest Common Ancestor，LCA）



+ 输入：一棵有根树和一堆节点对
+ 输出：给定节点对的最低(最深)公共祖先
+ 目标：在O(nlogn)时间预处理树，以便每次LCA查询在O(logn)时间内应答

### 预处理

+ 每个节点保存其深度，以及到每个2^k th祖先的链接( as well as the links to every 2kth ancestor )
  + 每个节点额外O(logn)的存储空间
  + 我们将用Anc\[x\]\[k\]来表示(denote)x的第2^k个祖先
+ 计算Anc\[x\]\[k\]:
  + Anc\[x][0]:x的父亲
  + Anc\[x][k]:Anc[ Anc\[x][k-1] ]\[ k-1 ]

### 应答查询

+ 给定两个节点编号x,y
  + 不失一般性(without loss of generality),假定`depth(x)<=depth(y)`
+ 维护两个指针p,q,初始化指向x和y
+ 如果`depth(p)<depth(q),把q移到和p同一深度`
  + 利用之前计算过的`Anc`
+ 现在我们假定`depth(p)=depth(q)`
+ 如果p和q相同，返回p
+ 否则，初始化k为`⌈log2 n⌉ `并且重复:
  + 如果k是0，返回p的父节点
  + 如果`Anc[p][k]`未定义，或者如果`Anc[p][k]`和`Anc[q][k]`指向同一个节点：
    + k减少1
  + 否则：
    + 置`p=Anc[p][k]` ,`q=Anc[q][k]`让p和q上升2^k层



### 朴素实现

节点上浮

```c++
#include<bits/stdc++.h>
using namespace std;
int const MAX_V = 1<<17;
vector<int> G[MAX_V];

void print_vector(vector<int>& a) {
    for(int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int root;
int parent[MAX_V];//根节点的父节点为-1
int depth[MAX_V];

void dfs(int v, int p, int d) {
    parent[v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++) {
        if(G[v][i]!=p) {
            dfs(G[v][i],v,d+1);
        }
    }
}

int lca(int u, int v) {
    //让u,v走到同一深度
    while(depth[u]>depth[v]) u=parent[u];
    while(depth[u]<depth[v]) v=parent[v];
    while(u!=v) {u=parent[u];v=parent[v];}
    return u;
}

int main() {
    freopen("lca_in.txt","r",stdin);
    int n;
    cin>>n;
    int E=n-1;
    for(int i=0;i<2*E;i++) {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++) {
        printf("Node %d:",i);
        print_vector(G[i]);
    }
    dfs(1,-1,0);
    for(int i=1;i<=n;i++) {
        printf("%d's Parent: %d\n",i, parent[i]);
        printf("%d's Depth: %d",i, depth[i]);
        cout<<endl;
    }
    int u,v;
    cin>>u>>v;
    cout<<lca(u,v);
    return 0;
}

```











