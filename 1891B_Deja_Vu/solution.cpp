#include <iostream>
#include <vector>

using namespace std;

void handle_test_case(){
  int n,q;
  cin >> n >> q;

  int a[n], x[q];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  int xi2;
  for(int i=0; i<q; i++){
    cin >> x[i];
    xi2 = 1 << x[i];
    for(int j=0; j<n; j++){
      if(a[j] % xi2 == 0)
        a[j] += 1 << (x[i] - 1);
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
