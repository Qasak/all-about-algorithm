#include <bits/stdc++.h>
using namespace std;

auto eratosthenes(int upperbound) {
  vector<bool> flag(upperbound + 1, true);
  flag[0] = flag[1] = false; //exclude 0 and 1
  for (int i = 2; i <= sqrt(upperbound); ++i) {
    if (flag[i]) {
      for (int j = i * i; j <= upperbound; j += i)
        flag[j] = false;
    }
  }	
  return flag;
}
int main(){
    int n=100;
    vector<bool> ans;
    ans=eratosthenes(n);
    for(int i=0;i<ans.size();i++) {
        if(ans[i]) 
            cout<<i<<endl;
    }
    return 0;
}