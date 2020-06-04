# All-about-Stanford-CS-97SI
 all solutions of CS-97-SI problems

## 数据结构

### 堆

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

