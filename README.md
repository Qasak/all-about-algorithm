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



