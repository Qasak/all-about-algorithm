#include<bits/stdc++.h>
using namespace std;

vector<int> bit(1<<10);
int n;

int sum(int i) {
	int s=0;
	while(i>0) {
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}

void add(int i, int x) {
	while(i<=n) {
		bit[i]+=x;
		i+=i&-i;
	}
}

int main()                                
{
    vector<int> arr_in={9,1,-8,1,2,4,7,9,6,4};
	n=10;
	for(int i=0; i<n;i++) {
		add(i+1, arr_in[i]);
	}
	cout<<sum(5)-sum(2);
    return 0;                         
}   