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
+ 第k个节点保存了元素k的值
+ 每个区间















