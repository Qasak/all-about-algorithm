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

