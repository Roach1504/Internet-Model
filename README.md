#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

typedef unsigned long long ULL;
using namespace std;
vector<int> rez;
void gen_placement_rep_by_num(vector<int> &cur, ULL num, int n, int k) {
  cur.assign(n,0);
  int pos = n-1;
  while (num) {
    cur[pos--] = num % k;
    num /= k;
  }
}

ULL get_num_by_placement_rep(const vector<int> &cur, int n, int k) {
  ULL num = 0;
  ULL step = 1;
  for (int i=cur.size()-1;i>=0;--i) {
    num += cur[i] * step;
    step *= k;
  }
  return num;
}

int main () {
    ULL n = 4;
    vector<int> ma(n);
    for(int i = 0; i < n; i++ ){
        ma[i] = i;
    }
    ULL num = get_num_by_placement_rep(ma, n, n);
    cout<<num<<endl;
    for(int i = 0; i<=num;){
        gen_placement_rep_by_num(rez,i,n,n);
        for(int k = 0; k < rez.size(); k++)
        {
            cout<<rez[k]<<" ";
        }
        cout<<endl;
        i++;
    }
    return 0;
}
