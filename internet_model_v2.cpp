#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>
#include <fstream>

typedef unsigned long long ULL;
using namespace std;

void gen_placement_rep_by_num(vector<int> &cur, ULL num, int n, int k) {
  //cur.assign(n,0);
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
    vector<int> raz(n);
    vector<int> rez(n);
    raz.assign(n,0);
    rez.assign(n,0);

    for(int i = 0; i < n; i++ ){
        ma[i] = 1;
    }

    ULL num = get_num_by_placement_rep(ma, n, 2);
    cout<<num<<endl;



    for(int i = 0; i <= num; i++){
        gen_placement_rep_by_num(rez,i,n,2);
        for(int k = 0; k < rez.size(); k++){
            cout<<rez[k]<<" ";
        }
        cout<<endl;
        int mark = 0;
        int ferst_one =find(rez.begin(), rez.end(), 1)-rez.begin();
        for(int l = rez.size()-1; l > ferst_one; l--){
            if(rez[l]==0){
                mark=1;
            }
        }
        if(mark==1){
            mark = 0;
            for(int j = 0; j < rez.size(); j++){
                if((j<=ferst_one)||(rez[j]!=0)){
                    cout<<rez[j]<<" ";
                }
                else{
                    cout<<(rez.size()-j)+1<<" ";
                }

            }
            cout<<endl;
        }


    }


   // for(int i = 0; i < = )
    /*
    gen_placement_rep_by_num(rez,num,n,n);
    fstream f;
    f.open("razmetka.txt", ios::out);
    for(int i = 0; i<=num;){

        int mark = 0;
        gen_placement_rep_by_num(rez,i,n,n);
        for(int k = 0; k < rez.size(); k++)
        {
            if(rez[k]!=0){
                mark = 1;
            }
            if(mark==1){
                raz[k]=rez[k];
            }
           // cout<<rez[k]<<" ";
        }
        int mark2 = 0;
        for(int j = 0; j < raz.size(); j++){
                if(raz[j]!=0){
                    mark2=1;
                }
                if(mark2==1){
                    f<<raz[j]<<' ';
                }
        }
        mark2=0;
        f<<endl;
       // cout<<endl;
        i++;
    }
    */
    return 0;
}
