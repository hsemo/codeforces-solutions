#include <iostream>
#include <vector>

using namespace std;


void handle_test_case(){
  int n,q;
  cin >> n >> q;

  long long a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  vector<int> st;
  vector<int> count(30,0); // to keep a count of each number to only 1
  int t;
  for(int i=0; i<q; i++){
    cin >> t;
    t--;
    if(count.at(t) == 0){
      st.push_back(++t);
      count.at(t) = 1;
    }
  }

  int mx;
  for(int i=0; i<n; i++){
    mx = 31; // because if a number is divisable by 2^x then after the modification it wouldn't be devisable by 2^x and also numbers > 2^x
    for(int j=0; j<st.size(); j++){
      if(st.at(j) < mx && a[i] % (1 << st.at(j)) == 0){
        a[i] += 1 << (st.at(j) - 1);
        mx = st.at(j);
      }
    }
  }

  for(int i=0; i < n-1; i++){
    cout << a[i] << ' ';
  }
  cout << a[n-1] << "\n";

}

int main(){
  int t;
  cin >> t;
  while(t--)
    handle_test_case();

  return 0;
}
