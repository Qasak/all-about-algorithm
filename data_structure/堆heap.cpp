#include <bits/stdc++.h>
using namespace std;

int H[1<<14];
int n=0;

void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void push(int v) {
    H[++n] = v;
    for(int k = n; k > 1; k /=2) {
        if(H[k] > H[k / 2])
            swap(H, k, k / 2);
        else
            break;
    }
}

void pop() {
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

int top() {
	return H[1];
}

int main() {
	push(2);
	push(1);
	cout<<top()<<endl;
	pop();
	cout<<top()<<endl;
	return 0;
}





